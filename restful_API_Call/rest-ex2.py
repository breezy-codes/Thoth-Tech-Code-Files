from splashkit import *

# Get a list of a JSON web resource
get_data = http_get("https://jsonplaceholder.typicode.com/posts/", 443)
response = http_response_to_string(get_data)
free_response(get_data)

# To access each JSON key value pair the string should be split to an vector<json>
# objects for simplicity sake we output just the string here.
print(response)
