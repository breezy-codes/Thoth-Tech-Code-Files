from splashkit import *

def calculate_square_root(x):
    # Find the first perfect square greater than the input number
    p = 0
    while True:
        p += 1
        square = (p + 1) * (p + 1)  # Calculate the next perfect square
        if x <= square:  # Stop when x is less than or equal to the square
            break

    # Approximate the square root using the Newton-Raphson method
    y = float(p)
    c = 0
    while c < 10:  # Perform a maximum of 10 iterations
        y = (x / y + y) / 2  # Update the guess by averaging x/y and y

        if y * y == x:  # Check if the square of the current guess matches the input
            return y  # If exact, return the square root

        c += 1

    # Return the approximated square root after all iterations
    return y

result = calculate_square_root(23)
write_line(f"The square root of 25 is: {result}")