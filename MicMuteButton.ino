
// USB Key board https://www.usb.org/sites/default/files/documents/hut1_12v2.pdf
// https://digistump.com/wiki/digispark for digispark  https://github.com/digistump/DigistumpArduino/
// IO pin 3 is third up from bottom, bottom is three seperate pins.
// https://defkey.com/ site that track key combinations
// Window mic mute software https://sourceforge.net/projects/micmute/

#include "DigiKeyboard.h"
#include <Bounce2.h>

#define MUTE_PIN 2
#define LED_PIN 1
int ledState = LOW;
Bounce debouncer = Bounce(); 

void setup() {                
  pinMode(LED_PIN, OUTPUT); //LED on Model A   
  debouncer.attach(MUTE_PIN, INPUT_PULLUP);
  debouncer.interval(25);
 }

void loop() {
  debouncer.update(); // Update the Bounce instance
  DigiKeyboard.update();
  if ( debouncer.fell() ) {  // Call code if button transitions from HIGH to LOW
     ledState = !ledState; // Toggle LED state
     DigiKeyboard.sendKeyStroke(KEY_SPACE, MOD_CONTROL_LEFT);
     digitalWrite(LED_PIN,ledState); // Apply new LED state
   }
}
