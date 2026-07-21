# Experiment 09 - Design a Simple Web Server using Python

## Aim

To design and implement a simple HTTP web server using Python socket programming that serves HTML files to a web browser and returns a **404 Not Found** response for unavailable files.

---

## Theory

A web server is a software application that listens for HTTP requests from clients (web browsers) and responds with the requested web pages or resources.

In this experiment:

- The server listens on port **8080**.
- A web browser sends an HTTP GET request.
- The server extracts the requested filename.
- If the file exists, the server sends an HTTP **200 OK** response along with the HTML content.
- If the file does not exist, the server sends an HTTP **404 Not Found** response.

The experiment uses Python's built-in **socket** module and the **HTTP protocol**.

---

## Algorithm

1. Import the required socket module.
2. Create a TCP socket.
3. Bind the socket to port **8080**.
4. Listen for incoming client connections.
5. Accept a client connection.
6. Receive the HTTP request from the browser.
7. Extract the requested filename.
8. Open and read the requested HTML file.
9. If the file exists:
   - Send an HTTP **200 OK** response.
   - Send the HTML file contents.
10. If the file does not exist:
    - Send an HTTP **404 Not Found** response.
11. Close the client connection.
12. Continue waiting for new requests.

---

## Files

```
Experiment-09-Design-Web-Server/
│── WebServer.py
│── index.html
└── README.md
```

---

## Requirements

- Python 3.x
- Any modern web browser (Chrome, Edge, Firefox)

---

## How to Run

### Start the Server

```bash
python WebServer.py
```

or

```bash
python3 WebServer.py
```

The server starts on:

```
http://localhost:8080
```

---

## Testing

### Existing File

Open:

```
http://localhost:8080/index.html
```

Expected Output:

```
Hello World

Response of requested file
```

---

### File Not Found

Open:

```
http://localhost:8080/test.html
```

Expected Output:

```
404 Not Found

Requested File Does Not Exist
```

---

## Concepts Used

- Socket Programming
- HTTP Protocol
- HTTP GET Request
- HTTP Response
- TCP Communication
- Client-Server Architecture
- File Handling
- Exception Handling

---

## Functions Used

- `socket()`
- `bind()`
- `listen()`
- `accept()`
- `recv()`
- `sendall()`
- `close()`
- `open()`

---

## Result

Successfully designed and implemented a simple HTTP web server using Python. The server handled browser requests, served HTML pages, and returned a **404 Not Found** response when the requested file was unavailable.