# include <Servo.h>
const int SW_pin = 2;
const int X_pin = 0;
const int y_pin = 1;

Servo bservo; //base servo 360
Servo gservo; // grippy servo
Servo servo1; // two servos
Servo servo2;


void setup() {
  pinMode(SW_pin, INPUT);
  digitalWrite(SW_pin, HIGH);
  servo2.attach (11);
  servo1.attach (12);
  bservo.attach (13);
  gservo.attach (14);
  Serial.begin(9060);

}



void loop() {
  int Xposition;
  int Yposition; 
  Xposition = analogRead(X_pin);
 
  int bservopos;
  bservopos = map(Yposition, 0,1023, 0, 180);
  bservo.write(bservopos);
  delay(180);
  // base servo movement

  int  12pos;
  12pos = map(Xposition,0,1023, 0, 180);
  servo1.write(12pos);
  servo2.write(12pos);
  delay(180);

  int gservo pos = 0;
  button = digitalRead(SW_pin);

  if(button == HIGH){
    if (gservo pos = 0){
      gservo.write(180);
    }
    else{
      gservo.write(0);
    }
    delay(500);
  }
}
