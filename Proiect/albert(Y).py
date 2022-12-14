import socket

IP = "192.168.208.224"
# IP =
PORT = 7777
ADDR = (IP, PORT)
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect(ADDR)


def play():
    # answers = ["i have", "i have not", "maybe"]
    print("\tWelcome to Never Have I Ever!\n" +
          "Please answer honestly.\n For every 'I have' answer you'll be deducted 1p.\n For every 'Maybe' you'll be deducted 0.5p.")
    while True:

        # Getting the question from the server
        question = s.recv(64).decode("utf-8")

        if question == 'null':
            print("Game over")
            exit(0)
        print(question)

        # Getting the client input and sending to serve
        answer = input("Did you?('I have','I have not', 'Maybe') ")
        s.send(answer.encode("utf-8"))
        points = s.recv(64).decode("utf-8")
        if (float(points) <= 0):
            msg = s.recv(64).decode("utf-8")
            print(msg)
            exit(0)
        print(f"Current points: {points}\n")


if __name__ == "__main__":
    play()
