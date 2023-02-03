"""
Server receiver buffer is char[256]
If correct, the server will send a message back to you saying "I got your message"
Write your socket client code here in python
Establish a socket connection -> send a short message -> get a message back -> ternimate
use python "input->" function, enter a line of a few letters, such as "abcd"
"""
import socket

HOST = "172.20.10.10"
PORT = 10000

def main():
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        s.connect((HOST, PORT))
        message = input("Please a message you want to send:").encode('utf-8')
        s.sendall(message)
        data = s.recv(1024)

    print("I got your message")


if __name__ == '__main__':
    main()
