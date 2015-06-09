#include "FastLED.h"

#define NUM_LEDS 60
#define DATA_PIN 0

CRGB leds[NUM_LEDS];

void setup() { FastLED.addLeds<WS2811, DATA_PIN>(leds, NUM_LEDS); 
pinMode(12, INPUT_PULLUP);}

int offset = 42;     //the amount that the color changes each time. 256 / 6 = 42

void loop() {
for(int i=0; i<32; i++) {
  leds[i]=CRGB::Green; 
 }
 FastLED.show();
  
  
  
  
  if (digitalRead(12)==LOW) {red();}
 
}    


void cylon() {
  
        for(int i = 0; i < NUM_LEDS; i++) {
		leds[i] = CHSV(84+15, 255, 255);
		FastLED.show();
		leds[i] = CRGB::Black;
		delay(15);
	}

	// Now go in the other direction.  
	for(int i = NUM_LEDS-1; i >= 0; i--) {
		leds[i] = CHSV(84+15, 255, 255);
		FastLED.show();
		leds[i] = CRGB::Black;
		delay(15);
	}
  
}

void red() {
 for(int i=0; i<32; i++) {
  leds[i]=CRGB::Red; 
 }
 FastLED.show();
}
