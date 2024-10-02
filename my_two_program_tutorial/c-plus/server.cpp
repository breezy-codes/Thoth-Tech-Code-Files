#include "splashkit.h"
using std::to_string;

void start_server(const string& name, int port) {
    server_socket server = nullptr;
    bool server_running = true;  // Control flag for the server

    // Create the server
    server = create_server(name, port);
    write_line("Server '" + name + "' started, listening on port " + to_string(port));

    // Open a graphical window for controlling the server
    open_window("Server Control", 200, 100);

    while (server_running) {
        // Process GUI events
        process_events();

        // Draw the "Close Server" button in the GUI window
        clear_screen(COLOR_WHITE);
        if (button("Close Server", rectangle_from(50, 25, 100, 50))) {
            server_running = false;
            break;  // Exit the loop to stop the server
        }
        draw_interface();
        refresh_screen();

        // Check for new connections and network activity
        check_network_activity();
        
        if (accept_new_connection(server)) {
            connection client_connection = last_connection(server);
            unsigned int client_ip = connection_ip(client_connection);
            write_line("Connected by " + to_string(client_ip));

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
                    write_line("Responded to client " + to_string(client_ip));
                }
                check_network_activity();
            }

            // Client disconnected
            write_line("Client " + to_string(client_ip) + " disconnected.");
        }
    }

    // Close the server when the loop exits
    if (server != nullptr) {
        close_server(server);
    }
    write_line("Server closed.");

    // Close the GUI window
    close_all_windows();
}

int main() {
    start_server("MyServer", 65432);
    return 0;
}
