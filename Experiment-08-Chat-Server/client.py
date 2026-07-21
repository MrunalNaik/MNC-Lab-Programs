import socket
HOST = "127.0.0.1"
PORT = 12345

#creating client socket
client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

client.connect((HOST,PORT)) #Connect to the server
print(f"Connected to server")

while True:
    messaage = input("Client : ") #Take input from client user
    client.send(messaage.encode()) #Send message to server

    server_reply = client.recv(1024).decode() #Receive reply from server
    print(f"Server :{server_reply}") 

client.close()  #Close the client socket

