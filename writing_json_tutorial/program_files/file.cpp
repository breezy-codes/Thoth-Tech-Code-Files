#include "splashkit.h"

int main()
{
    raspi_init();
    pins led_pin = PIN_11;
    raspi_set_mode(led_pin, GPIO_OUTPUT);

    open_window("dummy_window", 1, 1);
    while(!any_key_pressed())
    {
        process_events();
        raspi_write(led_pin, GPIO_HIGH);
        delay(500);
        raspi_write(led_pin, GPIO_LOW);
        delay(500);
    }

    close_all_windows();
    raspi_cleanup();
    return 0;
}