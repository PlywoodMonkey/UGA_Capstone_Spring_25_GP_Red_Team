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
  radio.openReadingPipe(0,address);
  radio.setPALevel(RF24_PA_MAX); // Could be RF24_PA_Min
  radio.setDataRate(RF24_250KBPS); // May not be necessary
  radio.startListening();

  pinMode(2, OUTPUT);       // Change Pin 2 to be an OUTPUT GPIO Pin
  Serial.println("Begin");  // Communicate that Program has been setup
  digitalWrite(2, 1);       // Test the LED
  Serial.println("On");
  delay(1000);              // Leave on for one second
  digitalWrite(2, 0);       // Turn the LED back off
  Serial.println("Off");
} // setup()

// Loop to be done indefintely
void loop() {
  char text[32] = "";
  
  // If the program can find a radio, it will enter the following loop
  if (radio.available()) {
    Serial.println("Radio Found"); // Communicate to the user that it is connected
    radio.read(&text, sizeof(text)); // Read the data sent
    String transData = String(text); // Convert to string
    //Serial.print(text); // Print the Text
    
    // Logic to turn LED on
    if (transData == "nrftest") {
      Serial.print("------Message Found!------");
        // Toggle the LED for one second
        digitalWrite(2, 1);
        delay(10000);
        digitalWrite(2, 0);
      } // if
      delay(500); // Delay half a second and repeat
  } // if
} // loop()
