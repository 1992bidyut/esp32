void connect_wifi(){
  WiFi.begin(ssid, password);
  displage_massage("Connecting.");
  while(WiFi.status() != WL_CONNECTED) {
    displage_massage(".");
    delay(500);
  }
  displage_massage("Wifi Connected!");
}