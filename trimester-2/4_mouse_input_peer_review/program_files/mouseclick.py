from splashkit import *
COLOR_RED = color_red()
COLOR_YELLOW = color_yellow()
COLOR_WHITE = color_white()

def main():

  win = open_window("Mouse Inputs", 800, 600)

  current_color = COLOR_WHITE

  # Main loop
  while not window_close_requested(win):
      # Process user input events
      process_events()

      # Check mouse click status and change screen color
      if mouse_clicked(MouseButton.left_button):

          current_color = COLOR_RED  # Change color to red
      elif mouse_clicked(MouseButton.right_button):

          current_color = COLOR_YELLOW  # Change color to yellow

      # Clear screen with the current color
      clear_screen(current_color)


      refresh_window(win)


  close_window(win)

if __name__ == "__main__":
  main()
