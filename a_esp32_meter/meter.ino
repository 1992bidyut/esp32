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