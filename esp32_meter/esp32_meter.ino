// https://www.youtube.com/watch?v=Xz73S-mrv3Y
// https://randomnerdtutorials.com/installing-the-esp32-board-in-arduino-ide-mac-and-linux-instructions/
// https://randomnerdtutorials.com/esp32-adc-analog-read-arduino-ide/#:~:text=Reading%20an%20analog%20input%20with,measurements%20in%2018%20different%20channels.
// https://github.com/Bodmer/TFT_eSPI

const int adcPin = 34;       // Pin for the ADC input
bool trigger = false;
int potValue = 0;

void setup() {
  Serial.begin(115200);
  delay(1000);
}

void loop() {
  // Reading potentiometer value
  potValue = analogRead(adcPin);
  if(potValue>3000 && trigger == false ){
    Serial.println("Pulse UP");
    Serial.println(potValue);
    trigger = true;
  }else if(potValue<3000 && trigger == true ){
    Serial.println("Pulse DOWN");
    Serial.println(potValue);
    trigger = false;
  }
}