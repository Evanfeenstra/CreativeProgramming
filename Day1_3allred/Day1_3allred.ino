//SETUP CODE
#include "FastLED.h"

#define NUM 32
#define DATA_PIN 3

CRGB leds[NUM];

void setup() { FastLED.addLeds<WS2811, DATA_PIN>(leds, NUM); }

//LOOPING CODE
void loop() {
  //THIS "FOR LOOP" CYCLES THROUGH ALL THE LEDS
  for(int i = 0; i < NUM; i++) {
     leds[i] = CRGB::Red;
  }
  //THEN THEY ALL ARE TURNED ON RED
  FastLED.show();
}    

