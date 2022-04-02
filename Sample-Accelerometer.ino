/* Copyright © JenTronic */

#include <Wire.h>
#include <U8g2lib.h>

#define ADDRESS 0x68  // IIC adressen for MPU6050

#define SDA D1        // IO port som SDA (MPU6050) er forbundet til
#define SCL D2        // IO port som SCL (MPU6050) er forbundet til

#define DC D4         // IO port som DC (OLED) er forbundet til
#define CS D8         // IO port som CD (OLED) er forbundet til

#define SAMPLES 20    // Antal samples som gennemsnit skal beregnes ud fra

int xSamples [SAMPLES] = {};
int ySamples [SAMPLES] = {};
int i,x,y = 0;
int16_t AcX,AcY;

U8G2_SH1106_128X64_NONAME_1_4W_HW_SPI u8g2(U8G2_R0, CS, DC, U8X8_PIN_NONE);

void UpdateDisplay(int PosX, int PosY) {

  u8g2.firstPage();
  
  do {

    u8g2.drawRFrame(1, 1, 127, 63, 10);
    u8g2.drawDisc(PosX, PosY, 5, U8G2_DRAW_ALL);

    if (PosX < 5 || PosX > 122 || PosY < 5 || PosY > 58) {
      u8g2.setFont(u8g2_font_open_iconic_embedded_4x_t);
      u8g2.drawGlyph(50, 50, 67);  
    }

  } while ( u8g2.nextPage() );

}

void setup(){
  
  Wire.begin(SCL, SDA);
  Wire.beginTransmission(ADDRESS);
  Wire.write(0x6B);                    // Register for strømstyring
  Wire.write(0);                       // Angiv at MPU6050 skal aktiveres
  Wire.endTransmission(true);
  Serial.begin(9600);
  u8g2.begin();
  
}

void loop(){

  Wire.beginTransmission(ADDRESS);
  Wire.write(0x3B);          // Register for accelerometer X-akse high-byte output
  Wire.endTransmission(false);
  Wire.requestFrom(ADDRESS, 4, true);  // Vi udlæser 4 registre
  AcX=Wire.read()<<8|Wire.read();      // 0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L)     
  AcY=Wire.read()<<8|Wire.read();      // 0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L) 

  if (i < SAMPLES) {
    i++;
  } else {
    i = 1;
  }
  
  xSamples[i - 1] = AcX / 50 ;
  ySamples[i - 1] = AcY / 50;

  x = 0;
  y = 0;
  
  for (int j = 1; j <= SAMPLES; j++) {
    x = x + xSamples[j - 1];
    y = y + ySamples[j - 1];
  }

  x = (128 / 2) + (x / SAMPLES);
  y = (64 / 2) + (y / SAMPLES);

  UpdateDisplay(x, y);

  delay(20);
  
}

