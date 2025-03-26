/* 
*  File   - HandheldController.ino
*  Author - Samuel Brewster
*  Class  - MCHE 4911
*
*  The following code is used to control whether the claw on the drone attachment
*  is opening or closing. Two LEDs are used to signify the correct output of voltage 
*  to the motor.
*/

int greenLED = 6;
int redLED = 5;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600); // Setup Serial Output
  pinMode(greenLED, INPUT);
  pinMode(redLED, INPUT);
  Serial.println("start"); // Communicate to user that program has begun
}

void loop() {

  // put your main code here, to run repeatedly:
  Serial.println(digitalRead(greenLED));
  Serial.println(digitalRead(redLED));

}
