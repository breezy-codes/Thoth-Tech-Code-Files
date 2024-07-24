from splashkit import *

def start_server(host='127.0.0.1', port=65432):
    server_name = "MyServer"
    server = create_server_with_port(server_name, port)

    if server:
        print(f"Server started, listening on {host}:{port}")
    else:
        print("Failed to start server.")
        return

    while True:
        print("Waiting for a new connection...")
        new_client = None
        while not new_client:
            if accept_new_connection(server):
                new_client = fetch_new_connection(server)

        client_ip = str(connection_ip(new_client))
        client_port = connection_port(new_client)
        client_name = f"{client_ip}:{client_port}"
        print(f"Connected by {client_name}")

        while has_connection(client_name):
            if has_messages_on_connection(new_client):
                client_message = read_message(new_client)
                if client_message:
                    message_text = message_data(client_message)
                    print(f"Received from client {client_name}: {message_text}")
                    response_message = f"Message accepted: {message_text}"
                    send_message_to_connection(response_message, new_client)
                    print(f"Response sent to client {client_name}")

            delay(1)

        print(f"Client {client_name} disconnected")
        close_connection(new_client)

if __name__ == "__main__":
    start_server()
