from splashkit import *

# Get a list of a JSON web resource
get_data = http_get("https://jsonplaceholder.typicode.com/posts/", 443)
response = http_response_to_string(get_data)
free_response(get_data)

# Output the response
print(response)
