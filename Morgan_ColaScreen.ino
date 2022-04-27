void MC_Screen() {

  //Captain Morgan
  lcd.print("Captain");
  lcd.setCursor(0, 1);
  lcd.print("Morgan");

  //Coca Cola
  lcd.setCursor(14, 0);
  lcd.print("Coca");
  lcd.setCursor(14, 1);
  lcd.print("Cola");

  //og
  lcd.setCursor(9, 0);
  lcd.print("og");

  //MainButton
  lcd.setCursor(7, 2);
  lcd.write((byte)4);
  lcd.setCursor(9, 2);
  lcd.write((byte)0);
  lcd.setCursor(12, 2);
  lcd.write((byte)3);
  lcd.setCursor(9, 3);
  lcd.write((byte)1);
  lcd.write((byte)2);

  //Percentage
  if (MC_Booziness < 10) {
    lcd.setCursor(3, 3);
  }
  else {
    lcd.setCursor(2, 3);
  }
  lcd.print(MC_Booziness);
  lcd.print("%");

  //Volumen
  lcd.setCursor(14, 3);
  if (volume < 10) {
    lcd.print(" ");
  }
  lcd.print(volume);
  lcd.print("cL");
}
