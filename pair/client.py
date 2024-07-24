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

        send_message_to_name(message, client_name)
        print(f"Sent to server: {message}")

        while not has_messages_on_name(client_name):
            delay(1)  # wait for a short period to avoid busy waiting

        while has_messages_on_name(client_name):
            server_message = read_message()
            if server_message:
                response_text = message_data(server_message)
                print(f"Received from server: {response_text}")

    close_connection(client)

if __name__ == "__main__":
    start_client()
