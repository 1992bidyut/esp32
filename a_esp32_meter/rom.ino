// NOTE for memory allocation
// # ROM index 0  to 9 used for meter reading operation

// # ROM index 10 to 19 reserved for flags
// >  if ROM index[10]=44 then device will connect to the wifi and the config will came from ROM
// >  if ROM index[10]=0 then device will not connect to the wifi

// # ROM index 20 to 62 reserved for WIFI config
// > index 20 to 40 for SSID[max ssid character length 20] last index will be stored '\n' for identify the ssid termination point
// > index 41 to 62 for password[max password character length 20] last index will be stored '\n' for identify the password termination point
#define EEPROM_SIZE 1

// must read the mamory allocation note from above, then code
void reset_rom(){
  for(int i=0;i<=512;i++){
   EEPROM.write(i,'\0');
   EEPROM.commit();
   delay(10);
  }
}

// must read the mamory allocation note from above, then code
void writeROMString(char index, String data)
{
  int _size = data.length();
  int i;
  for(i=0;i<_size;i++)
  {
    EEPROM.write(index+i,data[i]);
  }
  EEPROM.write(index+_size,'\0');   //Add termination null character for String Data
  EEPROM.commit();
}

// must read the mamory allocation note from above, then code
String readROMString(char index)
{
  int i;
  char data[100]; //Max 100 Bytes
  int len=0;
  unsigned char k;
  k=EEPROM.read(index);
  while(k != '\0' && len<500)   //Read until null character
  {
    k=EEPROM.read(index+len);
    data[len]=k;
    len++;
  }
  data[len]='\0';
  return String(data);
}