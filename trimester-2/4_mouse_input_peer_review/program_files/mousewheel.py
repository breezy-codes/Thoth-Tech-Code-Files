from splashkit import *

def main():

  hue = 0.6
  saturation = 0.6
  brightness = 0.6


  window = open_window("Mouse Scrolling", 800, 600)

  while not window_close_requested(window):
      # Process user input events
      process_events()

      # Store the mouse wheel scroll direction and distance to the scroll variable
      scroll = mouse_wheel_scroll()

      # Change hue of screen color based on vertical mouse scrolling
      hue += scroll.y / 100.0

      # Ensure hue is within the valid range [0.0, 1.0]
      hue = min(max(hue, 0.0), 1.0)

      # Display current screen color
      clear_screen(hsb_color(hue, saturation, brightness))
      refresh_window(window)


  close_window(window)

if __name__ == "__main__":
  main()
