//SETUP CODE
#include "FastLED.h"

#define NUM 32
#define DATA_PIN 3

CRGB leds[NUM];

void setup() { FastLED.addLeds<WS2811, DATA_PIN>(leds, NUM); }

//LOOPING CODE
void loop() {
  
  int knob = analogRead(20);
  leds[(knob/32)-1] = CRGB::Red;
  FastLED.show();

  for(int i = 0; i < NUM; i++) {
     leds[i] = CRGB::Black;
  }
  
}    

