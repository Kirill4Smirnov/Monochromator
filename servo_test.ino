#include <Servo.h>

Servo myservo;

const int photopin = A0;
const int diodpin = A5;
const int servopin = 9;
int val, input;

void setup() {
  myservo.attach(servopin);
  Serial.begin(9600);
  
  //pinMode(9, OUTPUT);
  pinMode(photopin, INPUT);
}

void loop() {
  //Serial.println("here");
  //serial_read();
  
  //val = analogRead(photopin);
  //Serial.println(val);

  
/*
  input = serial_read();
  if (input == 5){
    analogWrite(9, 500);
  } else if (input == -5){
    analogWrite(9, 0);
  }
  */

  //control_servo(90, myservo);
  //Serial.println("+90");
  //delay(1000);

  control_servo(90, myservo);
  Serial.println("180");
  delay(1000);
}


int serial_read() {
  while (Serial.available() == 0) {}
    int zone = Serial.parseInt();
    if (zone != 0){
      Serial.print("You entered: ");
      Serial.println(zone);
      return zone;
    }
}

void control_servo(int pos, Servo servo) { // 90 stands for neutral, >90 - positive direction, <90 - negative direction of rotation
  servo.write(pos);
  delay(15);
}
