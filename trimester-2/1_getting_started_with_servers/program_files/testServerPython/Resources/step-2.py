from splashkit import *

write_line("About to start the server...")

# Start a web server - defaults to listening to port 8080
server = start_web_server()

# For now we are done... so lets shutdown...
stop_web_server(server)