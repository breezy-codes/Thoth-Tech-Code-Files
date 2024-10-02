from splashkit import *

def start_server(name, port):
    server_running = True  # Flag to control the server loop
    server = None  # Initialize server to None for safety

    try:
        # Create the server
        server = create_server_with_port(name, port)
        write_line(f"Server '{name}' started, listening on port {port}")

        # Start GUI window
        open_window("Server Interface", 150, 100)

        while server_running:
            process_events()  # Handle events in GUI

            # Check for new connections and network activity
            check_network_activity()

            # Draw the "Close Server" button in the window
            clear_screen(color_white)
            if button("Close Server", rectangle_from(25, 25, 100, 50)):
                server_running = False
                break  # Exit loop to stop the server

            # Check if a new connection has been accepted
            if accept_new_connection(server):
                connection = last_connection(server)
                client_name = connection_ip(connection)
                write_line(f"Connected by {client_name}")

                while is_connection_open(connection) and server_running:
                    # Read message data from the connection
                    if has_messages_on_connection(connection):
                        data = read_message_data_from_connection(connection)
                        if not data:
                            break
                        write_line(f"Received from client: {data}")

                        # Send confirmation back to the client
                        confirmation_message = f"Server received the message: {data}"
                        send_message_to_connection(confirmation_message, connection)
                        write_line(f"Responded to client {client_name}")
                    
                    # Check for network activity to handle new messages
                    check_network_activity()

                # Close the connection if it's still open
                if is_connection_open(connection):
                    close_connection(connection)
                    write_line(f"Connection with {client_name} closed.")

            draw_interface()  # Refresh the interface
            refresh_screen()

        # Close all connections and clean up when the server is stopped
        write_line("Server shutting down...")
    except Exception as e:
        write_line(f"Server error: {e}")
    finally:
        # Ensure the server is closed properly if it was created
        if server is not None:
            # There's no need to call `close_connection` on the server
            write_line("Closing server...")
            close_server(server)  # Use `close_server()` instead of `close_connection()`

        write_line("Server closed.")
        close_all_windows()  # Close the GUI window

if __name__ == "__main__":
    start_server("MyServer", 65432)
