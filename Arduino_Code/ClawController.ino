/* 
*  File   - ClawController.ino
*  Author - Samuel Brewster
*  Class  - MCHE 4911
*
*  Description to be written.
*/

int closeArmInput  = 7;
int openArmInput   = 6;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);       // Setup the Serial Output

  pinMode(closeArmInput,     INPUT);  // Setup the current GPIO pin for the left button as an input
  pinMode(openArmInput,      INPUT);  // Setup the current GPIO pin for the right button as an input

  Serial.println("start");  // Communicate to user that program has begun

}

void loop() {
  // put your main code here, to run repeatedly:

  if ((digitalRead(openArmInput)) == 1) {
    // Put PWM Open here
    Serial.println("Opening");
  } else if (digitalRead(closeArmInput) == 1) {
    // Put PWM Close here
    Serial.println("Closing");
  } 

}
