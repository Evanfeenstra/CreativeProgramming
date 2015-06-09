//SETUP CODE
#include "FastLED.h"

#define NUM 32
#define DATA_PIN 3

CRGB leds[NUM];

void setup() { FastLED.addLeds<WS2811, DATA_PIN>(leds, NUM); }

//LOOPING CODE
void loop() {
  
  int knob = analogRead(20);
  for(int i = 0; i < knob/32-1; i++) {
     leds[i] = CRGB::Green;
  }
     
  FastLED.show();
  
  for(int i =  knob/32-1; i < NUM; i++) {
     leds[i] = CRGB::Black;
  }
  
}    

