#include <Arduino.h>
#include <Joystick.h>
const int button_count = 8;
const int led_pin = 48;
// const int bindings[button_count][2] = {{22, 1}, {24, 2}, {26, 3}, {28, 4}, {30, 5}, {32, 6}, {34, 7}, {36, 8}, {38, 9}, {40, 10}, {42, 11}, {44, 12}, {46, 13} };
// const int bindings[4][2] = {{22, 1}, {24, 2}, {26, 3}, {28, 4}};
const int bindings[button_count][2] = {{22, 2}, {42, 5}, {26, 12}, {28, 3}, {30, 11}, {36, 4}, {38, 1}, {32, 10}};
Joystick_ Joystick;
void setup() {
  // put your setup code here, to run once:
 for (int pin = 0; pin <= button_count; pin++){
  pinMode(bindings[pin][0], INPUT_PULLUP);
 }
 pinMode(led_pin, OUTPUT);
  Joystick.begin(true);
  Serial.begin(9600);
  Serial.println("Started");
}


void loop() {
  // put your main code here, to run repeatedly:
  for (int pin = 0; pin <= button_count; pin++){
      if (digitalRead(bindings[pin][0]) == LOW){
        Joystick.setButton(bindings[pin][1], 1);
        Serial.print(pin);
        if (pin == 0){
          digitalWrite(led_pin, HIGH);
        } 
      } else {
        Joystick.setButton(bindings[pin][1], 0);
        digitalWrite(led_pin, LOW);
      }
  }
}
