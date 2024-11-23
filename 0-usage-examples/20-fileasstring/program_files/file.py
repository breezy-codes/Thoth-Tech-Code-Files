from splashkit import *

# Read the file content as a string
file_content = file_as_string("hello.json", resource_kind.json_resource)

# Display the content in the console
write_line("File Contents:")
write_line(file_content)