from splashkit import *

def main():

  black_hole_radius = 50
  window_width, window_height = 800, 600
  window = open_window("Mouse Visibility", window_width, window_height)


  black_hole_center = point_at(window_width / 2, window_height / 2)

  while not window_close_requested(window):
      # Process user input events
      process_events()

      # Get the current mouse position
      mouse_pos = mouse_position()

      # Calculate distance from the mouse to the black hole center
      dx = mouse_pos.x - black_hole_center.x
      dy = mouse_pos.y - black_hole_center.y
      distance = (dx ** 2 + dy ** 2) ** 0.5

      # Hide or show the mouse based on distance
      if distance <= black_hole_radius:
          hide_mouse()
      else:
          show_mouse()

      # Clear the screen with white color
      clear_screen(color_white())

      # Draw the black hole as a circle
      fill_circle(color_black(), black_hole_center.x, black_hole_center.y, black_hole_radius)


      refresh_window(window)


  close_all_windows()

if __name__ == "__main__":
  main()
