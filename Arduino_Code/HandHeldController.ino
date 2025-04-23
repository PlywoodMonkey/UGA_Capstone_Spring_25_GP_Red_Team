/* 
*  File   - HandheldController.ino
*  Author - Samuel Brewster
*  Class  - MCHE 4911
*
*  The following code is used to control whether the claw on the drone attachment is opening or closing. Two LEDs are 
*  used to signify the correct output of voltage to the motor.
*
*  Behaves almost perfectly, now counts the (estimated) degrees that the claw is at and outputs a voltage to the according LED.
*  It also tells the user when they have completely opened or closed the arm, which is shown by the lighting of the yellow LED.
*
*  Left Button  - "Opens the Claw" (Outputs a high to the LED from GPIO 2).
*  Right Button - "Closes the Claw" (Outputs a high to the LED from GPIO 4).
*  Yellow LED   - Signifies that the user has either completely opened or closed the claw.
*/

// Create variables for ease of changing pins
int greenLEDOutput  = 2; // Green Dupont
int yellowLEDOutput = 7; // Yellow Dupont
int redLEDOutput    = 4; // Red Dupont
int greenLEDInput   = 5; // Orange Dupont
int redLEDInput     = 6; // Purple Dupont

int tellArmToClose  = 8;
int tellArmToOpen   = 9;

double degreesRotated  = 45;


// Code for the setup
void setup() {

  Serial.begin(9600);       // Setup the Serial Output

  pinMode(greenLEDOutput,   OUTPUT); // Setup the current GPIO pin for the Green LED as an output
  pinMode(yellowLEDOutput,  OUTPUT); // Setup the current GPIO pin for the Yellow LED as an output
  pinMode(redLEDOutput,     OUTPUT); // Setup the current GPIO pin for the Red LED as an output
  pinMode(greenLEDInput,    INPUT);  // Setup the current GPIO pin for the left button as an input
  pinMode(redLEDInput,      INPUT);  // Setup the current GPIO pin for the right button as an input

  pinMode(tellArmToClose, OUTPUT);
  pinMode(tellArmToOpen, OUTPUT);

  Serial.println("start");  // Communicate to user that program has begun
} // end of setup


// Main loop to be run continously
void loop() {

  if ((digitalRead(greenLEDInput) && digitalRead(redLEDInput)) == 1) {

    Serial.println("Claw is not moving (BOTH BUTTONS PUSHED)");
    turnOnYellowLED();

  } else if (digitalRead(greenLEDInput) == 1) {
    
    Serial.println("Opening Claw (GREEN LED ON)");
    digitalWrite(tellArmToOpen, 1);
    turnOnGreenLED();

  } else if (digitalRead(redLEDInput) == 1) {

    Serial.println("Closing Claw (RED LED ON)");
    digitalWrite(tellArmToClose, 1);
    turnOnRedLED();

  } else {
    digitalWrite(tellArmToOpen,  0);
    digitalWrite(tellArmToClose, 0);
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
