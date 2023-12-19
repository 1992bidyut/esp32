void run_server(){
  // Route for root / web page
  indexView();
 
  wifiConfigView();
  onWifiConfigGet();

  meterConfigView();
  onMeterConfigGet();
  getMeterReadingView();

  // Start server
  server.begin();
  yield();
}