import socket

HOST = 'localhost'
PORT = 9999

client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client.connect((HOST, PORT))

def count01(msg):
    count_0 = 0
    count_1 = 0

    for letter in msg:
        if(letter == '0'):
            count_0 += 1
        if(letter == '1'):
            count_1 += 1

    print(f"Count of 0's : {count_0}")
    print(f"Count of 1's : {count_1}")

    client.sendall(str.encode("\n".join([str(count_0), str(count_1)])))

while True:
    msg = client.recv(1024).decode('utf-8')
    
    if msg:
        print(f"\nserver : {msg}")
        count01(msg)
    else:
        print(f"\n[SERVER DISCONNECTED!]")
        client.close()