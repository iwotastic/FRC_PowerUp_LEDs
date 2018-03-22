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
#define COM_READ int(uint8_t(COM.read()))

#endif

Pattern patterns[numarrays];

Adafruit_DotStar strip1 = Adafruit_DotStar(NUMPIXELS, DATAPIN1, CLOCKPIN1, DOTSTAR_BGR);
Adafruit_DotStar strip2 = Adafruit_DotStar(NUMPIXELS, DATAPIN2, CLOCKPIN2, DOTSTAR_BGR);
Adafruit_DotStar strip3 = Adafruit_DotStar(NUMPIXELS, DATAPIN3, CLOCKPIN3, DOTSTAR_BGR);
Adafruit_DotStar strip4 = Adafruit_DotStar(NUMPIXELS, DATAPIN4, CLOCKPIN4, DOTSTAR_BGR);
Adafruit_DotStar strip5 = Adafruit_DotStar(NUMPIXELS, DATAPIN5, CLOCKPIN5, DOTSTAR_BGR);
Adafruit_DotStar strip6 = Adafruit_DotStar(NUMPIXELS, DATAPIN6, CLOCKPIN6, DOTSTAR_BGR);
Adafruit_DotStar strip7 = Adafruit_DotStar(NUMPIXELS, DATAPIN7, CLOCKPIN7, DOTSTAR_BGR);
Adafruit_DotStar strip8 = Adafruit_DotStar(NUMPIXELS, DATAPIN8, CLOCKPIN8, DOTSTAR_BGR);

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
  strip7.begin(); 
  strip7.show();
  strip8.begin(); 
  strip8.show();

  pinMode(LED_BUILTIN, OUTPUT);

  COM.SETUP;

  patterns[0].setStrip(&strip1);
  patterns[1].setStrip(&strip2);
  patterns[2].setStrip(&strip3);
  patterns[3].setStrip(&strip4);
  patterns[4].setStrip(&strip5);
  patterns[5].setStrip(&strip6);
  patterns[6].setStrip(&strip7);
  patterns[7].setStrip(&strip8);

  patterns[0].setLocation(0, NUMPIXELS);
  patterns[0].aze(6, false);
  patterns[1].setLocation(0, NUMPIXELS);
  patterns[1].aze(2, true);
  patterns[2].setLocation(0, NUMPIXELS);
  patterns[2].aze(2, false);
  patterns[3].setLocation(0, NUMPIXELS);
  patterns[3].aze(6, false);
  patterns[4].setLocation(0, NUMPIXELS);
  patterns[4].aze(6, false);
  patterns[5].setLocation(0, NUMPIXELS);
  patterns[5].aze(2, true);
  patterns[6].setLocation(0, NUMPIXELS);
  patterns[6].aze(2, false);
  patterns[7].setLocation(0, NUMPIXELS);
  patterns[7].aze(6, false);
}

