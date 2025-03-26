/* 
*  File   - HandheldController.ino
*  Author - Samuel Brewster
*  Class  - MCHE 4911
*
*  The following code is used to control whether the claw on the drone attachment is opening or closing. Two LEDs are 
*  used to signify the correct output of voltage to the motor.
*
*  Currently, it only tells the user when they are pushing a button, but will send an error message if they push both 
*  at the same time.
*/

// Create variables for ease of changing pins
int greenLED = 6;
int redLED = 5;

void setup() {

  Serial.begin(9600);       // Setup the Serial Output

  pinMode(greenLED, INPUT); // Setup the current GPIO pin for the Green LED as an input
  pinMode(redLED, INPUT);   // Setup the current GPIO pin for the Red LED as an input

  Serial.println("start");  // Communicate to user that program has begun
} // end of setup


void loop() {

  if ((digitalRead(greenLED) && digitalRead(redLED)) == 1) {
    Serial.println("Both buttons are pushed: Do Nothing");
  } else if (digitalRead(greenLED) == 1) {
    Serial.println("The Green LED is pushed");
  } else if (digitalRead(redLED) == 1) {
    Serial.println("The Red LED is pushed");
  } // end of if/else-if

} // end of loop
