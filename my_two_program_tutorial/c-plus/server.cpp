#include "splashkit.h"

void start_server(const string& name, int port) {
    server_socket server = nullptr;
    try {
        // Create the server
        server = create_server(name, port);
        write_line("Server '" + name + "' started, listening on port " + std::to_string(port));

        while (true) {
            // Check for new connections and network activity
            check_network_activity();
            
            if (accept_new_connection(server)) {
                connection client_connection = last_connection(server);
                unsigned int client_ip = connection_ip(client_connection);
                write_line("Connected by " + std::to_string(client_ip));

                while (is_connection_open(client_connection)) {
                    // Read message data from the connection
                    if (has_messages(client_connection)) {
                        string data = read_message_data(client_connection);
                        write_line("Message read attempt...");
                        if (data.empty()) {
                            break;
                        }
                        write_line("Received from client: " + data);

                        // Send confirmation back to the client
                        string confirmation_message = "Server received the message: " + data;
                        send_message_to(confirmation_message, client_connection);
                        write_line("Responded to client " + std::to_string(client_ip));
                    }
                    check_network_activity();
                }

                // Client disconnected
                write_line("Client " + std::to_string(client_ip) + " disconnected.");
            }
        }
    } catch (const std::exception& e) {
        write_line("Server error: " + string(e.what()));
    }

    if (server != nullptr) {
        close_server(server);
    }
    write_line("Server closed.");
}

int main() {
    start_server("MyServer", 65432);
    return 0;
}
