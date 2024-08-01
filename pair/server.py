from splashkit import *

def start_server(name, port):
    try:
        # Create the server
        server = create_server_with_port(name, port)
        print(f"Server '{name}' started, listening on port {port}")

        while True:
            # Check for new connections and network activity
            check_network_activity()
            
            if accept_new_connection(server):
                connection = last_connection(server)
                client_name = connection_ip(connection)
                print(f"Connected by {client_name}")

                while is_connection_open(connection):
                    # Read message data from the connection
                    if has_messages_on_connection(connection):
                        data = read_message_data_from_connection(connection)
                        if not data:
                            break
                        print(f"Received from client: {data}")

                        # Send confirmation back to the client
                        confirmation_message = f"Server received the message: {data}"
                        send_message_to_connection(confirmation_message, connection)
                        print(f"Responded to client {client_name}")
                    check_network_activity()
                
                # Client disconnected
                print(f"Client {client_name} disconnected.")
    except Exception as e:
        print(f"Server error: {e}")
    finally:
        if server:
            close_connection(server)
        print("Server closed.")

if __name__ == "__main__":
    start_server("MyServer", 65432)
