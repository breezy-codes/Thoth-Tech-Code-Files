from splashkit import *

# Get a single JSON web resource
get_data = http_get("https://jsonplaceholder.typicode.com/posts/1", 443)
response = http_response_to_string(get_data)
free_response(get_data)

# Parse the response as JSON
json_response = json_from_string(response)

# Output the response
print("UserID => " + str(json_read_number_as_int(json_response, "userId")))
print("ID     => " + str(json_read_number_as_int(json_response, "id")))
print("Title  => " + json_read_string(json_response, "title"))
print("Body   => " + json_read_string(json_response, "body"))
print("================")

# Free the JSON object after use
free_json(json_response)
