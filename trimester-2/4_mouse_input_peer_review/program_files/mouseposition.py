from splashkit import *

def main():

  window = open_window("Mouse Location", 800, 600)

  while not window_close_requested(window):
      # Process user input events
      process_events()

      # Clear the screen with white color
      clear_screen(color_white())

      # Get the current mouse position
      mouse_pos = mouse_position()

      # Draw a blue circle at the current mouse position
      fill_circle(color_light_blue(), mouse_pos.x, mouse_pos.y, 20)


      refresh_window(window)


  close_window(window)

if __name__ == "__main__":
  main()
