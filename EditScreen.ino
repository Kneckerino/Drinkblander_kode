void EditScreen() {
  //Ændr oprindelige til EDIT-skærm
  lcd.setCursor(7, 2);
  lcd.print("(EDIT)");
  lcd.setCursor(9, 3);
  lcd.print("  ");

  //Lav array af alkoholprocenter
  /*Af ukendt årsag kan dette ikke blot deklareres i begyndelsen, men skal opdateres hver gang*/
  uint8_t booziness[] {
    MC_Booziness,
    VRB_Booziness
  };

  //Find cifrene i vores variabler og de tilhørende inverterede versioner
  //---------------------------------------------------------------------------------------
  v_firstDigit = volume % 10;
  v_secondDigit = (volume / 10) % 10;
  UpdateVolume();

  b_firstDigit = booziness[chosenDrink - 1] % 10;
  b_secondDigit = (booziness[chosenDrink - 1] / 10) % 10;
  UpdateBooze();
  //---------------------------------------------------------------------------------------

  timestamp = millis();
  while (true) {
    //Skift mellem invertering og normalitet efter blinkehastighed
    //---------------------------------------------------------------------------------------
    if (millis() - timestamp > blinkSpeed) {
      timestamp += blinkSpeed;
      invCharacters = !invCharacters;
      UpdateVolume();
      UpdateBooze();
    }

    //Bevægelse i interfacet
    //---------------------------------------------------------------------------------------
    key = keypad.getKey();
    if (key != NO_KEY) {

      //Øg værdi af valgt variabel
      if (key == '2') {
        if (editVar && volume < maxVolume) { //Volume
          volume += 2;
          if (volume > maxVolume) {
            volume = maxVolume;
          }
          v_firstDigit = volume % 10;
          v_secondDigit = (volume / 10) % 10;
          UpdateVolume();
        }
        else if (!editVar && booziness[chosenDrink - 1] < maxBooziness[chosenDrink - 1]) { //Booziness for enten Morgan eller Vodka
          booziness[chosenDrink - 1] ++;
          if (booziness[chosenDrink - 1] > maxBooziness[chosenDrink - 1]) {
            booziness[chosenDrink - 1] = maxBooziness[chosenDrink - 1];
          }
          b_firstDigit = booziness[chosenDrink - 1] % 10;
          b_secondDigit = (booziness[chosenDrink - 1] / 10) % 10;
          UpdateBooze();
        }
      }

      //Formindsk værdi af valgt variabel
      if (key == '8') {
        if (editVar && volume > 2) { //Volume
          volume -= 2;
          if (volume < 2) {
            volume = 2;
          }
          v_firstDigit = volume % 10;
          v_secondDigit = (volume / 10) % 10;
          UpdateVolume();
        }
        else if (!editVar && booziness[chosenDrink - 1] > 0) { //Booziness
          booziness[chosenDrink - 1]--;
          if (booziness[chosenDrink - 1] < 0) {
            booziness[chosenDrink - 1] = 0;
          }
          b_firstDigit = booziness[chosenDrink - 1] % 10;
          b_secondDigit = (booziness[chosenDrink - 1] / 10) % 10;
          UpdateBooze();
        }
      }

      //Skift mellem booze og volumen
      if (key == '4' || key == '6') {
        Revert();
        editVar = !editVar;
        if (editVar) {
          UpdateBooze();
        }
        else {
          UpdateVolume();
        }
      }

      //Forlad EDIT-skærmen
      //EEPROM gemmer kun værdierne når EditScreen forlades for at spare på EEPROM's write-begrænsninger
      if (key == 'E') {
        EEPROM.write(volAddress, volume);
        EEPROM.write(boozeAddress[chosenDrink - 1], booziness[chosenDrink - 1]);
        MC_Booziness = EEPROM.read(boozeAddress[0]);
        VRB_Booziness = EEPROM.read(boozeAddress[1]);

        StandardChars();
        return;
      }
    }
  }
}

void UpdateBooze() {
  if (invCharacters & !editVar) {
    FindInvChars(b_firstDigit, b_secondDigit);
    lcd.setCursor(2, 3);
    if (b_secondDigit > 0) {
      lcd.write((byte)1);
    }
    else {
      lcd.print(" ");
    }
    lcd.write((byte)0);
  }
  else {
    lcd.setCursor(2, 3);
    if (b_secondDigit > 0) {
      lcd.print(b_secondDigit);
    }
    else {
      lcd.print(" ");
    }
    lcd.print(b_firstDigit);
  }
}

void UpdateVolume() {
  if (invCharacters && editVar) {
    FindInvChars(v_firstDigit, v_secondDigit);
    lcd.setCursor(14, 3);
    if (v_secondDigit > 0) {
      lcd.write((byte)1);
    }
    else {
      lcd.print(" ");
    }
    lcd.write((byte)0);
  }
  else {
    lcd.setCursor(14, 3);
    if (v_secondDigit > 0) {
      lcd.print(v_secondDigit);
    }
    else {
      lcd.print(" ");
    }
    lcd.print(v_firstDigit);
  }
}

void Revert() {
  if (editVar) {
    lcd.setCursor(14, 3);
    if (v_secondDigit > 0) {
      lcd.print(v_secondDigit);
    }
    else {
      lcd.print(" ");
    }
    lcd.print(v_firstDigit);
  }
  else {
    lcd.setCursor(2, 3);
    if (b_secondDigit > 0) {
      lcd.print(b_secondDigit);
    }
    else {
      lcd.print(" ");
    }
    lcd.print(b_firstDigit);
  }
  //Revert previous numbers to normal
}
