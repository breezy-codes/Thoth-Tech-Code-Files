from splashkit import *


COLOR_RED = color_red()
COLOR_YELLOW = color_yellow()
COLOR_WHITE = color_white()

def main():

  window = open_window("Mouse Inputs", 800, 600)

  current_color = COLOR_WHITE


  while not window_close_requested(window):
      # Process user input events
      process_events()

      # Check mouse button status and change screen color
      if mouse_down(MouseButton.left_button):

          current_color = COLOR_RED  # Change color to red
      elif mouse_down(MouseButton.right_button):

          current_color = COLOR_YELLOW  # Change color to yellow
      else:
          current_color = COLOR_WHITE  # Default color if no mouse button is held down


      clear_screen(current_color)


      refresh_window(window)

  # Close the window
  close_window(window)

if __name__ == "__main__":
  main()
