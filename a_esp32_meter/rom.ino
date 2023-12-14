void reset_rom(){
  for(int i=0;i<=512;i++){
   EEPROM.write(i,'\0');
   EEPROM.commit();
   delay(10);
  }
}