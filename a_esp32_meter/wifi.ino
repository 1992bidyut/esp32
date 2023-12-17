const char* ssid = "PrismFi";
const char* password = "prismerp@1";
// const char* ssid = "Bidyut";
// const char* password = "bidyutwifi";
void connect_wifi(){
  WiFi.begin(ssid, password);
  while(WiFi.status() != WL_CONNECTED) {
    displage_massage("Connecting.....");
    delay(500);
  }
  IPAddress ipAddress(WiFi.localIP());
  String CONNECTED_SSID(ssid);
  displage_massage("Wifi Connected!\nSSID: "+CONNECTED_SSID+"\nIP:"+ toString(ipAddress));
  Serial.println(WiFi.localIP());
}

String toString(IPAddress& ip) { // IP v4 only
  String ips;
  ips.reserve(16);
  ips = ip[0];  ips += ':';
  ips += ip[1]; ips += ':';
  ips += ip[2]; ips += ':';
  ips += ip[3];
  return ips;
}