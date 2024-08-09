from splashkit import *

write_line("About to start the server...")

# Start a web server - defaults to listening to port 8080
server = start_web_server_with_default_port()

write_line("Waiting for a request - navigate to http://localhost:8080")

# Wait and get the first request that comes in
request = next_web_request(server)

# Send back the index.html file
send_html_file_response(request, "index.html")

# For now, we are done, so let's shutdown
stop_web_server(server)

read_line() # Pause to keep the console window open