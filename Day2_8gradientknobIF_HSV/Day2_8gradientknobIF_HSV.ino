//SETUP CODE
#include "FastLED.h"

#define NUM 32
#define DATA_PIN 3

CRGB leds[NUM];

void setup() { FastLED.addLeds<WS2811, DATA_PIN>(leds, NUM); }

//LOOPING CODE
void loop() {
  
  int knob = analogRead(14);
  
  if (knob<512) {
    for(int i = 0; i < NUM; i++) {
       leds[i] = CHSV(i*8, 255, 255);
    }
  }
  
  if (knob>512) {
    for(int i = 0; i < NUM; i++) {
       leds[i] = CRGB::Green;
    }
  }
     
  FastLED.show();

}    

