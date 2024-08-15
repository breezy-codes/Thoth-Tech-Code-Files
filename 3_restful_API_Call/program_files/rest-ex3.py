from splashkit import *

# Create a JSON Web resource
# Create the JSON body for the HTTP POST call
body = create_json()
json_set_string(body, "title", "foo")
json_set_string(body, "body", "test entry")
json_set_number_integer(body, "userId", 1)

# Create the header for the HTTP POST call
headers = ["Content-type: application/json; charset=UTF-8"]

# Send the request
get_data = http_post_with_headers("https://jsonplaceholder.typicode.com/posts", 443, json_to_string(body), headers)
response = http_response_to_string(get_data)
free_response(get_data)

# Output the response
json_response = json_from_string(response)
print("Following resource has been created")
print("UserID => " + str(json_read_number_as_int(json_response, "userId")))
print("ID     => " + str(json_read_number_as_int(json_response, "id")))
print("Title  => " + json_read_string(json_response, "title"))
print("Body   => " + json_read_string(json_response, "body"))
print("================")