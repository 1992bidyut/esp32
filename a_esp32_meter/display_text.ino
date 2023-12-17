void displage_massage(String msg){
  tft.fillScreen(TFT_BLACK);//screen background
  // tft.loadFont(AA_FONT_SMALL);    // Must load the font first
  tft.setCursor(2, 70); // Set cursor at top left of screen
  tft.setTextColor(TFT_WHITE, TFT_BLACK, true);
  tft.print(msg);
}

void display_meter_value(){
  tft.fillScreen(TFT_SKYBLUE);//screen background
  tft.setCursor(11, 5); // Set cursor at top left of screen
  tft.loadFont(AA_FONT_LARGE);    // Must load the font first
  // N5
  tft.setTextColor(TFT_WHITE, TFT_BLUE, true);
  tft.print(EEPROM.read(5));
  // N4
  tft.setTextColor(TFT_WHITE, TFT_BLUE, true);
  tft.print(EEPROM.read(4));
  // N3
  tft.setTextColor(TFT_WHITE, TFT_BLUE, true);
  tft.print(EEPROM.read(3));
  // N2
  tft.setTextColor(TFT_WHITE, TFT_BLUE, true);
  tft.print(EEPROM.read(2));
  // N1
  tft.setTextColor(TFT_WHITE, TFT_BLUE, true);
  tft.print(EEPROM.read(1));
  // N0
  tft.setCursor(35, 45); // Set cursor at top left of screen
  tft.setTextColor(TFT_WHITE, TFT_DARKGREEN, true);
  tft.setTextPadding(5);
  tft.print(EEPROM.read(0));
  // N6
  tft.setCursor(75, 45); // Set cursor at top left of screen
  tft.setTextColor(TFT_WHITE, TFT_DARKGREEN, true);
  tft.setTextPadding(5);
  tft.print(EEPROM.read(6));
  tft.unloadFont();

    // N0
  tft.setCursor(35, 85); // Set cursor at top left of screen
  tft.setTextColor(TFT_WHITE, TFT_RED, true);
  tft.setTextPadding(5);
  tft.print("x0.1");
  // N6
  tft.setCursor(75, 85); // Set cursor at top left of screen
  tft.setTextColor(TFT_WHITE, TFT_RED, true);
  tft.setTextPadding(5);
  tft.print("x0.01");


  tft.loadFont(AA_FONT_SMALL);    // Must load the font first
  tft.setCursor(5, 80); // Set cursor at top left of screen
  tft.setTextColor(TFT_WHITE, TFT_SKYBLUE, true);
  tft.println("");
  tft.print("Water: ");
  tft.print(water_area());
  tft.println(" m3");
  tft.unloadFont();

  tft.setCursor(5, 130); // Set cursor at top left of screen
  tft.setTextColor(TFT_BLUE, TFT_SKYBLUE, true);
  tft.println("");
  tft.println("-by Divine IT & WASA");
  
  
}