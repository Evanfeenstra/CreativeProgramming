#include "FastLED.h"

#define NUM_LEDS 60

CRGB leds[NUM_LEDS];
int lightPin = 15;

void setup() { FastLED.addLeds<WS2811, 3>(leds, 60); }

void loop() { 
  rainbow(10);
}

void rainbow(int wait) {
  
  for(int j = 1; j<255; j++) {
    int reading = analogRead(lightPin);
    int brightness = (int)((reading/4));
    for(int i = 0; i < NUM_LEDS; i++) {
      leds[i] = CHSV((i+j), 255, brightness);
    }
    FastLED.show();
    delay(wait); }  
}
