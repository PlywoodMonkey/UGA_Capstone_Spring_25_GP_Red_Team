#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

int greenLEDOutput  = 2; // Green Dupont
int yellowLEDOutput = 3; // Yellow Dupont
int redLEDOutput    = 4; // Red Dupont
int greenLEDInput   = 5; // Orange Dupont
int redLEDInput     = 6; // Purple Dupont

double degreesRotated  = 90;

void setup() {
  Serial.begin(9600);
  myservo.attach(10);  // attaches the servo on pin 9 to the servo object
}

void loop() {

  if ((digitalRead(greenLEDInput) && digitalRead(redLEDInput)) == 1) {

    Serial.print(degreesRotated);
    Serial.println(" : Claw is not moving (BOTH BUTTONS PUSHED)");

  } else if (digitalRead(greenLEDInput) == 1) {
    
    if (degreesRotated < 200){
      degreesRotated += 2;
      Serial.print(degreesRotated);
      Serial.println(" : Opening Claw (GREEN LED ON)");    
    } else if (degreesRotated == 90) {
      Serial.println("Claw is Fully Opened");
    }

  } else if (digitalRead(redLEDInput) == 1) {

    if (degreesRotated > 0){
      degreesRotated -= 2;
      Serial.print(degreesRotated);
      Serial.println(" : Closing Claw (RED LED ON)");
    } else if (degreesRotated == 0) {
      Serial.println("Claw is Fully Closed");
    }

  } else if (degreesRotated == 0) {
    
    Serial.println("Claw is Fully Closed");

  } else if (degreesRotated == 360) {

    Serial.println("Claw is Fully Opened");

  } else {
  }// end of if/else-if/else

  myservo.write(degreesRotated);  

} // end of loop
