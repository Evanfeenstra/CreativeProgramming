#include <Adafruit_NeoPixel.h>

int ledPin = 0;
int num = 30;

Adafruit_NeoPixel strand = Adafruit_NeoPixel(num, ledPin, NEO_GRB + NEO_KHZ800);

void setup() {
  strand.begin();
  Serial.begin(9600);
  pinMode(12, INPUT_PULLUP);
}

int touch1 = 0;
int touch1old = 0;
int touch2 = 0;
int touch2old = 0;
int threshold = 1000;
int bright = 255;
int knob = 0;

void loop() {
  if (digitalRead(12) == 1) {
    cap();
  }
  else {
    bounce();
  }
}

void strobe() {
  for (int i = 0; i < 20; i++) {
    for (int i = 0; i < num; i++) {
      strand.setPixelColor(i, 255, 255, 255);
    }
    delay(100);
    strand.show();
    for (int i = 0; i < num; i++) {
      strand.setPixelColor(i, 0, 0, 0);
    }
    delay(100);
    strand.show();
  }
}
void bounce() {
  int knob = analogRead(14) / 4;
  for (int i = 0; i < num; i++) {
    if (checkTouch() == true && i == 29) {
      strobe();
    }
    strand.setPixelColor(i, i * 8, 255 - i * 8, 0);
    strand.show();
    delay(knob);
    strand.setPixelColor(i, 0, 0, 0);
  }
  for (int i = num; i >= 0; i--) {
    strand.setPixelColor(i, i * 8, 255 - i * 8, 0);
    strand.show();
    delay(knob);
    strand.setPixelColor(i, 0, 0, 0);
  }
}

bool checkTouch() {
  touch1old = touch1;
  touch1 = touchRead(23);
  if (touch1 - touch1old > threshold) {
    return true;
  }
  else {
    return false;
  }
}

void cap() {
  touch1old = touch1;
  touch1 = touchRead(23);
  touch2old = touch2;
  touch2 = touchRead(22);
  knob = analogRead(14);
  if (touch1 - touch1old > threshold) {
    for (int i = 0; i < num; i++) {
      strand.setPixelColor(i, i * 8 + knob, 255 - i * 8, touch1);
    }
    bright = 255;
  }
  if (touch2 - touch2old > threshold) {
    for (int i = 0; i < num; i++) {
      strand.setPixelColor(i, i * 8 - touch2, 255 - i * 5, knob);
    }
    bright = 255;
  }
  strand.setBrightness(bright);
  bright--;
  strand.show();
  delay(10);
}
