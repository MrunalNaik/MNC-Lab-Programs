# Experiment 08 - Chat Server using Socket Programming (Python)

## Aim

To implement a simple client-server chat application using Python socket programming.

---

## Theory

Socket programming is a method of communication between two computers or two processes over a network.

In this experiment:

- The **server** waits for a client to connect.
- The **client** initiates the connection.
- The client sends a message to the server.
- The server receives the message and sends a reply.
- After the communication is complete, both the client and server close the connection.

This experiment uses:

- **TCP (Transmission Control Protocol)** for reliable communication.
- **IPv4** addressing.
- Python's built-in **socket** module.

---

## Algorithm

### Server

1. Import the socket module.
2. Create a TCP socket.
3. Bind the socket to an IP address and port.
4. Listen for incoming connections.
5. Accept a client connection.
6. Receive a message from the client.
7. Display the received message.
8. Send a reply to the client.
9. Close the connection.

### Client

1. Import the socket module.
2. Create a TCP socket.
3. Connect to the server.
4. Enter a message.
5. Send the message to the server.
6. Receive the server's reply.
7. Display the reply.
8. Close the connection.

---

## Files

```
Experiment-08-Chat-Server/
│── server.py
│── client.py
└── README.md
```

---

## How to Run

### Step 1: Start the Server

```bash
python3 server.py
```

Output:

```
Waiting for connection...
```

---

### Step 2: Run the Client (in another terminal)

```bash
python3 client.py
```

---

## Sample Output

### Server

```
Waiting for connection...
Connected by ('127.0.0.1', 54321)
Client: Hello Server
Enter message:
Hello Client
```

### Client

```
Enter message:
Hello Server
Server: Hello Client
```

---

## Concepts Used

- Socket Programming
- TCP Communication
- Client-Server Architecture
- IPv4 Addressing
- Data Transmission using `send()` and `recv()`
- String Encoding and Decoding

---

## Functions Used

### Server

- `socket()`
- `bind()`
- `listen()`
- `accept()`
- `recv()`
- `send()`
- `close()`

### Client

- `socket()`
- `connect()`
- `send()`
- `recv()`
- `close()`

---

## Result

Successfully implemented a client-server chat application using Python sockets. The client and server exchanged messages over a TCP connection and terminated the communication successfully.