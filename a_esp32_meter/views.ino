
#include "portal/templates/html_index.h"
#include "portal/templates/warning.h"
#include "portal/templates/success.h"
void indexView(){
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/html", html_index);
  });
}

const char* VALUE_5 = "VALUE_5";
const char* VALUE_4 = "VALUE_4";
const char* VALUE_3 = "VALUE_3";
const char* VALUE_2 = "VALUE_2";
const char* VALUE_1 = "VALUE_1";
const char* VALUE_0 = "VALUE_0";

void onConfigGet(){
  server.on("/get", HTTP_GET, [] (AsyncWebServerRequest *request) {
    Serial.println("GET found!");
    Serial.println(request->hasParam(VALUE_5));
   String main_reading;
    String data_5, data_4, data_3, data_2, data_1, data_0;
    if (
      request->hasParam(VALUE_5)
      && request->hasParam(VALUE_4) 
      && request->hasParam(VALUE_3)
      && request->hasParam(VALUE_2)
      && request->hasParam(VALUE_1)
      && request->hasParam(VALUE_0)
      ) {
      data_5 = request->getParam(VALUE_5)->value();
      data_4 = request->getParam(VALUE_4)->value();
      data_3 = request->getParam(VALUE_3)->value();
      data_2 = request->getParam(VALUE_2)->value();
      data_1 = request->getParam(VALUE_1)->value();
      data_0 = request->getParam(VALUE_0)->value();
      EEPROM.write(5, data_5.toInt());
      EEPROM.write(4, data_4.toInt());
      EEPROM.write(3, data_3.toInt());
      EEPROM.write(2, data_2.toInt());
      EEPROM.write(1, data_1.toInt());
      EEPROM.write(0, data_0.toInt());
      EEPROM.commit();
      display_meter_value();
      request->send(200, "text/html", success);
    }else{
       request->send(200, "text/html", warning);
    }
  });
}
