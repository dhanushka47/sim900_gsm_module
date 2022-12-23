#include <SoftwareSerial.h>

// SIM900A RX is connected to Arduino D7
// SIM900A TX is connected to Arduino D8
SoftwareSerial sim900a(7, 8); // RX, TX

void setup() {
  // Set baud rate for SIM900A serial communication
  sim900a.begin(19200);

  // Initialize SIM900A
  sim900a.println("AT+CPIN?");
  delay(1000);
  sim900a.println("AT+CREG?");
  delay(1000);
  sim900a.println("AT+CMGF=1");
  delay(1000);
}

void loop() {
  // Send SMS message
  sim900a.println("AT+CMGS=\"+1234567890\"");
  delay(1000);
  sim900a.println("Hello World!");
  delay(1000);
  sim900a.println((char)26); // ASCII code for "End of Text" character
  delay(1000);
}
