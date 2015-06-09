//SETUP CODE
#include "FastLED.h"

#define NUM 32
#define DATA_PIN 3

CRGB leds[NUM];

void setup() { FastLED.addLeds<WS2811, DATA_PIN>(leds, NUM); }

//LOOPING CODE
void loop() {
  //A "FOR LOOP" THAT CYCLES THROUGH ALL THE LEDS
  for(int i = 0; i < NUM; i++) {
     leds[i] = CRGB::Red;
     FastLED.show();
     leds[i] = CRGB::Black;
     delay(30);
  }
  
  for(int i = 0; i < NUM; i++) {
     leds[i] = CRGB::Green;
     FastLED.show();
     leds[i] = CRGB::Black;
     delay(30);
  }
  
  for(int i = 0; i < NUM; i++) {
     leds[i] = CRGB::Blue;
     FastLED.show();
     leds[i] = CRGB::Black;
     delay(30);
  }
}    

