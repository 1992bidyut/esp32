void setup(void) {
  Serial.begin(115200);
  tft.begin();
  tft.setRotation(0);
  EEPROM.begin(512);
  show_divine_logo();
  delay(2000);
  show_wasa_logo();
  delay(2000);
  connect_wifi();
  delay(5000);
  display_meter_value();
}