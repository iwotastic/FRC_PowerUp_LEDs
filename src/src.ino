//  LIGHTS ARE 48 LONG

#include "src.h"

//#define TEST_MODE_ENABLED

#ifdef TEST_MODE_ENABLED

#define COM Serial
#define SETUP begin(9600)
#define COM_READ COM.parseInt()

#else

#include <Wire.h>
#define COM Wire
#define SETUP begin(5)
#define COM_READ COM.read()

#endif

Pattern patterns[numarrays];

Adafruit_DotStar strip1 = Adafruit_DotStar(NUMPIXELS, DATAPIN1, CLOCKPIN1, DOTSTAR_BGR);
Adafruit_DotStar strip2 = Adafruit_DotStar(NUMPIXELS, DATAPIN2, CLOCKPIN2, DOTSTAR_BGR);
Adafruit_DotStar strip3 = Adafruit_DotStar(NUMPIXELS, DATAPIN3, CLOCKPIN3, DOTSTAR_BGR);
Adafruit_DotStar strip4 = Adafruit_DotStar(NUMPIXELS, DATAPIN4, CLOCKPIN4, DOTSTAR_BGR);
Adafruit_DotStar strip5 = Adafruit_DotStar(NUMPIXELS, DATAPIN5, CLOCKPIN5, DOTSTAR_BGR);
Adafruit_DotStar strip6 = Adafruit_DotStar(NUMPIXELS, DATAPIN6, CLOCKPIN6, DOTSTAR_BGR);

void setup() {
  strip1.begin(); 
  strip1.show();
  strip2.begin(); 
  strip2.show();
  strip3.begin(); 
  strip3.show();
  strip4.begin(); 
  strip4.show();
  strip5.begin(); 
  strip5.show();
  strip6.begin(); 
  strip6.show();

  pinMode(LED_BUILTIN, OUTPUT);

  COM.SETUP;

  patterns[0].setStrip(&strip1);
  patterns[1].setStrip(&strip2);
  patterns[2].setStrip(&strip3);
  patterns[3].setStrip(&strip4);
  patterns[4].setStrip(&strip5);
  patterns[5].setStrip(&strip6);

  patterns[0].setLocation(0, NUMPIXELS);
  patterns[0].aze(6, false);
  patterns[1].setLocation(0, NUMPIXELS);
  patterns[1].aze(2, true);
  patterns[2].setLocation(0, NUMPIXELS);
  patterns[2].aze(2, true);
  patterns[3].setLocation(0, NUMPIXELS);
  patterns[3].aze(6, false);
  patterns[4].setLocation(0, NUMPIXELS);
  patterns[4].aze(6, false);
  patterns[5].setLocation(0, NUMPIXELS);
  patterns[5].aze(2, true);
}

