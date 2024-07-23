import socket

# Define the host and the designated port to use
def start_client(host='127.0.0.1', port=65432):
    # Create a socket object
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        # Connect to the server
        s.connect((host, port))
        print(f"Connected to server at {host}:{port}")

        while True:
            # Get user input
            message = input("Enter message to send (or 'exit' to quit): ")
            if message.lower() == 'exit':
                break
            # Send data to the server
            s.sendall(message.encode())
            # Receive data from the server
            data = s.recv(1024)
            print(f"Received from server: {data.decode()}")


if __name__ == "__main__":
    start_client()
