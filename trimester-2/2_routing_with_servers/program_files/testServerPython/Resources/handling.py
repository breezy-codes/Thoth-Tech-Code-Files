from splashkit import *


write_line("About to start the server...")

server = start_web_server_with_default_port()

write_line("Waiting for a request - navigate to http://localhost:8080")
write_line("To end - navigate to http://localhost:8080/quit")

# Get the next request that the server has
request = next_web_request(server)

while not is_get_request_for(request, "/quit"):
    write_line("I got a request for " + request_uri(request))

    if is_get_request_for(request, "/login") or is_get_request_for(request, "/login.html"):
        # Serve page for login path, e.g.
        # send_html_file_response(request, "login.html")

        send_response(request, "login page")
    elif is_get_request_for(request, "/contact") or is_get_request_for(request, "/contact.html"):
        # Serve page for contact path, e.g.
        # send_html_file_response(request, "contact.html")

        send_response(request, "contact page")

    elif is_get_request_for(request, "/about") or is_get_request_for(request, "/about.html"):
        # Server page for about path, e.g.
        # send_html_file_response(request, "about.html")

        send_response(request, "about page")

    else:
        # If no specified path is requested, serve index.html to the user
        send_html_file_response(request, "index.html")

    write_line("Waiting for a request - navigate to http://localhost:8080")
    write_line("To end - navigate to http://localhost:8080/quit")

    # Get the next request that the server has
    request = next_web_request(server)

write_line("About to stop the server...")
stop_web_server(server)