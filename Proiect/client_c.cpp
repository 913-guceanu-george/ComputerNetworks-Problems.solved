#define _WINSOCK_DEPRECATED_NO_WARNINGS 1

#include <windows.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <string>
#include <locale>
#include <codecvt>

// #pragma comment(lib, "Ws2_32.lib")

char buf[8] = "hello";
int sfd;
struct sockaddr_in soc;
int main()
{
#ifdef _WIN32

    WSADATA wsaData;

    if (WSAStartup(MAKEWORD(2, 2), &wsaData) < 0)
    {

        return -1;
    }

#endif
    sfd = socket(AF_INET, SOCK_DGRAM, 0);

    soc.sin_family = AF_INET;
    soc.sin_port = htons(7777);
    soc.sin_addr.s_addr = inet_addr("192.168.0.174");
    connect(sfd, (const sockaddr *)&soc, sizeof(sockaddr));

    printf("\tWelcome to Never Have I Ever!\n");
    printf("Please answer honestly.\n For every 'I have' answer you 'll be deducted 1p.\n For every ' Maybe ' you' ll be deducted 0.5p.");

    while (true)
    {
        wchar_t question[64];
        recv(sfd, (char *)question, 64, 0);
        if (strstr((char *)question, "null") == NULL)
        {
            printf("Game Over!\n");
            exit(0);
        }
        char answer[64];
        printf("Did you?('I have','I have not', 'Maybe') ");
        scanf("%s", answer);
        sendto(sfd, answer, strlen(answer), 0, (const struct sockaddr *)&soc, sizeof(struct sockaddr_in));
    }

    // sendto(sfd, buf, strlen(buf), 0, (const struct sockaddr *)&soc, sizeof(struct sockaddr_in));
}
