# Experiment 10 - Multithreaded Proxy Server using Python

## Aim

To design and implement a multithreaded HTTP proxy server using Python that receives client requests, forwards them to the destination web server, and returns the server's response to the client.

---

## Theory

A proxy server acts as an intermediary between a client and a web server. Instead of communicating directly with the destination server, the client sends its request to the proxy server. The proxy forwards the request to the original server, receives the response, and sends it back to the client.

In this experiment, multiple clients can connect simultaneously because each client request is handled in a separate thread.

---

## Algorithm

1. Create a TCP socket.
2. Bind the socket to an IP address and port.
3. Listen for incoming client connections.
4. Accept a client connection.
5. Create a new thread to handle the connected client.
6. Receive the HTTP request from the client.
7. Extract the destination host from the request.
8. Connect to the original web server.
9. Forward the HTTP request to the server.
10. Receive the server's response.
11. Send the response back to the client.
12. Close the connection.
13. Continue serving multiple clients.

---

## Files

```
Experiment-10-Multithreaded-Proxy-Server/
│── ProxyServer.py
└── README.md
```

---

## Requirements

- Python 3.x
- Internet Connection
- Web Browser (Chrome, Edge, Firefox)

---

## How to Run

Start the proxy server:

```bash
python ProxyServer.py
```

or

```bash
python3 ProxyServer.py
```

The proxy server starts on:

```
127.0.0.1:8888
```

---

## Working

1. A client sends an HTTP request to the proxy server.
2. The proxy extracts the destination host.
3. The proxy establishes a connection with the original web server.
4. The request is forwarded to the web server.
5. The web server sends the requested data.
6. The proxy forwards the response back to the client.
7. Each client connection is handled in a separate thread.

---

## Concepts Used

- Socket Programming
- TCP Communication
- HTTP Protocol
- Proxy Server
- Multithreading
- Client-Server Architecture
- Thread Management

---

## Python Modules Used

- `socket`
- `threading`

---

## Functions Used

- `socket()`
- `bind()`
- `listen()`
- `accept()`
- `connect()`
- `recv()`
- `send()`
- `sendall()`
- `close()`
- `threading.Thread()`

---

## Advantages

- Handles multiple clients simultaneously.
- Improves server responsiveness.
- Demonstrates multithreaded networking.
- Illustrates the working of an HTTP proxy server.

---

## Result

Successfully implemented a multithreaded HTTP proxy server using Python. The proxy server received client requests, forwarded them to the destination web server, received the responses, and returned them to the client while serving multiple clients concurrently using threads.