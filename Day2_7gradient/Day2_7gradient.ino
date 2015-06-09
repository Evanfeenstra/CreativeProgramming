//SETUP CODE
#include "FastLED.h"

#define NUM 32
#define DATA_PIN 3

CRGB leds[NUM];

void setup() { FastLED.addLeds<WS2811, DATA_PIN>(leds, NUM); }

//LOOPING CODE
void loop() {
  
 hi();

}    

void hi() {
   int knob = analogRead(20);
  for(int i = 0; i < NUM; i++) {
     leds[i] = CRGB(255-i*8,124,i*8);
  }
     
  FastLED.show();
}
