/* https://www.diyengineers.com/2022/06/02/lidar-how-to-use-with-arduino/
 v1 - changes by Nicu FLORICA (niq_ro) to show info on i2c LCD1602
*/

#include <Arduino.h>
#include <Wire.h>        // Instantiate the Wire library
#include <TFLI2C.h>      // TFLuna-I2C Library v.0.1.1
#include <LiquidCrystal_I2C.h> 

TFLI2C tflI2C;
LiquidCrystal_I2C lcd(0x27, 16, 2);  // // Set the LCD address to 0c3F (or 0x27) for a 16 chars and 2 line display

int16_t  tfDist;    // distance in centimeters
int16_t  tfAddr = TFL_DEF_ADR;  // Use this default I2C address
int dist, dist1, dist2,dist3;

void setup(){
    Serial.begin(115200);  // Initalize serial port
    Wire.begin();           // Initalize Wire library
    lcd.begin();  // initialize the LCD
    //lcd.init(); // switch if lcd.begin not work
  lcd.clear();  // clear the screen
  lcd.backlight();  // Turn on the blacklight
  lcd.setCursor(0,0); 
  lcd.print("TF-Luna distance");  
  lcd.setCursor(0,1); 
  lcd.print("v.1.0 by niq_ro "); 
  delay(3000);
  lcd.clear(); 
}

void loop(){
    tflI2C.getData(tfDist, tfAddr);
    Serial.println(String(tfDist)+" cm / " + String(tfDist/2.54)+" inches");
    dist1 = tfDist/10;
    dist2 = tfDist%10/10;
    dist3 = tfDist%10%10;
    lcd.setCursor(0,0); 
    lcd.print("TF-Luna distance");  
    lcd.setCursor(6,1);
    if (dist1 == 0) 
      lcd.print(" ");  
      else
      lcd.print(dist1);
    if ((dist1 == 0) and (dist2 == 0)) 
      lcd.print(" ");  
      else
      lcd.print(dist2);
    lcd.print(dist3);
    lcd.print(" cm ");
    delay(500);
} // end main loop
