//SETUP CODE
#include "FastLED.h"

#define NUM 32
#define DATA_PIN 3

CRGB leds[NUM];

void setup() { FastLED.addLeds<WS2811, DATA_PIN>(leds, NUM); }

//LOOPING CODE
void loop() {
  //MAKES THE FIRST LED LIGHT UP RED
  leds[0] = CRGB::Red;
  FastLED.show();
}    

