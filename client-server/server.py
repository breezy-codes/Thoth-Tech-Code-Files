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
        # Accept all new connections
        accept_all_new_connections()

        # Check for new connections
        if server_has_new_connection(server):
            new_client = fetch_new_connection(server)
            if new_client:
                client_name = f"{host}:{connection_port(new_client)}"
                connections[client_name] = new_client
                print(f"Connected by {client_name}")

        # Process messages from existing connections
        for client_name, conn in list(connections.items()):
            if has_connection(client_name):
                try:
                    while has_messages_on_connection(conn):
                        client_message = read_message(conn)
                        if client_message:
                            message_text = message_data(client_message)
                            print(f"Received from client {client_name}: {message_text}")
                            response_message = f"Message accepted: {message_text}"
                            send_message_to_connection(response_message, conn)
                            print(f"Response sent to client {client_name}")
                except Exception as e:
                    print(f"Error processing message from {client_name}: {e}")
            else:
                print(f"Connection {client_name} lost, removing connection.")
                del connections[client_name]

if __name__ == "__main__":
    start_server()
