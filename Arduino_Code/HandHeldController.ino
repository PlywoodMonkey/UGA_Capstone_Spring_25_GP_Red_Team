/* 
*  File   - HandheldController.ino
*  Author - Samuel Brewster
*  Class  - MCHE 4911
*
*  The following code is used to control whether the claw on the drone attachment is opening or closing. Two LEDs are 
*  used to signify the correct output of voltage to the motor.
*
*  Simply renamed the variables and resetup the LEDs in order to provide a way to output to them instead of connecting 3.3V power.
*/

// Create variables for ease of changing pins
int greenLEDOutput  = 2; // Green Dupont
int yellowLEDOutput = 3; // Yellow Dupont
int redLEDOutput    = 4; // Red Dupont
int greenLEDInput   = 5; // Orange Dupont
int redLEDInput     = 6; // Purple Dupont


void setup() {

  Serial.begin(9600);       // Setup the Serial Output

  pinMode(greenLEDInput, INPUT); // Setup the current GPIO pin for the Green LED as an input
  pinMode(redLEDInput, INPUT);   // Setup the current GPIO pin for the Red LED as an input

  Serial.println("start");  // Communicate to user that program has begun
} // end of setup


void loop() {

  if ((digitalRead(greenLEDInput) && digitalRead(redLEDInput)) == 1) {
    Serial.println("Both buttons are pushed: Do Nothing");
  } else if (digitalRead(greenLEDInput) == 1) {
    Serial.println("The Green LED is pushed");
  } else if (digitalRead(redLEDInput) == 1) {
    Serial.println("The Red LED is pushed");
  } // end of if/else-if

} // end of loop
