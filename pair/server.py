from splashkit import *

def start_server(host='127.0.0.1', port=65432):
    server_name = "MyServer"
    server = create_server_with_port(server_name, port)

    if server:
        print(f"Server started, listening on {host}:{port}")
    else:
        print("Failed to start server.")
        return

    connections = {}

    while True:
        accept_all_new_connections()

        while new_connection_count(server) > 0:
            new_client = fetch_new_connection(server)
            if new_client:
                client_name = name_for_connection(host, connection_port(new_client))
                connections[client_name] = new_client
                print(f"Connected by {client_name}")

        for client_name, conn in list(connections.items()):
            if has_connection(client_name):
                while has_messages_on_name(client_name):
                    client_message = read_message()
                    if client_message:
                        message_text = message_data(client_message)
                        print(f"Received from client {client_name}: {message_text}")
                        response_message = f"Message accepted: {message_text}"
                        send_message_to_name(response_message, client_name)
                        print(f"Response sent to client {client_name}")

        delay(1)  # Prevents the server loop from consuming 100% CPU

if __name__ == "__main__":
    start_server()
