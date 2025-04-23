#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(7,8); // Define the CE and CSN pins

const byte address[6] = "00001"; // Address of SPI

// Function to Setup the Arduino
void setup() {
  Serial.begin(9600); // Setup Serial Output

  // Begin the Radio Object and Setup
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MAX); // Could be RF24_PA_MIN
  radio.setDataRate(RF24_250KBPS); // Is this necessary?
  radio.stopListening();

  Serial.println("start"); // Communicate to user that program has begun
}

// Loop to be done indefinitely
void loop() {
  Serial.println("Top of Loop");    // Communicate Position in loop to user
  const char text[] = "nrftest";    // Define text to send
  radio.write(&text, sizeof(text)); // Send the above char
  delay(500);                       // Delat half a second and repeat
}
