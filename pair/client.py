from splashkit import *

def start_client(host='127.0.0.1', port=65432):
    client_name = "ClientConnection"

    client = open_connection(client_name, host, port)

    if client:
        print(f"Connected to server at {host}:{port}")
    else:
        print("Failed to connect to server.")
        return

    while True:
        message = input("Enter message to send (or 'exit' to quit): ")
        if message.lower() == 'exit':
            break

        try:
            send_message_to_connection(message, client)
            print(f"Sent to server: {message}")

            while has_messages_on_connection(client):
                server_message = read_message(client)
                if server_message:
                    response_text = message_data(server_message)
                    print(f"Received from server: {response_text}")
        except Exception as e:
            print(f"Error sending or receiving message: {e}")

if __name__ == "__main__":
    start_client()
