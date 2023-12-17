// EEPROM SIZE
#define EEPROM_SIZE 1

void reset_rom(){
  for(int i=0;i<=512;i++){
   EEPROM.write(i,'\0');
   EEPROM.commit();
   delay(10);
  }
}