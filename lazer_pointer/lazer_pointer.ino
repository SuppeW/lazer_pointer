#include <Servo.h>

Servo servo;

 int Xpos, XposLast = 90;
 int buttonVal = 0;
  
 const int button_pin = 4; // digital pin connected to switch output
 const int X_pin = 0; // analog pin connected to X output
 const int Y_pin = 1; // analog pin connected to Y output
 const int laser_pin = 6; //laser pin
 const int servo_pin = 8; //servo pin
 const int led_pin = 13; //led pin


void setup() {
  pinMode(button_pin, INPUT);
  pinMode(laser_pin, OUTPUT);
  servo.attach(servo_pin);
  delay(2000);
}

void loop() {
  if(analogRead(X_pin) < 500  || analogRead(X_pin) > 520){
    Xpos = analogRead(X_pin);     
    Xpos = map(Xpos,0,1023,0,180);
    Xpos = (90-Xpos)/10;
    XposLast += Xpos;
    if(XposLast <0){
      XposLast = 0;
    }else if(XposLast > 180){
      XposLast = 180;
    }
  }
  servo.write(XposLast);
  
  buttonVal = digitalRead(button_pin);
  if(buttonVal == HIGH){
    digitalWrite(laser_pin, HIGH);
    digitalWrite(led_pin, HIGH);
  }else{
    digitalWrite(laser_pin, LOW);
    digitalWrite(led_pin, LOW);
  }
  delay(50);
}
