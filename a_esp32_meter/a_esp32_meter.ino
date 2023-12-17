//  ####### Supportive Turorials and Documentation ##########
// https://www.youtube.com/watch?v=Xz73S-mrv3Y
// https://randomnerdtutorials.com/installing-the-esp32-board-in-arduino-ide-mac-and-linux-instructions/
// https://randomnerdtutorials.com/esp32-adc-analog-read-arduino-ide/#:~:text=Reading%20an%20analog%20input%20with,measurements%20in%2018%20different%20channels.
// https://github.com/Bodmer/TFT_eSPI
// https://randomnerdtutorials.com/esp32-http-post-ifttt-thingspeak-arduino/
// https://randomnerdtutorials.com/esp32-async-web-server-espasyncwebserver-library/
//##### Common Configs
#include <WiFi.h>
#include <EEPROM.h>
#include <HTTPClient.h>
#include <SPI.h>
#include "NotoSansBold15.h"
#include "NotoSansBold36.h"
#include <TFT_eSPI.h>       // Hardware-specific library
// JPEG decoder library
#include <JPEGDecoder.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
const int adcPin = 34;       // Pin for the ADC input
bool trigger = true;
int potValue = 0;
int small_value = 0;
AsyncWebServer server(80);


