/* https://www.diyengineers.com/2022/06/02/lidar-how-to-use-with-arduino/
 * changes by Nicu FLORICA (niq_ro)
 * v.1 - added TM1637 display
*/

#include <Arduino.h>
#include <Wire.h>        // Instantiate the Wire library
#include <TFLI2C.h>      // TFLuna-I2C Library v.0.1.1
#include <TM1637Display.h>  // https://github.com/avishorp/TM1637

// Module connection pins (Digital Pins)
#define CLK 2
#define DIO 3

TFLI2C tflI2C;
TM1637Display display(CLK, DIO);

int16_t  tfDist;    // distance in centimeters
int16_t  tfAddr = TFL_DEF_ADR;  // Use this default I2C address

int dist, dist1, dist2, dist3, k;

void setup(){
    Serial.begin(115200);  // Initalize serial port
    Wire.begin();           // Initalize Wire library
    display.setBrightness(2); // 0...15
   // display.showNumberDecEx(dist, (0x80 >> k%2), true); 
}

void loop(){
  
    if(tflI2C.getData(tfDist, tfAddr)){
        Serial.println(String(tfDist)+" cm / " + String(tfDist/2.54)+" inches");
       // display.showNumberDecEx(tfDist, (0x80 >> k%2), true);
        display.showNumberDec(tfDist, false); // Expect: _301 
    }
    delay(500);
}
