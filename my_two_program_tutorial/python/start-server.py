from splashkit import *

def start_server(name, port):
    try:
        # Create the server
        server = create_server_with_port(name, port)
        write_line(f"Server '{name}' started, listening on port {port}")

        while True:
            # Check for new connections and network activity
            check_network_activity()
            
            # Check for new connections
            if accept_new_connection(server):
                # Get the last connection
                connection = last_connection(server)
                client_name = connection_ip(connection)
                write_line(f"Connected by {client_name}")

                # Keep the connection open
                while is_connection_open(connection):
                    check_network_activity()
           
    finally:
        if server:
            # Close the server
            close_connection(server)
        write_line("Server closed.")

if __name__ == "__main__":
    start_server("MyServer", 65432)
