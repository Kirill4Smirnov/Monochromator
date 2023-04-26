#include <Servo.h>

Servo myservo;

int photopin = A0;
int diodpin = A5;
int val, input;

void setup() {
  myservo.attach(9);
  Serial.begin(9600);
  
  //pinMode(9, OUTPUT);
  pinMode(photopin, INPUT);
}

void loop() {
  //Serial.println("here");
  //serial_read();
  
  val = analogRead(photopin);
  Serial.println(val);

  

  input = serial_read();
  if (input == 5){
    analogWrite(9, 500);
  } else if (input == -5){
    analogWrite(9, 0);
  }
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

void control_servo(int pos, Servo servo) { //gets pos from 0 to 180
  servo.write(pos);
  delay(15);
}
