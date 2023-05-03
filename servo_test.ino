#include <Servo.h>

Servo myservo;

const int photopin = A0;
const int button1pin = 12;
const int button2pin = 13;
const int servopin = 9;
int val, input;

void setup() {
  myservo.attach(servopin);
  Serial.begin(9600);

  //pinMode(9, OUTPUT);
  pinMode(photopin, INPUT);
  pinMode(button1pin, INPUT_PULLUP);
  pinMode(button2pin, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(button1pin) != HIGH) {
    control_servo(100, myservo);
    //Serial.println("button1 is pressed, servo is set to 100");
  } else if (digitalRead(button2pin) != HIGH) {
    control_servo(80, myservo);
    //Serial.println("button2 is pressed, servo is set to 80");
  } else {
    control_servo(90, myservo);
  }

  val = analogRead(photopin);
  Serial.println(val);
  
  delay(100);
}


int serial_read() {
  while (Serial.available() == 0) {}
  int zone = Serial.parseInt();
  if (zone != 0) {
    Serial.print("You entered: ");
    Serial.println(zone);
    return zone;
  }
}

void control_servo(int pos, Servo servo) { // 90 stands for neutral, >90 - positive direction, <90 - negative direction of rotation
  servo.write(pos);
  delay(15);
}
