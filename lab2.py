# Client

import socket
sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
msg = "Marian"
sock.sendto(str.encode(msg), ("127.0.0.1", 5555))
