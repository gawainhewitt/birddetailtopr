
#include <LovyanGFX.hpp>
#include "lgfx_setup.h"
#include "stewartImages.h"

#define Screen1_CS 21 
#define Screen2_CS 22

#define SCREENOFF 1
#define SCREENON 0

#define BLACK 0x0000
#define ORANGE 0xE4E0
#define SKYBLUE 0x55BD
#define BLUISHGREEN 0x04EE
#define YELLOW 0xF728
#define BLUE 0x0396
#define VERMILLION 0xD2E0
#define REDDISHPURPLE 0xCBD4

LGFX tft;
LGFX_Sprite spr(&tft);

void setup(void)
{
  tft.init();

  Serial.begin(250000);

  pinMode(Screen1_CS, OUTPUT);
  pinMode(Screen2_CS, OUTPUT);

  tft.begin();

  tft.setRotation(0);

  spr.setColorDepth(16); // 16 bit colour needed to show antialiased fonts

  tft.fillScreen(REDDISHPURPLE);
}

void loop(void)
{
  int width = tft.width(); 
  int height = tft.height();
  int waitTime = 4500;

  for(int i = 0; i < 4; i++) {

    spr.createSprite(width -1, height -1);   // Create a sprite - must be smaller than the screen size? certainly not working on the drawing unless smaller

    spr.drawBitmap(0, 0, epd_bitmap_allArray[i], 239, 239, ORANGE);

    digitalWrite(Screen1_CS, SCREENON);
    digitalWrite(Screen2_CS, SCREENON);

    spr.pushSprite(0, 0);         // Push to TFT screen coord x, y

    spr.deleteSprite(); // Recover memory

    delay(waitTime);
  }
  
}
