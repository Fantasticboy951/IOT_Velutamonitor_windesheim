#include <string.h>
#include <pico/stdlib.h>
#include "LoRa-RP2040.h"
#include "hardware/gpio.h"
#include "hardware/uart.h"
#include <stdio.h>

// Functie om het interne LED-lampje te laten knipperen
void blink_led(int times) {
    const uint LED_PIN = PICO_DEFAULT_LED_PIN;
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    for (int i = 0; i < times; i++) {
        gpio_put(LED_PIN, 1);
        sleep_ms(200);
        gpio_put(LED_PIN, 0);
        sleep_ms(200);
    }
}

int main() {
    // Initialize the UART instance (use uart1)
    uart_inst_t * UART_ID = uart1;  // UART ID for the Pico

    stdio_init_all();   // Initialize all of the stdio functions
    sleep_ms(1000);  // Delay to ensure serial monitor is ready

    // Initialize the UART serial communication
    const uint UART_TX_PIN = 6;  // TX pin number (GP4)
    const uint UART_RX_PIN = 7;  // RX pin number (GP5)
    const uint baudrate = 9600;  // Set this to the baudrate supported by your GPS module

    // Probeer UART te initialiseren en de pinnen in te stellen
    uart_init(UART_ID, baudrate);
    gpio_set_function(UART_TX_PIN, GPIO_FUNC_UART);
    gpio_set_function(UART_RX_PIN, GPIO_FUNC_UART);
    uart_set_hw_flow(UART_ID, false, false);
    uart_set_format(UART_ID, 8, 1, UART_PARITY_NONE);

    // Check UART initialisatie en GPS-communicatie
    bool gps_communication = false;
    sleep_ms(1000);  // Geef tijd om te starten
    if (uart_is_readable(UART_ID)) {
        gps_communication = true;
        blink_led(3);  // Knipper LED 3 keer bij succes
    }

    if (gps_communication) {
        blink_led(2);  // Alles is correct, knipper LED 2 keer
    } else {
        blink_led(1);  // Geen communicatie met GPS-module, knipper LED 1 keer
    }

    // Initialize LoRa
    printf("Starting LoRa\n");

    if (!LoRa.begin(500E6)) {
        printf("Starting LoRa failed!\n");
        blink_led(1);  // Knipper LED 1 keer bij fout
        while (1);
    }

    while (1) {
        // Transmit received data from GPS module to the serial monitor and via LoRa
        if (uart_is_readable(UART_ID)) {
            char gps_data[256];
            int index = 0;
            while (uart_is_readable(UART_ID) && index < 255) {
                char ch = uart_getc(UART_ID);
                putchar(ch);  // Send to USB-serial
                gps_data[index++] = ch;
            }
            gps_data[index] = '\0';  // Null-terminate the string

            // Send GPS data via LoRa
            printf("Sending GPS data via LoRa: %s\n", gps_data);
            LoRa.beginPacket();
            LoRa.print(gps_data);
            LoRa.endPacket();
            sleep_ms(1000);
        }
    }

    return 0;
}
