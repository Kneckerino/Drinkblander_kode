void VRB_Screen() {

  //Vodka
  lcd.print(" Vodka");

  //Redbull
  lcd.setCursor(13, 0);
  lcd.print("Redbull");

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
  if (VRB_Booziness < 10) {
    lcd.setCursor(3, 3);
  }
  else {
    lcd.setCursor(2, 3);
  }
  lcd.print(VRB_Booziness);
  lcd.print("%");

  //Volumen
  lcd.setCursor(14, 3);
  if (volume < 10) {
    lcd.print(" ");
  }
  lcd.print(volume);
  lcd.print("cL");
}
