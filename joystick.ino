#include <Servo.h>

const int SW_pin = 2;//joy button
const int X_pin = 0;
const int Y_pin = 1;

Servo bservo; // Base servo 360
Servo gservo; // Grippy servo
Servo servo1; // Two servos
Servo servo2;

void setup() {
  pinMode(SW_pin, INPUT);
  digitalWrite(SW_pin, HIGH);
  servo2.attach(11);
  servo1.attach(12);
  bservo.attach(13);
  gservo.attach(14);
  Serial.begin(9600); 

}

void loop() {
  int Xposition = analogRead(X_pin);
  int Yposition = analogRead(Y_pin);

  // Base servo movement
  int bservopos = map(Yposition, 0, 1023, 0, 180);
  bservo.write(bservopos);
  delay(180);

  // Two servo movement
  int servoPos = map(Xposition, 0, 1023, 0, 180);
  servo1.write(servoPos);
  servo2.write(servoPos);
  delay(180);

  // Grippy servo movement
  int gservoPos = 0;
  int button = digitalRead(SW_pin);

//claw
  if (button == HIGH) {
    if (gservoPos == 0) {
      gservo.write(180);
      gservoPos = 180; // Update the grippy servo position
    } else {
      gservo.write(0);
      gservoPos = 0; // Update the grippy servo position
    }
    delay(500);
  }
}
