from socket import *
import os

#search http://localhost:8080/index.html 

# Server Port
serverPort = 8080

# Create TCP Socket
serverSocket = socket(AF_INET, SOCK_STREAM)

# Reuse Port
serverSocket.setsockopt(SOL_SOCKET, SO_REUSEADDR, 1)

# Bind Socket
serverSocket.bind(("", serverPort))

# Listen for clients
serverSocket.listen(1)

print(f"Server running at http://localhost:{serverPort}")

while True:
    print("\nWaiting for connection...")

    # Accept connection
    connectionSocket, addr = serverSocket.accept()
    print("Connected by:", addr)

    try:
        # Receive HTTP Request
        message = connectionSocket.recv(1024).decode()
        print("\nREQUEST:\n")
        print(message)

        # Extract requested file
        filename = message.split()[1]

        # Default page
        if filename == "/":
            filePath = "index.html"
        else:
            filePath = filename[1:]  # Remove '/'

        print("Opening file:", filePath)

        # Get absolute path of current folder
        baseDir = os.path.dirname(os.path.abspath(__file__))
        fullPath = os.path.join(baseDir, filePath)

        # Open HTML file
        with open(fullPath, "r") as f:
            outputData = f.read()

        # Create HTTP Response
        response = "HTTP/1.1 200 OK\r\n"
        response += "Content-Type: text/html\r\n"
        response += "Connection: close\r\n\r\n"
        response += outputData

        # Send HTML
        connectionSocket.sendall(response.encode())

        print("Response sent successfully!")

    except FileNotFoundError:
        print("404 File Not Found")

        response = """HTTP/1.1 404 Not Found\r
Content-Type: text/html\r
Connection: close\r
\r
<!DOCTYPE html>
<html>
<head>
    <title>404 Not Found</title>
</head>
<body>
    <h1>404 Not Found</h1>
    <p>Requested File Does Not Exist</p>
</body>
</html>
"""

        connectionSocket.sendall(response.encode())

    except Exception as e:
        print("ERROR:", e)

    finally:
        connectionSocket.close()
        print("Connection Closed")