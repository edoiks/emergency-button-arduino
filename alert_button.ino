#include "DigiKeyboard.h"
#define DEBOUNCE_TIME 2000 
#define BUTTON_PIN 2
#define BUTTON_IRQ 0

volatile bool buttonPressed = false;
volatile static unsigned long lastPressedTime = 0;

void setup() {
  pinMode(BUTTON_PIN, INPUT);
  digitalWrite(BUTTON_PIN, LOW);
  attachInterrupt(BUTTON_IRQ, buttonISR, FALLING);
}


void loop() {
  if (buttonPressed){
    DigiKeyboard.update();
    DigiKeyboard.sendKeyStroke(0);
    DigiKeyboard.sendKeyStroke(KEY_L, MOD_GUI_LEFT);
    buttonPressed = false;
  }
  
}

void buttonISR() {
  if ( millis()-lastPressedTime > DEBOUNCE_TIME )
  {
    buttonPressed = true;
    lastPressedTime = millis();
  }
}
