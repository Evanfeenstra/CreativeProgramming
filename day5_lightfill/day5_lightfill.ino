#include "FastLED.h"

#define NUM_LEDS 60
#define DATA_PIN 0

CRGB leds[NUM_LEDS];
int lightPin = 17;

void setup() { 
  FastLED.addLeds<WS2811, DATA_PIN>(leds, NUM_LEDS); 

}



void loop() { 
  light();
}

void light() {
  
  int lightlevel = analogRead(lightPin)/16;
 
  
  for(int i = 0; i < 32; i++) {
    leds[i]=CRGB::Black; 
    for(int i=0; i<lightlevel; i++) {
     leds[i] = CRGB::Green;
    }
    
    FastLED.show();
    }
  
  
}
