void SyncScreen() {
  lcd.clear();

  //Synchronizing-skærm
  lcd.setCursor(3, 1);
  lcd.print("SYNKRONISERER");

  lcd.setCursor(0, 2);
  lcd.print("pumpe1  end   pumpe2");
  lcd.setCursor(0, 3);
  lcd.print(" '7'    'C'     '9' ");

  
  pump1_enable = false;
  pump2_enable = false;
  digitalWrite(pump1, pump1_enable);
  digitalWrite(pump2, pump1_enable);

  //Styr pumperne efter behov så slangerne fyldes helt op
  //---------------------------------------------------------------------------------------
  while (true) {
    key = keypad.getKey();
    if (key != NO_KEY) {

      //Forlad SyncScreen og sluk begge pumper
      if (key == 'C') {
        digitalWrite(pump1, LOW);
        digitalWrite(pump2, LOW);
        return;
      }

      //Sluk/tænd pumpe 1
      if (key == '7') {
        pump1_enable = !pump1_enable;
        digitalWrite(pump1, pump1_enable);
      }

      //Sluk/tænd pumpe 2
      if (key == '9') {
        pump2_enable = !pump2_enable;
        digitalWrite(pump2, pump2_enable);
      }
    }
  }
  //---------------------------------------------------------------------------------------
}
