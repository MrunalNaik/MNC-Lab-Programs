import socket

HOST = "127.0.0.1"
PORT = 12345

#creating server socket
server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

#Now we tell the socket which IP address and port it should use.
server.bind((HOST, PORT))

server.listen(1)  #This socket is now a server. Start waiting for clients
print(f"Waiting for connection .....")

conn, addr = server.accept()  #Accept a connection from a client
print(f"Connected to {addr}")

while True:
    client_message = conn.recv(1024).decode() #Receive message from client
    if not client_message:
        break
    print(f"Client : {client_message}")

    server_reply = input("Server : ") #Take input from server user
    conn.send(server_reply.encode())

conn.close()  #Close the connection
server.close()  #Close the server socket
