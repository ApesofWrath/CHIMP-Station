#include <Arduino.h>
#include <Joystick.h>
const int bindings[13][2] = {{22, 1}, {24, 2}, {26, 3}, {28, 4}, {30, 5}, {32, 6}, {34, 7}, {36, 8}, {38, 9}, {40, 10}, {42, 11}, {44, 12}, {46, 13} };
// const int bindings[4][2] = {{22, 1}, {24, 2}, {26, 3}, {28, 4}};

Joystick_ Joystick;
void setup() {
  // put your setup code here, to run once:
 for (int pin = 0; pin <= 12; pin++){
  pinMode(bindings[pin][0], INPUT_PULLUP);
 }
  Joystick.begin(true);
}


void loop() {
  // put your main code here, to run repeatedly:
  for (int pin = 0; pin <= 12; pin++){
      if (digitalRead(bindings[pin][0]) == LOW){
        Joystick.setButton(bindings[pin][1], 1);
      } else {
        Joystick.setButton(bindings[pin][1], 0);
      }
  }
}
