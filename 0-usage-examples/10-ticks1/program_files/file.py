from splashkit import *

# Get the ticks before delay
ticks_before = current_ticks()
write_line(f"Ticks before: {ticks_before}")

# Delay for 10 seconds (10000 milliseconds)
delay(10000)

# Get the ticks after delay
ticks_after = current_ticks()
write_line(f"Ticks after: {ticks_after}")
