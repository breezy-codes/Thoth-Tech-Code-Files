from splashkit import *

def main():
  x = 0


  window = open_window("Mouse Location", 800, 600)

  while not window_close_requested(window):
      # Process user input events
      process_events()

      # Update x-coordinate if the left mouse button is down
      if mouse_down(MouseButton.left_button):
          x = mouse_x()

      # Clear the screen with white color
      clear_screen(color_white())

      # Draw a blue circle at the center of the screen
      fill_circle(color_blue(), 400, 300, 100)

      # Draw a purple "curtain" from the left side of the screen to the x-coordinate of the mouse
      fill_rectangle(color_purple(), 0, 0, x, window_height(window))


      refresh_window(window)


  close_window(window)

if __name__ == "__main__":
  main()
