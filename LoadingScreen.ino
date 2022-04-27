void LoadingBar() {

  uint8_t booziness[] {
    MC_Booziness,
    VRB_Booziness
  };
  //Beregn on-time for hver pumpe
  pump1Time = booziness[chosenDrink - 1] * (millisToLitre * volume / 100) / maxBooziness[chosenDrink - 1];
  pump2Time = (millisToLitre * volume / 100) - pump1Time;

  //find den længste tid og brug den  som reference til loadingbaren
  if (pump1Time > pump2Time) {
    millisToFull = pump1Time;
  }
  else {
    millisToFull = pump2Time;
  }
  
  //Start pumperne
  digitalWrite(pump1, HIGH);
  digitalWrite(pump2, HIGH);
  pump1_enable = true;
  pump2_enable = true;
  
  //Start loadingbar
  //Den fylder en firkant ud, hver gang der er gået en tiendedel af referencetiden
  //---------------------------------------------------------------------------------------
  timestamp = millis();
  for (i = 1; i < 11; i++) {

    //Opdater procenten så længe loadingbaren ikke skal opdateres
    //---------------------------------------------------------------------------------------
    while (millis() - timestamp < i * millisToFull / 10) {
      procent = 100 * (millis() - timestamp) / millisToFull;
      if (i > 1) {
        lcd.setCursor(8, 3);
      }
      else {
        lcd.setCursor(9, 3);
      }
      lcd.print(procent);
      lcd.print("%");

      //Check om en pumpe er færdig
      if (pump1_enable) {
        if (millis() - timestamp >= pump1Time ) {
          digitalWrite(pump1, LOW);
          pump1_enable = false;
        }
      }
      if (pump2_enable) {
        if (millis() - timestamp >= pump2Time) {
          digitalWrite(pump2, LOW);
          pump2_enable = false;
        }
      }
    }
    //---------------------------------------------------------------------------------------

    lcd.setCursor(4 + i, 2);
    lcd.write((byte)7);
  }
  //Stop pumperne
  digitalWrite(pump1, LOW);
  digitalWrite(pump2, LOW);
}

void LoadingScreen() {
  //Alco-flask + Glass
  lcd.setCursor(8, 0);
  lcd.write((byte)0);
  lcd.write((byte)1);
  lcd.write((byte)2);
  lcd.setCursor(10, 1);
  lcd.write((byte)3);

  //Loading Bar
  lcd.setCursor(5, 2);
  lcd.write((byte)4);
  lcd.write((byte)6);
  lcd.write((byte)6);
  lcd.write((byte)6);
  lcd.write((byte)6);
  lcd.write((byte)6);
  lcd.write((byte)6);
  lcd.write((byte)6);
  lcd.write((byte)6);
  lcd.write((byte)5);
}
