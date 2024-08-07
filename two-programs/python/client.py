from splashkit import *

def start_client(name, host='127.0.0.1', port=65432):
    # Create the client connection
    client = open_connection(name, host, port)
    print(f"Connected to server at {host}:{port}")

    while is_connection_open(client):
        # Get user input
        message = input("Enter message to send (or 'exit' to quit): ")
        if message.lower() == 'exit':
            break
        # Send data to the server
        print(f"Sending to server: {message}")
        send_message_to_connection(message, client)
        # Check for new network activity and wait for the server response
        while True:
            check_network_activity()
            if has_messages_on_connection(client):
                msg = read_message_data_from_connection(client)
                print(f"Received from server: {msg}")
                break

    # Close the client connection
    close_connection(client)

if __name__ == "__main__":
    start_client("MyClient", "127.0.0.1", 65432)