void loop() {
  for (int i = 0; i < numarrays; i++) {
    patterns[i].setPixels();
  }
  strip1.show();
  strip2.show();
  strip3.show();
  strip4.show();
  if (COM.available() > 0) {
    int code = COM_READ;
    switch (code) {
      case 8:
      patterns[0].setLocation(0, NUMPIXELS);
      patterns[0].scroll(0xff0000, 0x000000, 44, false);
      patterns[1].setLocation(0, NUMPIXELS);
      patterns[1].scroll(0xff0000, 0x000000, 4, false);
      patterns[2].setLocation(0, NUMPIXELS);
      patterns[2].scroll(0xff0000, 0x000000, 4, true);
      patterns[3].setLocation(0, NUMPIXELS);
      patterns[3].scroll(0xff0000, 0x000000, 44, false);
      break;
      case 7:
      patterns[0].setLocation(0, NUMPIXELS);
      patterns[0].scroll(0xff00ff, 0xff7f00, 4, true);
      patterns[1].setLocation(0, NUMPIXELS);
      patterns[1].flash(0xff00ff, 0xff7f00, 100);
      patterns[2].setLocation(0, NUMPIXELS);
      patterns[2].flash(0xff00ff, 0xff7f00, 100);
      patterns[3].setLocation(0, NUMPIXELS);
      patterns[3].scroll(0xff00ff, 0xff7f00, 4, true);
      break;
      case 6:
      patterns[0].setLocation(0, NUMPIXELS);
      patterns[0].scroll(0xffff00, 0xff0000, 4, false);
      patterns[1].setLocation(0, NUMPIXELS);
      patterns[1].flash(0xffff00, 0xff0000, 100);
      patterns[2].setLocation(0, NUMPIXELS);
      patterns[2].flash(0xffff00, 0xff0000, 100);
      patterns[3].setLocation(0, NUMPIXELS);
      patterns[3].scroll(0xffff00, 0xff0000, 4, false);
      break;
      case 5:
      patterns[0].setLocation(0, NUMPIXELS);
      patterns[0].scroll(0xffff00, 0xff7f00, 4, false);
      patterns[1].setLocation(0, NUMPIXELS);
      patterns[1].flash(0xffff00, 0xff7f00, 100);
      patterns[2].setLocation(0, NUMPIXELS);
      patterns[2].flash(0xffff00, 0xff7f00, 100);
      patterns[3].setLocation(0, NUMPIXELS);
      patterns[3].scroll(0xffff00, 0xff7f00, 4, false);
      break;
      case 4:
      patterns[0].setLocation(0, NUMPIXELS);
      patterns[0].scroll(0xffff00, 0x00ff00, 4, false);
      patterns[1].setLocation(0, NUMPIXELS);
      patterns[1].flash(0xffff00, 0x00ff00, 100);
      patterns[2].setLocation(0, NUMPIXELS);
      patterns[2].flash(0xffff00, 0x00ff00, 100);
      patterns[3].setLocation(0, NUMPIXELS);
      patterns[3].scroll(0xffff00, 0x00ff00, 4, false);
      break;
      case 3:
      patterns[0].setLocation(0, NUMPIXELS);
      patterns[0].scroll(0xffff00, 0x000000, 4, false);
      patterns[1].setLocation(0, NUMPIXELS);
      patterns[1].flash(0xffff00, 0x000000, 100);
      patterns[2].setLocation(0, NUMPIXELS);
      patterns[2].flash(0xffff00, 0x000000, 100);
      patterns[3].setLocation(0, NUMPIXELS);
      patterns[3].scroll(0xffff00, 0x000000, 4, false);
      break;
      case 2:
      patterns[0].setLocation(0, NUMPIXELS);
      patterns[0].scroll(0x0000ff, 0x000000, 44, false);
      patterns[1].setLocation(0, NUMPIXELS);
      patterns[1].scroll(0x0000ff, 0x000000, 4, false);
      patterns[2].setLocation(0, NUMPIXELS);
      patterns[2].scroll(0x0000ff, 0x000000, 4, true);
      patterns[3].setLocation(0, NUMPIXELS);
      patterns[3].scroll(0x0000ff, 0x000000, 44, false);
      break;
      case 1:
      patterns[0].setLocation(0, NUMPIXELS);
      patterns[0].aze(6, false);
      patterns[1].setLocation(0, NUMPIXELS);
      patterns[1].aze(2, true);
      patterns[2].setLocation(0, NUMPIXELS);
      patterns[2].aze(2, false);
      patterns[3].setLocation(0, NUMPIXELS);
      patterns[3].aze(6, false);
      break;
      default:
      patterns[0].setLocation(0, NUMPIXELS);
      patterns[0].aze(6, false);
      patterns[1].setLocation(0, NUMPIXELS);
      patterns[1].aze(2, true);
      patterns[2].setLocation(0, NUMPIXELS);
      patterns[2].aze(2, false);
      patterns[3].setLocation(0, NUMPIXELS);
      patterns[3].aze(6, false);
        patterns[4].setLocation(0, NUMPIXELS);
  patterns[4].aze(6, false);
  patterns[5].setLocation(0, NUMPIXELS);
  patterns[5].aze(2, true);
  patterns[6].setLocation(0, NUMPIXELS);
  patterns[6].aze(2, false);
  patterns[7].setLocation(0, NUMPIXELS);
  patterns[7].aze(6, false);
//      patterns[0].setLocation(0, NUMPIXELS);
//      patterns[0].goBlack();
//      patterns[1].setLocation(0, NUMPIXELS);
//      patterns[1].goBlack();
//      patterns[2].setLocation(0, NUMPIXELS);
//      patterns[2].goBlack();
//      patterns[3].setLocation(0, NUMPIXELS);
//      patterns[3].goBlack();
      break;
    }
    digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
  }
}
