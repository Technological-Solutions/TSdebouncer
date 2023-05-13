#include <Arduino.h>
#include <TSdebouncer.h>

#define BUTTON1 2
#define BUTTON2 3
#define BUTTON3 4

// button instance needs pin, levelshift, activestate
TSdebouncer BTN1(BUTTON1,4,true);   // pin 2 , levelshift of 4, activehigh
TSdebouncer BTN2(BUTTON2,1,false);  // pin 3 , levelshift of 1, activelow
TSdebouncer BTN3(BUTTON3);

void BTN1_CALLBACK(bool value) {
  if (value == 0) {
    Serial.println("BUTTON1 RELEASED!");
  }
  if (value == 1) {
    Serial.println("BUTTON1 PRESSED!");
  }
}

void BTN2_CALLBACK(bool value) {
  if (value == 0) {
    Serial.println("BUTTON2 RELEASED!");
  }
  if (value == 1) {
    Serial.println("BUTTON2 PRESSED!");
  }
}

void BTN3_CALLBACK(bool value) {
  if (value == 0) {
    Serial.println("BUTTON3 RELEASED!");
  }
  if (value == 1) {
    Serial.println("BUTTON3 PRESSED!");
  }
}

void setup() {
  Serial.begin(9600);
  pinMode(BUTTON1, INPUT);
  BTN1.event = &BTN1_CALLBACK;
  BTN2.event = &BTN2_CALLBACK;
  BTN3.event = &BTN3_CALLBACK;
}

void loop() {
  BTN1.poll();
  BTN2.poll();
  BTN3.poll();
  delay(10);
}