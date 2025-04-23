#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int closeArmInput   = 2;  // Green Dupont
int openArmInput    = 3;  // Yellow Dupont
int outputToMotor   = 10; // Red Dupont

double degreesRotated  = 0;

void setup() {

  Serial.begin(9600);
  myservo.attach(outputToMotor);  // attaches the servo on pin 10 to the servo object

}

void loop() {

  if ((digitalRead(closeArmInput) && digitalRead(openArmInput)) == 1) {

    Serial.print(degreesRotated);
    Serial.println(" : Claw is not moving (BOTH BUTTONS PUSHED)");

  } else if (digitalRead(openArmInput) == 1) {
    
      degreesRotated += 2;
      Serial.print(degreesRotated);
      Serial.println(" : Opening Claw (GREEN LED ON)");    

  } else if (digitalRead(closeArmInput) == 1) {

      degreesRotated -= 2;
      Serial.print(degreesRotated);
      Serial.println(" : Closing Claw (RED LED ON)");

  }

  myservo.write(degreesRotated);  

} // end of loop
