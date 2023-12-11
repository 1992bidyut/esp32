// https://www.youtube.com/watch?v=Xz73S-mrv3Y
// https://randomnerdtutorials.com/installing-the-esp32-board-in-arduino-ide-mac-and-linux-instructions/
// https://randomnerdtutorials.com/esp32-adc-analog-read-arduino-ide/#:~:text=Reading%20an%20analog%20input%20with,measurements%20in%2018%20different%20channels.
// https://github.com/Bodmer/TFT_eSPI

#include <SPI.h>
#include <TFT_eSPI.h>       // Hardware-specific library
#include <EEPROM.h>

#include "NotoSansBold15.h"
#include "NotoSansBold36.h"

// The font names are arrays references, thus must NOT be in quotes ""
#define AA_FONT_SMALL NotoSansBold15
#define AA_FONT_LARGE NotoSansBold36
// EEPROM SIZE
#define EEPROM_SIZE 1

TFT_eSPI tft = TFT_eSPI();
const int adcPin = 34;       // Pin for the ADC input
bool trigger = false;
int potValue = 0;
int small_value = 0;

void setup(void) {
  Serial.begin(115200);
  tft.begin();
  tft.setRotation(0);
  EEPROM.begin(512);
  // for(int i=0;i<=512;i++){
  //  EEPROM.write(i,'\0');
  //  EEPROM.commit();
  //  delay(10);
  // }
  display_meter_value();
}

void loop() {
   potValue = analogRead(adcPin);
  if(potValue>3000 && trigger == false ){
    Serial.println("Pulse UP");
    Serial.println(potValue);
    trigger = true;
    small_value = EEPROM.read(0);
    if(small_value<9){
      small_value++;
      EEPROM.write(0, small_value);
      EEPROM.commit();
    }else{
      EEPROM.write(0, 0);
      EEPROM.commit();
    }
    update_meter();
    display_meter_value();
  }else if(potValue<3000 && trigger == true ){
    Serial.println("Pulse DOWN");
    Serial.println(potValue);
    trigger = false;
  }
}

void update_meter(){
  for(int i = 1; i<6; i++){
    Serial.println(i);
    int previous_value = EEPROM.read(i-1);
    if(previous_value == 0 && check_previous(i)){
      int current_value = EEPROM.read(i);
      if(current_value<9){
        current_value++;
        EEPROM.write(i, current_value);
        EEPROM.commit();
      }else{
        EEPROM.write(i, 0);
        EEPROM.commit();
      }
    }
  }
}

bool check_previous(int index){
  for(int i =0; i<index; i++){
    if(EEPROM.read(i)!=0) return false;
  }
  return true;
}

void display_meter_value(){
  Serial.println("Loading value");
  tft.fillScreen(TFT_BLACK);//screen background
  tft.setCursor(2, 10); // Set cursor at top left of screen
  tft.loadFont(AA_FONT_LARGE);    // Must load the font first
  // N5
  tft.setTextColor(TFT_WHITE, TFT_BLUE, true);
  tft.print(EEPROM.read(5));
  // N4
  tft.setTextColor(TFT_WHITE, TFT_BLUE, true);
  tft.print(EEPROM.read(4));
  // N3
  tft.setTextColor(TFT_WHITE, TFT_BLUE, true);
  tft.print(EEPROM.read(3));
  // N2
  tft.setTextColor(TFT_WHITE, TFT_BLUE, true);
  tft.print(EEPROM.read(2));
  // N1
  tft.setTextColor(TFT_WHITE, TFT_BLUE, true);
  tft.print(EEPROM.read(1));
  // N0
  tft.setTextColor(TFT_WHITE, TFT_BLUE, true);
  tft.print(EEPROM.read(0));

  tft.loadFont(AA_FONT_SMALL);    // Must load the font first
  tft.setCursor(2, 40); // Set cursor at top left of screen
  tft.setTextColor(TFT_WHITE, TFT_BLACK, true);
  tft.println("");
  tft.println("Divine IT");
  tft.unloadFont();
}
