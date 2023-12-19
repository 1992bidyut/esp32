void setup(void) {
  Serial.begin(115200);
  tft.begin();
  tft.setRotation(0);
  EEPROM.begin(512);
  show_divine_logo();
  delay(2000);
  show_wasa_logo();
  delay(2000);
  create_ap();
  if(EEPROM.read(10) == 44){
    connect_wifi();
  }
  display_meter_value();
  run_server();
  yield();
}