void loop() {
  for (int i = 0; i < numarrays; i++) {
    patterns[i].setPixels();
  }
  strip1.show();
  strip2.show();
  strip3.show();
  strip4.show();
  strip5.show();
  strip6.show();
  if (COM.available() > 0) {
    int code = COM_READ;
    switch (code) {
      case 8:
      patterns[0].setLocation(0, NUMPIXELS);
      patterns[0].scroll(0xff0000, 0x000000, NUMPIXELS, false);
      patterns[1].setLocation(0, NUMPIXELS);
      patterns[1].scroll(0xff0000, 0x000000, 10, false);
      patterns[2].setLocation(0, NUMPIXELS);
      patterns[2].scroll(0xff0000, 0x000000, 10, true);
      patterns[3].setLocation(0, NUMPIXELS);
      patterns[3].scroll(0xff0000, 0x000000, NUMPIXELS, false);
      patterns[4].setLocation(0, NUMPIXELS);
      patterns[4].scroll(0xff0000, 0x000000, 2, false);
      patterns[5].setLocation(0, NUMPIXELS);
      patterns[5].scroll(0xff0000, 0x000000, 2, true);
      break;
      case 7:
      patterns[0].setLocation(0, NUMPIXELS);
      patterns[0].flash(0xff00ff, 0xff8000, 100);
      patterns[1].setLocation(0, NUMPIXELS);
      patterns[1].flash(0xff00ff, 0xff8000, 100);
      patterns[2].setLocation(0, NUMPIXELS);
      patterns[2].flash(0xff00ff, 0xff8000, 100);
      patterns[3].setLocation(0, NUMPIXELS);
      patterns[3].flash(0xff00ff, 0xff8000, 100);
      patterns[4].setLocation(0, NUMPIXELS);
      patterns[4].scroll(0xff00ff, 0xff8000, 12, true);
      patterns[5].setLocation(0, NUMPIXELS);
      patterns[5].scroll(0xff00ff, 0xff8000, 12, true);
      break;
      case 6:
      patterns[0].setLocation(0, NUMPIXELS);
      patterns[0].flash(0xffff00, 0xff0000, 100);
      patterns[1].setLocation(0, NUMPIXELS);
      patterns[1].flash(0xffff00, 0xff0000, 100);
      patterns[2].setLocation(0, NUMPIXELS);
      patterns[2].flash(0xffff00, 0xff0000, 100);
      patterns[3].setLocation(0, NUMPIXELS);
      patterns[3].flash(0xffff00, 0xff0000, 100);
      patterns[4].setLocation(0, NUMPIXELS);
      patterns[4].scroll(0xffff00, 0xff0000, 12, false);
      patterns[5].setLocation(0, NUMPIXELS);
      patterns[5].scroll(0xffff00, 0xff0000, 12, false);
      break;
      case 5:
      patterns[0].setLocation(0, NUMPIXELS);
      patterns[0].flash(0xffff00, 0xff8000, 100);
      patterns[1].setLocation(0, NUMPIXELS);
      patterns[1].flash(0xffff00, 0xff8000, 100);
      patterns[2].setLocation(0, NUMPIXELS);
      patterns[2].flash(0xffff00, 0xff8000, 100);
      patterns[3].setLocation(0, NUMPIXELS);
      patterns[3].flash(0xffff00, 0xff8000, 100);
      patterns[4].setLocation(0, NUMPIXELS);
      patterns[4].scroll(0xffff00, 0xff8000, 12, false);
      patterns[5].setLocation(0, NUMPIXELS);
      patterns[5].scroll(0xffff00, 0xff8000, 12, false);
      break;
      case 4:
      patterns[0].setLocation(0, NUMPIXELS);
      patterns[0].flash(0xffff00, 0x00ff00, 100);
      patterns[1].setLocation(0, NUMPIXELS);
      patterns[1].flash(0xffff00, 0x00ff00, 100);
      patterns[2].setLocation(0, NUMPIXELS);
      patterns[2].flash(0xffff00, 0x00ff00, 100);
      patterns[3].setLocation(0, NUMPIXELS);
      patterns[3].flash(0xffff00, 0x00ff00, 100);
      patterns[4].setLocation(0, NUMPIXELS);
      patterns[4].scroll(0xffff00, 0x00ff00, 12, false);
      patterns[5].setLocation(0, NUMPIXELS);
      patterns[5].scroll(0xffff00, 0x00ff00, 12, false);
      break;
      case 3:
      patterns[0].setLocation(0, NUMPIXELS);
      patterns[0].flash(0xffff00, 0x000000, 100);
      patterns[1].setLocation(0, NUMPIXELS);
      patterns[1].flash(0xffff00, 0x000000, 100);
      patterns[2].setLocation(0, NUMPIXELS);
      patterns[2].flash(0xffff00, 0x000000, 100);
      patterns[3].setLocation(0, NUMPIXELS);
      patterns[3].flash(0xffff00, 0x000000, 100);
      patterns[4].setLocation(0, NUMPIXELS);
      patterns[4].scroll(0xffff00, 0x000000, NUMPIXELS, false);
      patterns[5].setLocation(0, NUMPIXELS);
      patterns[5].scroll(0xffff00, 0x000000, NUMPIXELS, false);
      break;
      case 2:
      patterns[0].setLocation(0, NUMPIXELS);
      patterns[0].scroll(0x0000ff, 0x000000, NUMPIXELS, false);
      patterns[1].setLocation(0, NUMPIXELS);
      patterns[1].scroll(0x0000ff, 0x000000, 10, false);
      patterns[2].setLocation(0, NUMPIXELS);
      patterns[2].scroll(0x0000ff, 0x000000, 10, true);
      patterns[3].setLocation(0, NUMPIXELS);
      patterns[3].scroll(0x0000ff, 0x000000, NUMPIXELS, false);
      patterns[4].setLocation(0, NUMPIXELS);
      patterns[4].scroll(0x0000ff, 0x000000, 2, false);
      patterns[5].setLocation(0, NUMPIXELS);
      patterns[5].scroll(0x0000ff, 0x000000, 2, true);
      break;
      case 1:
      patterns[0].setLocation(0, NUMPIXELS);
      patterns[0].aze(6, false);
      patterns[1].setLocation(0, NUMPIXELS);
      patterns[1].aze(6, true);
      patterns[2].setLocation(0, NUMPIXELS);
      patterns[2].aze(6, true);
      patterns[3].setLocation(0, NUMPIXELS);
      patterns[3].aze(6, false);
      patterns[4].setLocation(0, NUMPIXELS);
      patterns[4].aze(2, false);
      patterns[5].setLocation(0, NUMPIXELS);
      patterns[5].aze(2, true);
      break;
      default:
      patterns[0].setLocation(0, NUMPIXELS);
      patterns[0].aze(6, false);
      patterns[1].setLocation(0, NUMPIXELS);
      patterns[1].aze(6, true);
      patterns[2].setLocation(0, NUMPIXELS);
      patterns[2].aze(6, true);
      patterns[3].setLocation(0, NUMPIXELS);
      patterns[3].aze(6, false);
      patterns[4].setLocation(0, NUMPIXELS);
      patterns[4].aze(2, false);
      patterns[5].setLocation(0, NUMPIXELS);
      patterns[5].aze(2, true);
      break;
    }
    digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
  }
}
