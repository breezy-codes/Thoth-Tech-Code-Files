from splashkit import *

def main():
  y = 0


  window = open_window("Mouse Location", 800, 600)

  while not window_close_requested(window):
      # Process user input events
      process_events()

      if mouse_down(MouseButton.left_button):
          y = mouse_y()

      # Clear the screen with white color
      clear_screen(color_white())

      # Draw a blue circle at the center of the screen
      fill_circle(color_blue(), 400, 300, 100)

      # Draw a purple "curtain" from the top of the screen to the y-coordinate of the mouse
      fill_rectangle(color_purple(), 0, 0, window_width(window), y)


      refresh_window(window)


  close_window(window)

if __name__ == "__main__":
  main()
