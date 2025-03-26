/* 
*  File   - HandheldController.ino
*  Author - Samuel Brewster
*  Class  - MCHE 4911
*
*  The following code is used to control whether the claw on the drone attachment is opening or closing. Two LEDs are 
*  used to signify the correct output of voltage to the motor.
*
*  Currently turns on only one LED at a time, either the Green, Red, or Yellow one. Proof of concept for the handheld controller
*  as it is controlled by output GPIO pins which will go to the battery and stepper motor. 
*/

// Create variables for ease of changing pins
int greenLEDOutput  = 2; // Green Dupont
int yellowLEDOutput = 3; // Yellow Dupont
int redLEDOutput    = 4; // Red Dupont
int greenLEDInput   = 5; // Orange Dupont
int redLEDInput     = 6; // Purple Dupont


// Code for the setup
void setup() {

  Serial.begin(9600);       // Setup the Serial Output

  pinMode(greenLEDOutput,   OUTPUT); // Setup the current GPIO pin for the Green LED as an output
  pinMode(yellowLEDOutput,  OUTPUT); // Setup the current GPIO pin for the Yellow LED as an output
  pinMode(redLEDOutput,     OUTPUT); // Setup the current GPIO pin for the Red LED as an output
  pinMode(greenLEDInput,    INPUT);  // Setup the current GPIO pin for the left button as an input
  pinMode(redLEDInput,      INPUT);  // Setup the current GPIO pin for the right button as an input

  Serial.println("start");  // Communicate to user that program has begun
} // end of setup


// Main loop to be run continously
void loop() {

  if ((digitalRead(greenLEDInput) && digitalRead(redLEDInput)) == 1) {
    Serial.println("Both buttons are pushed: Do Nothing");
    turnOnYellowLED();
  } else if (digitalRead(greenLEDInput) == 1) {
    Serial.println("The Green LED is pushed");    
    turnOnGreenLED();
  } else if (digitalRead(redLEDInput) == 1) {
    Serial.println("The Red LED is pushed");
    turnOnRedLED();
  } else {
    turnOffAllLEDs();  
  }// end of if/else-if/else

} // end of loop


// Turns off all of the LEDs at once
void turnOffAllLEDs() {
  digitalWrite(greenLEDOutput,  0);
  digitalWrite(yellowLEDOutput, 0);
  digitalWrite(redLEDOutput,    0);
}


// Turns on ONLY the Green LED
void turnOnGreenLED(){
  digitalWrite(greenLEDOutput,  1);
  digitalWrite(yellowLEDOutput, 0);
  digitalWrite(redLEDOutput,    0);
}


// Turns on ONLY the Yellow LED
void turnOnYellowLED(){
  digitalWrite(greenLEDOutput,  0);
  digitalWrite(yellowLEDOutput, 1);
  digitalWrite(redLEDOutput,    0);
}


// Turns on ONLY the Red LED
void turnOnRedLED(){
  digitalWrite(greenLEDOutput,  0);
  digitalWrite(yellowLEDOutput, 0);
  digitalWrite(redLEDOutput,    1);
}
