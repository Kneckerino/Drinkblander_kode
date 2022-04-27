//Almindelige brugerdefinerede karakterer
//---------------------------------------------------------------------------------------
void StandardChars() {
  byte AlcoFlaskTop[] {
    B00000,
    B01100,
    B01100,
    B01100,
    B01100,
    B11110,
    B11110,
    B11110,
  };
  byte AlcoFlaskBottom[] {
    B11110,
    B11110,
    B11110,
    B11110,
    B11110,
    B11110,
    B11110,
    B11110,
  };
  byte ShotGlass[] {
    B00000,
    B00000,
    B00000,
    B10001,
    B10001,
    B11111,
    B11111,
    B01110,
  };
  byte RightArrow[] {
    B10000,
    B11000,
    B11100,
    B11110,
    B11110,
    B11100,
    B11000,
    B10000,
  };
  byte LeftArrow[] {
    B00001,
    B00011,
    B00111,
    B01111,
    B01111,
    B00111,
    B00011,
    B00001,
  };

  lcd.createChar(0, AlcoFlaskTop);
  lcd.createChar(1, AlcoFlaskBottom);
  lcd.createChar(2, ShotGlass);
  lcd.createChar(3, RightArrow);
  lcd.createChar(4, LeftArrow);
}
//---------------------------------------------------------------------------------------

//Brugerdefinerede karakterer til Loadingskærmen
//---------------------------------------------------------------------------------------
void LoadingChars() {
  byte AlcoFlaskLeft[] {
    B00000,
    B00000,
    B11111,
    B11111,
    B11111,
    B11111,
    B00000,
    B00000,
  };
  byte AlcoFlaskMid[] {
    B00000,
    B00000,
    B11110,
    B11111,
    B11111,
    B11110,
    B00000,
    B00000,
  };
  byte AlcoFlaskRight[] {
    B00000,
    B00000,
    B00000,
    B11000,
    B11000,
    B00100,
    B00100,
    B00100,
  };
  byte ShotGlass[] {
    B00100,
    B00010,
    B00010,
    B10011,
    B10011,
    B11111,
    B11111,
    B01110,
  };
  byte LoadingLeft[] {
    B11111,
    B10000,
    B10000,
    B10000,
    B10000,
    B10000,
    B10000,
    B11111,
  };
  byte LoadingRight[] {
    B11111,
    B00001,
    B00001,
    B00001,
    B00001,
    B00001,
    B00001,
    B11111,
  };
  byte LoadingMain[] {
    B11111,
    B00000,
    B00000,
    B00000,
    B00000,
    B00000,
    B00000,
    B11111,
  };
  byte LoadingFull[] {
    B11111,
    B11111,
    B11111,
    B11111,
    B11111,
    B11111,
    B11111,
    B11111,
  };

  lcd.createChar(0, AlcoFlaskLeft);
  lcd.createChar(1, AlcoFlaskMid);
  lcd.createChar(2, AlcoFlaskRight);
  lcd.createChar(3, ShotGlass);
  lcd.createChar(4, LoadingLeft);
  lcd.createChar(5, LoadingRight);
  lcd.createChar(6, LoadingMain);
  lcd.createChar(7, LoadingFull);
}
//---------------------------------------------------------------------------------------

