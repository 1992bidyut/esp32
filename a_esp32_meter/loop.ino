void loop() {
  potValue = analogRead(adcPin);
  if(potValue>1000 && trigger == false){
    EEPROM.write(6, 0);
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
    EEPROM.write(6, 5);
    EEPROM.commit();
    Serial.println("Pulse DOWN");
    Serial.println(potValue);
    trigger = false;
    display_meter_value();
    String httpRequestData = "api_key=" + apiKey + "&field1=" + String(read_meter())+ "&field2=0"+ "&field3=" + String(water_area()); 
    post_data(httpRequestData);
  }
  yield();
}