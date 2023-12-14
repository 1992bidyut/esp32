// https://www.youtube.com/watch?v=Xz73S-mrv3Y
// https://randomnerdtutorials.com/installing-the-esp32-board-in-arduino-ide-mac-and-linux-instructions/
// https://randomnerdtutorials.com/esp32-adc-analog-read-arduino-ide/#:~:text=Reading%20an%20analog%20input%20with,measurements%20in%2018%20different%20channels.
// https://github.com/Bodmer/TFT_eSPI
// https://randomnerdtutorials.com/esp32-http-post-ifttt-thingspeak-arduino/

// #####EEPROM Configs
#include <EEPROM.h>
// EEPROM SIZE
#define EEPROM_SIZE 1

//##### WiFi config
#include <WiFi.h>
#include <HTTPClient.h>
const char* ssid = "PrismFi";
const char* password = "prismerp@1";
const char* serverName = "http://api.thingspeak.com/update";
String apiKey = "JKAYNH65NV6F2HNP";
unsigned long lastTime = 0;
// Set timer to 10 minutes (600000)
//unsigned long timerDelay = 600000;
// Timer set to 10 seconds (10000)
unsigned long timerDelay = 10000;

//##### Display Config
#include <SPI.h>
#include "NotoSansBold15.h"
#include "NotoSansBold36.h"
#include <TFT_eSPI.h>       // Hardware-specific library
// JPEG decoder library
#include <JPEGDecoder.h>
TFT_eSPI tft = TFT_eSPI();
#include "divine_logo.h"
#include "wasa_logo.h"
// The font names are arrays references, thus must NOT be in quotes ""
#define AA_FONT_SMALL NotoSansBold15
#define AA_FONT_LARGE NotoSansBold36

//##### Common Configs
const int adcPin = 34;       // Pin for the ADC input
bool trigger = false;
int potValue = 0;
int small_value = 0;


