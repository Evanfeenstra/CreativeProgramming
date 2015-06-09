//SETUP CODE
#include "FastLED.h"

#define NUM 32
#define DATA_PIN 3

CRGB leds[NUM];

void setup() { FastLED.addLeds<WS2811, DATA_PIN>(leds, NUM); }

int wait = 0;
//LOOPING CODE
void loop() {
  //A "FOR LOOP" THAT CYCLES THROUGH ALL THE LEDS
  for(int i = 0; i < NUM; i++) {
     leds[i] = CRGB::Red;
     FastLED.show();
     leds[i] = CRGB::Black;
     delay(analogRead(20)/50);
  }
  for(int i = NUM-1; i >= 0; i--) {
     leds[i] = CRGB::Red;
     FastLED.show();
     leds[i] = CRGB::Black;
     delay(analogRead(20)/50);
  }
  
  for(int i = 0; i < NUM; i++) {
     leds[i] = CRGB::Green;
     FastLED.show();
     leds[i] = CRGB::Black;
     delay(analogRead(20)/50);
  }
  for(int i = NUM-1; i >= 0; i--) {
     leds[i] = CRGB::Green;
     FastLED.show();
     leds[i] = CRGB::Black;
     delay(analogRead(20)/50);
  }
  
  for(int i = 0; i < NUM; i++) {
     leds[i] = CRGB::Blue;
     FastLED.show();
     leds[i] = CRGB::Black;
     delay(analogRead(20)/50);
  }
  for(int i = NUM-1; i >= 0; i--) {
     leds[i] = CRGB::Blue;
     FastLED.show();
     leds[i] = CRGB::Black;
     delay(analogRead(20)/50);
  }
}    

