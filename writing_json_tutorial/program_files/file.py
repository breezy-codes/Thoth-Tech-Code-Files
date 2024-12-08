from splashkit import *

# Initialize Raspberry Pi GPIO
raspi_init()
led_pin = PIN_11  # Define the pin for the LED
raspi_set_mode(led_pin, GPIO_OUTPUT)  # Set the pin as output

# Open a dummy window
open_window("dummy_window", 1, 1)

while not any_key_pressed():
    process_events()
    
    # Turn the LED on (HIGH)
    raspi_write(led_pin, GPIO_HIGH)
    delay(500)

    # Turn the LED off (LOW)
    raspi_write(led_pin, GPIO_LOW)
    delay(500)

# Close all windows and cleanup GPIO
close_all_windows()
raspi_cleanup()