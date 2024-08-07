#include "splashkit.h"
#include <string>

void start_server(const std::string& name, int port) {
    // Assign the server to nullptr to ensure it is not left uninitialised
    server_socket server = nullptr;
    
    // Create the server
    server = create_server(name, port);
    write_line("Server '" + name + "' started, listening on port " + std::to_string(port));

    while (true) {
        // Check for new connections and network activity
        check_network_activity();
        
        // Accept new connections
        if (accept_new_connection(server)) {
            // Get the last connection
            connection client_connection = last_connection(server);
            unsigned int client_ip = connection_ip(client_connection);
            write_line("Connected by " + std::to_string(client_ip));

            // Keep the connection open
            while (is_connection_open(client_connection)) {
                check_network_activity();
            }

            // Client disconnected
            write_line("Client " + std::to_string(client_ip) + " disconnected.");
        }
    }

    // Close the server
    if (server != nullptr) {
        close_server(server);
    }
    write_line("Server closed.");
}

int main() {
    start_server("MyServer", 65432);
    return 0;
}