//Find inverterede numre 0-9
//If-statements da der kun er plads til 8 karakterer i LCD'en
//---------------------------------------------------------------------------------------
void FindInvChars(int x, int y) {
  int charNr = 0;
  
  if (x == 0) {
    byte inv0[] {
      B10001,
      B01110,
      B01100,
      B01010,
      B00110,
      B01110,
      B10001,
    };
    lcd.createChar(charNr, inv0);
  }
  else if (x == 1) {
    byte inv1[] {
      B11011,
      B10011,
      B11011,
      B11011,
      B11011,
      B11011,
      B10001,
    };
    lcd.createChar(charNr, inv1);
  }
  else if (x == 2) {
    byte inv2[] {
      B10001,
      B01110,
      B11110,
      B11101,
      B11011,
      B10111,
      B00000,
    };
    lcd.createChar(charNr, inv2);
  }
  else if (x == 3) {
    byte inv3[] {
      B00000,
      B11101,
      B11011,
      B11101,
      B11110,
      B01110,
      B10001,
    };
    lcd.createChar(charNr, inv3);
  }
  else if (x == 4) {
    byte inv4[] {
      B11101,
      B11001,
      B10101,
      B01101,
      B00000,
      B11101,
      B11101,
    };
    lcd.createChar(charNr, inv4);
  }
  else if (x == 5) {
    byte inv5[] {
      B00000,
      B01111,
      B00001,
      B11110,
      B11110,
      B01110,
      B10001,
    };
    lcd.createChar(charNr, inv5);
  }
  else if (x == 6) {
    byte inv6[] {
      B11001,
      B10111,
      B01111,
      B00001,
      B01110,
      B01110,
      B10001,
    };
    lcd.createChar(charNr, inv6);
  }
  else if (x == 7) {
    byte inv7[] {
      B00000,
      B11110,
      B11101,
      B11011,
      B10111,
      B10111,
      B10111,
    };
    lcd.createChar(charNr, inv7);
  }
  else if (x == 8) {
    byte inv8[] {
      B10001,
      B01110,
      B01110,
      B10001,
      B01110,
      B01110,
      B10001,
    };
    lcd.createChar(charNr, inv8);
  }
  else if (x == 9) {
    byte inv9[] {
      B10001,
      B01110,
      B01110,
      B10000,
      B11110,
      B11101,
      B10011,
    };
    lcd.createChar(charNr, inv9);
  }

  charNr++;
  // Do the y's
  if (y == 0) {
    byte inv0[] {
      B10001,
      B01110,
      B01100,
      B01010,
      B00110,
      B01110,
      B10001,
    };
    lcd.createChar(charNr, inv0);
  }
  else if (y == 1) {
    byte inv1[] {
      B11011,
      B10011,
      B11011,
      B11011,
      B11011,
      B11011,
      B10001,
    };
    lcd.createChar(charNr, inv1);
  }
  else if (y == 2) {
    byte inv2[] {
      B10001,
      B01110,
      B11110,
      B11101,
      B11011,
      B10111,
      B00000,
    };
    lcd.createChar(charNr, inv2);
  }
  else if (y == 3) {
    byte inv3[] {
      B00000,
      B11101,
      B11011,
      B11101,
      B11110,
      B01110,
      B10001,
    };
    lcd.createChar(charNr, inv3);
  }
  else if (y == 4) {
    byte inv4[] {
      B11101,
      B11001,
      B10101,
      B01101,
      B00000,
      B11101,
      B11101,
    };
    lcd.createChar(charNr, inv4);
  }
  else if (y == 5) {
    byte inv5[] {
      B00000,
      B01111,
      B00001,
      B11110,
      B11110,
      B01110,
      B10001,
    };
    lcd.createChar(charNr, inv5);
  }
  else if (y == 6) {
    byte inv6[] {
      B11001,
      B10111,
      B01111,
      B00001,
      B01110,
      B01110,
      B10001,
    };
    lcd.createChar(charNr, inv6);
  }
  else if (y == 7) {
    byte inv7[] {
      B00000,
      B11110,
      B11101,
      B11011,
      B10111,
      B10111,
      B10111,
    };
    lcd.createChar(charNr, inv7);
  }
  else if (y == 8) {
    byte inv8[] {
      B10001,
      B01110,
      B01110,
      B10001,
      B01110,
      B01110,
      B10001,
    };
    lcd.createChar(charNr, inv8);
  }
  else if (y == 9) {
    byte inv9[] {
      B10001,
      B01110,
      B01110,
      B10000,
      B11110,
      B11101,
      B10011,
    };
    lcd.createChar(charNr, inv9);
  }
}
//---------------------------------------------------------------------------------------
