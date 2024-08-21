#include "splashkit.h"
using std::to_string;

void start_client(const string& name, const string& host = "127.0.0.1", int port = 65432) {
    // Create the client connection
    connection client = open_connection(name, host, port);
    write_line("Connected to server at " + host + ":" + to_string(port));

    // Keep the connection open
    while (is_connection_open(client)) {
        check_network_activity();
    }

    // Close the client connection
    close_connection(client);
    write_line("Client closed.");
}

int main() {
    start_client("MyClient", "127.0.0.1", 65432);
    return 0;
}
