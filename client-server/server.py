import socket

# Define the host and the designated port to use
def start_server(host='127.0.0.1', port=65432):
    # Create a socket object
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        # Bind the socket to the address and port
        s.bind((host, port))
        # Listen for incoming connections
        s.listen()
        print(f"Server started, listening on {host}:{port}")

        # Accept a connection
        conn, addr = s.accept()
        with conn:
            print(f"Connected by {addr}")
            while True:
                # Receive data from the client
                data = conn.recv(1024)
                if not data:
                    break
                print(f"Received from client: {data.decode()}")
                # Send data back to the client
                conn.sendall(data)


if __name__ == "__main__":
    start_server()
