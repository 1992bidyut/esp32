void run_server(){
  // Route for root / web page
  indexView();
  onConfigGet();
  // Start server
  server.begin();
  yield();
}