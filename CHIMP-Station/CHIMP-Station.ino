#include <Joystick.h>

// Create the Joystick
Joystick_ Joystick;

// Constant that maps the physical pin to the joystick button.

int currentButtonState = 0;
void setup() {
	// Initialize Button Pins

	// Initialize Joystick Library
	Joystick.begin();
  
}


void loop() {

	// Read pin values
  if (currentButtonState == 1){
    currentButtonState = 0;
  }else{
    currentButtonState = 1;
  }
	Joystick.setButton(0, currentButtonState);


	delay(1000);
}