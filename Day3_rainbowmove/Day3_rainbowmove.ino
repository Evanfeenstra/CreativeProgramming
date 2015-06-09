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
  for(int j=0; j<200; j++) {
    for(int i = 0; i < NUM; i++) {
       leds[i] = CHSV(i*8+j, 255, 255);
    }
    FastLED.show();
  }
}
