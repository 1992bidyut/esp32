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
// The font names are arrays references, thus must NOT be in quotes ""
#define AA_FONT_SMALL NotoSansBold15
#define AA_FONT_LARGE NotoSansBold36
#include <TFT_eSPI.h>       // Hardware-specific library
TFT_eSPI tft = TFT_eSPI();


//##### Common Configs
const int adcPin = 34;       // Pin for the ADC input
bool trigger = false;
int potValue = 0;
int small_value = 0;

void setup(void) {
  Serial.begin(115200);
  tft.begin();
  tft.setRotation(0);
  EEPROM.begin(512);
  // reset_rom();
  display_meter_value();
  connect_wifi();
}

void loop() {
   potValue = analogRead(adcPin);
  if(potValue>1000 && trigger == false ){
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
    String httpRequestData = "api_key=" + apiKey + "&field1=" + String(read_meter())+ "&field2=1"+ "&field3=" + String(water_area()); 
    post_data(httpRequestData);
  }else if(potValue<1000 && trigger == true ){
    Serial.println("Pulse DOWN");
    Serial.println(potValue);
    trigger = false;
    String httpRequestData = "api_key=" + apiKey + "&field1=" + String(read_meter())+ "&field2=0"+ "&field3=" + String(water_area()); 
    post_data(httpRequestData);
  }
}

int read_meter(){
  String reading = "";
   for(int i=5; i>=0; i--){
    reading = reading + String(EEPROM.read(i));
  }
  Serial.print("reading: ");
  Serial.println(reading);
  return reading.toInt();
}

float water_area(){
  return read_meter()*0.166;
}

void reset_rom(){
  for(int i=0;i<=512;i++){
   EEPROM.write(i,'\0');
   EEPROM.commit();
   delay(10);
  }
}

void connect_wifi(){
  WiFi.begin(ssid, password);
  Serial.println("Connecting");
  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());
  Serial.println("Timer set to 10 seconds (timerDelay variable), it will take 10 seconds before publishing the first reading.");
}

void post_data(String httpRequestData){
  //Check WiFi connection status
    if(WiFi.status()== WL_CONNECTED){
      WiFiClient client;
      HTTPClient http;
      // Your Domain name with URL path or IP address with path
      http.begin(client, serverName);
      // Specify content-type header
      http.addHeader("Content-Type", "application/x-www-form-urlencoded");
      // Data to send with HTTP POST
                
      // Send HTTP POST request
      int httpResponseCode = http.POST(httpRequestData);
      Serial.print("HTTP Response code: ");
      Serial.println(httpResponseCode);
      // Free resources
      http.end();
    }
    else {
      Serial.println("WiFi Disconnected");
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
  tft.print("Water: ");
  tft.print(water_area());
  tft.println(" m3");

  tft.setCursor(2, 70); // Set cursor at top left of screen
  tft.setTextColor(TFT_WHITE, TFT_BLACK, true);
  tft.println("");
  tft.println("Divine IT");
  
  tft.unloadFont();
}


