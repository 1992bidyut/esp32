// const char* ssid = "PrismFi";
// const char* password = "prismerp@1";
// const char* ssid = "Bidyut";
// const char* password = "bidyutwifi";
bool connect_wifi(){
  String ssid=readROMString(20);
  String pass=readROMString(41);
  Serial.println(ssid);
  Serial.println(pass);

  WiFi.begin(ssid, pass);
  int count = 0;
  while(WiFi.status() != WL_CONNECTED && count<10) {
    displage_massage("Connecting to Wifi.....");
    delay(500);
    count ++;
    yield();
  }

  if(count >= 10){
    displage_massage("Can not connect to the WiFi! \n\nMaybe SSID or Password error!");
    delay(2000);
    return false;
  }else{
    IPAddress ipAddress(WiFi.localIP());
    String CONNECTED_SSID(ssid);
    displage_massage("Wifi Connected!\n\nSSID: "+CONNECTED_SSID+"\n\nIP:"+ toString(ipAddress));
    delay(3000);
    return true;
  }
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

// DEFAULT AP CONFIG
const char* ap_ssid     = "WASA-Meter";
const char* ap_password = "admin@1234";
IPAddress local_ip(192,168,1,1);
IPAddress gateway(8,8,8,8);
IPAddress subnet(255,255,255,0);

void create_ap(){
  displage_massage("Creatting Access Point.....");
  delay(1000);
  WiFi.softAP(ap_ssid, ap_password);
  WiFi.softAPConfig(local_ip, gateway, subnet);
  IPAddress IP = WiFi.softAPIP();
  IPAddress soft_ip(WiFi.softAPIP());
  String AP_SSID(ap_ssid);
  displage_massage("Access Point Created!\n\nAP_SSID: "+AP_SSID+"\n\nIP:"+ toString(soft_ip));
  delay(3000);
}