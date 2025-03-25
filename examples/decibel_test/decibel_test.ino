//    FILE: decibel_test.ino
//  AUTHOR: Rob Tillaart
// PURPOSE: explore
//     URL: https://github.com/RobTillaart/decibel

#include "decibel.h"

uint32_t start, stop;


volatile float a = -5.0;
float x;

void setup()
{
  Serial.begin(115200);
  while (!Serial);
  Serial.println(__FILE__);
  delay(100);

  start = micros();
  x = decibel(-a);
  stop = micros();
  Serial.print("TIME:\t");
  Serial.println(stop - start);
  Serial.print("VAL:\t");
  Serial.println(x, 6);
  delay(100);

  start = micros();
  x = decibel(-0.0);
  stop = micros();
  Serial.print("TIME:\t");
  Serial.println(stop - start);
  Serial.print("VAL:\t");
  Serial.println(x, 6);
  delay(100);

  start = micros();
  x = decibel(a);
  stop = micros();
  Serial.print("TIME:\t");
  Serial.println(stop - start);
  Serial.print("VAL:\t");
  Serial.println(x, 6);
  delay(100);

  start = micros();
  x = decibelFast(a);
  stop = micros();
  Serial.print("TIME:\t");
  Serial.println(stop - start);
  Serial.print("DBFAST:\t");
  Serial.println(x, 6);
  delay(100);

  x = decibel(a);
  start = micros();
  float y = inverseDecibel(x);
  stop = micros();
  Serial.print("TIME:\t");
  Serial.println(stop - start);
  Serial.print("INVDB:\t");
  Serial.println(a, 6);
  Serial.println(x, 6);
  Serial.println(y, 6);
  delay(100);

}

void loop()
{


}

// -- END OF FILE --
