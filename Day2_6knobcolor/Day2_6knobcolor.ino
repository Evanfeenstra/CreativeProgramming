//SETUP CODE
#include "FastLED.h"

#define NUM 32
#define DATA_PIN 3

CRGB leds[NUM];

void setup() { FastLED.addLeds<WS2811, DATA_PIN>(leds, NUM); }

//LOOPING CODE
void loop() {
  
  int knob = analogRead(20);
  for(int i = 0; i < NUM; i++) {
     leds[i] = CRGB(256-knob/4,50,knob/4);
  }
     
  FastLED.show();

}    

