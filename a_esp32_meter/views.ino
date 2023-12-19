
#include "portal/templates/html_index.h"
#include "portal/templates/htm_meter_config.h"
#include "portal/templates/html_wifi_config.h"
#include "portal/templates/warning.h"
#include "portal/templates/success.h"

    // <div class="container">
    //   <div class="meter-section">
    //     <h1>WASA Digital Meter</h1>
    //     <h2>Meter Reading</h2>
    //     %MAINREADING%
    //   </div>
    //   <div class="button-container">
    //     <button onClick="wifi_config()" id="wifi_config">Connect WiFi</button>
    //     <button onclick="meter_config()" id="meter_config">
    //       Set Meter Reading
    //     </button>
    //   </div>
    // </div>

String meter_processor(const String& var){
  //Serial.println(var);
  if(var == "INDEX_0"){
    String meter = String(EEPROM.read(0));
    return meter;
  }
  return String();
}

void indexView(){
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/html", html_index);
  });
}

void meterConfigView(){
  server.on("/meter_config", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/html", htm_meter_config);
  });
}

void wifiConfigView(){
  server.on("/wifi_config", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/html", html_wifi_config);
  });
}

const char* VALUE_5 = "VALUE_5";
const char* VALUE_4 = "VALUE_4";
const char* VALUE_3 = "VALUE_3";
const char* VALUE_2 = "VALUE_2";
const char* VALUE_1 = "VALUE_1";
const char* VALUE_0 = "VALUE_0";

void onMeterConfigGet(){
  server.on("/get_meter_config", HTTP_GET, [] (AsyncWebServerRequest *request) {
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
      delay(1000);
      request->send(200, "text/html", html_index);
    }else{
       request->send(200, "text/html", warning);
    }
  });
}


const char* form_ssid = "form_ssid";
const char* form_password = "form_password";
void onWifiConfigGet(){
  server.on("/get_wifi_config", HTTP_GET, [] (AsyncWebServerRequest *request) {
    String data_ssid, data_password;
    if (
      request->hasParam(form_ssid)
      && request->hasParam(form_password) 
      ) {
      data_ssid = request->getParam(form_ssid)->value();
      data_password = request->getParam(form_password)->value();

      writeROMString(20, data_ssid);
      writeROMString(41, data_password);
      EEPROM.write(10, 44);
      EEPROM.commit();
      delay(100);
      bool connect = connect_wifi();
      if(connect == true){
        display_meter_value();
        request->send(200, "text/html", success);
        delay(1000);
        request->send(200, "text/html", html_index);
      }else{
        display_meter_value();
        request->send(200, "text/html", warning);
      }
    }else{
      display_meter_value();
       request->send(200, "text/html", warning);
    }
    
  });
}

void getMeterReadingView(){
  server.on("/get_meter_reading", HTTP_GET, [](AsyncWebServerRequest *request){
    
    const int capacity = JSON_OBJECT_SIZE(128);
    StaticJsonDocument<capacity> response_doc;
    JsonObject response_obj = response_doc.to<JsonObject>();
    response_obj["water"] = water_area();
    for(int i=5; i>=0; i--){
      response_obj["index_"+String(i)] = EEPROM.read(i);
    }
    char jsonChar[200];
    serializeJson(response_doc, jsonChar);

    DefaultHeaders::Instance().addHeader("Access-Control-Allow-Origin", "*");
    DefaultHeaders::Instance().addHeader("Access-Control-Allow-Methods", "GET, POST, PUT");
    DefaultHeaders::Instance().addHeader("Access-Control-Allow-Headers", "Content-Type");
    request->send_P(200, "application/json", jsonChar);
  });
}
