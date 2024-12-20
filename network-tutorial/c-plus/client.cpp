#include "splashkit.h"
using std::to_string;

void start_client(const string& name, const string& host = "127.0.0.1", int port = 65432) {
    // Create the client connection
    connection client = open_connection(name, host, port);
    write_line("Connected to server at " + host + ":" + to_string(port));

    while (is_connection_open(client)) {
        // Get user input
        write("Enter message to send (or 'exit' to quit): ");
        string message = read_line();

        // Send the message to the server
        write_line("Sending message: " + message);
        send_message_to(message, client);

        // Check if the message is "exit"
        if (message == "exit") {
            send_message_to(message, client);
            write_line("Exit message sent. Closing client...");
            break; // Exit the loop
        }

        // Check for new network activity and wait for the server response
        while (true) {
            check_network_activity();
            if (has_messages(client)) {
                string msg = read_message_data(client);
                write_line("Received from server: " + msg);
                break;
            }
        }
    }

    // Close the client connection
    close_connection(client);
    write_line("Client closed.");
}

int main() {
    start_client("MyClient", "127.0.0.1", 65432);
    return 0;
}
