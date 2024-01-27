#include <Arduino.h>
#include <Joystick.h>
const int bindings[4][2] = {{3, 1}, {4, 2}, {5, 3}, {6, 4}};
Joystick_ Joystick;
void setup() {
  // put your setup code here, to run once:
 for (int pin = 0; pin <= 3; pin++){
  pinMode(bindings[pin][0], INPUT);
  Joystick.begin(true);
 }
}


void loop() {
  // put your main code here, to run repeatedly:
  for (int pin = 0; pin <= 3; pin++){
      if (digitalRead(bindings[pin][0] == HIGH)){
        Serial.print(1);
        Joystick.setButton(bindings[pin][1], 1);
      } else {
        Joystick.setButton(bindings[pin][1], 0);
      }
  }
}
