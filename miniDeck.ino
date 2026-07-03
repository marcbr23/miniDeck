#include <BleKeyboard.h>
BleKeyboard bleKeyboard("MBR's miniDeck");

int state = 0;



void setup() {
  bleKeyboard.begin();
  delay(1000);

  pinMode(12, INPUT_PULLUP);
  pinMode(14, INPUT_PULLUP);
  pinMode(LED_BUILTIN, OUTPUT);

}

void loop() {
  if (digitalRead(12) == LOW) { 
    bleKeyboard.press(KEY_LEFT_GUI); 
    bleKeyboard.press('h');
    while (digitalRead(12) == LOW) {
      delay(10);
    }      
    bleKeyboard.release(KEY_LEFT_GUI);
    bleKeyboard.release('h');
    delay(100);
    
    if (state == 0) {
      state = 1;
      digitalWrite(LED_BUILTIN, HIGH);
    }
    
    else if (state == 1) {
      state = 0;
      digitalWrite(LED_BUILTIN, LOW);
    }
  }

  if (digitalRead(14) == LOW) { 
    bleKeyboard.press(KEY_LEFT_GUI); 
    bleKeyboard.press('a');

    while (digitalRead(14) == LOW) {
      delay(10);
    }
    bleKeyboard.release(KEY_LEFT_GUI); 
    bleKeyboard.release('a');
    delay(100);
    if (state == 0) {
      state = 1;
      digitalWrite(LED_BUILTIN, HIGH);
    }
    
    else if (state == 1) {
      state = 0;
      digitalWrite(LED_BUILTIN, LOW);
    }

  }

}