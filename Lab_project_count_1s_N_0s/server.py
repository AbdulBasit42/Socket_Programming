import socket

HOST = socket.gethostbyname(socket.gethostname())
PORT = 9999

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.bind(('localhost', PORT))

server.listen()
print(f"SERVER LISTENING ON {HOST}, {PORT}")

while(True):
    client_conn, addr = server.accept()
    print(f"\n[CONNECTED TO CLIENT] : {addr}")

    while True:
        msg = input("\n-> ")
        n = len(msg)
        count = 0
        # check if only 0s and 1s are given in the input
        while count < n:
            l = msg[count]
            if (l!='0' and l!='1'):
                print("!!!Invalid Input...Enter ONLY 0's and 1's : ")
                # repeat
                msg = input("\n-> ")
                n = len(msg)
                count = 0
                continue
            count+=1

        client_conn.send(msg.encode('utf-8'))

        count0, count1 = [int(i) for i in client_conn.recv(2048).decode('utf-8').split('\n')]

        if (count0, count1):
            print("\nclient : ")
            print(f"Count of 0's : {count0}")
            print(f"Count of 1's : {count1}")
        else:
            print(f"\n[CLIENT {addr} DISCONNECTED!]")
            client_conn.close()