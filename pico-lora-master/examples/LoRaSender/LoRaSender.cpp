#include <string.h>
#include <pico/stdlib.h>
#include "LoRa-RP2040.h"

int main() {

	stdio_init_all();

	sleep_ms(5000);

	printf("Starting LoRa\n");

	if (!LoRa.begin(500E6)) {
		printf("Starting LoRa failed!\n");
		while (1);
	}
	
	string information[5] = {"CoordinatesMonitors:\nmonitor1 = {53.39380810895207 \n 6.377531971130557} monitor2 = {53.34820152031504\n 6.284628700694686} monitor3 = {53.34099105955094, 6.375722843936565}\n","Distance to nest:\n Monitor 1 = 3676.92 \nMonitor 2 = 4326.32\nMonitor 3 = 4359.05\n", "Calculated location of nest via trilateration: {53.3721, 6.33603}\n", "true location of Hive: {53.37208112298921, 6.335904439215057}\n", "End message\n"};

	uint8_t counter = 0;

	while (1) {
		printf("Sending packets: ");
		// send packet
		for (counter = 0; counter < 5; counter++)
		{
			LoRa.beginPacket();
			LoRa.print("\n  ");
			LoRa.print(information[counter]);
			LoRa.endPacket();
			sleep_ms(1000);
		}
		printf("Packets received\n");
		sleep_ms(5000);
		
  }
  return 0;
}