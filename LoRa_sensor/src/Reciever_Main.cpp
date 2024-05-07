#include <SPI.h>
#include <LoRa.h>
#include <Hash.h>
// - Pin configs - ESP32 -
#define ss 5
#define rst 14
#define dio0 2

// - Pin configs - ESP8266 -
// #define ss 4    // D2
// #define rst  5 // D1
// #define dio0 -1 // Disabled

// Taken from https://forum.arduino.cc/t/arduino-split-funktion-eines-strings/595753
String split(String s, char parser, int index) {
  String rs = "";
  int parserIndex = index;
  int parserCnt = 0;
  int rFromIndex = 0, rToIndex = -1;
  while (index >= parserCnt) {
    rFromIndex = rToIndex + 1;
    rToIndex = s.indexOf(parser, rFromIndex);
    if (index == parserCnt) {
      if (rToIndex == 0 || rToIndex == -1) return "";
      return s.substring(rFromIndex, rToIndex);
    } else parserCnt++;
  }
  return rs;
}

void setup() {
  Serial.begin(115200);
  while (!Serial);

  Serial.println("LoRa Receiver");
  LoRa.setPins(ss, rst, dio0);
if (!LoRa.begin(868E6)) {
    Serial.println("Starting LoRa failed!");
    delay(5000);
    Serial.println("Now waiting for Watchdog to restart");
    while (1);
  }else{
    Serial.println("Starting LoRa successful");
    }
}

void loop() {
  // try to parse packet
  int packetSize = LoRa.parsePacket();
  if (packetSize) {
    // received a packet
    Serial.print("Received packet '");

    // Create a string of the incoming message
    String message = ""; 
    while (LoRa.available()) {
      message += (char)LoRa.read();
    }
    Serial.print(message);
 
    String result = sha1(split(message, ';', 0)); // Take the first element, the raw message and hashing it
    String tempy = message;
    tempy.replace(split(message, ';', 0) + ";", ""); // Now replace the message so only the hash is left
    if (result == tempy) { // Is the hash the same?
      Serial.print(" Hash ok ");
    } else {
      Serial.print(" Hash fail, expectd hash ");
      Serial.print(tempy);
      Serial.print(" "); 
      Serial.print(split(message, ';', 1)); 
      Serial.print(" "); 
    }

    // print RSSI of packet
    Serial.print("' with RSSI ");
    Serial.println(LoRa.packetRssi());
  }
}