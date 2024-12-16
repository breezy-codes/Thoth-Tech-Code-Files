from splashkit import *

def start_client(name, host='127.0.0.1', port=65432):
    try:
        # Create the client connection
        client = open_connection(name, host, port)
        write_line(f"Connected to server at {host}:{port}")
        
        # Keep the connection open
        while is_connection_open(client):
            check_network_activity()
        
    finally:
        if client:
            # Close the client connection
            close_connection(client)
        write_line("Client closed.")

if __name__ == "__main__":
    start_client("MyClient", "127.0.0.1", 65432)