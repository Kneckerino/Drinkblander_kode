void SwitchRight() { //Skift skærm mod højre
  screenType++;
  if (screenType == 3) {
    screenType -= 2;
  }
  CheckScreen();
}

void SwitchLeft() { //Skift skærm mod venstre
  screenType--;
  if (screenType == 0) {
    screenType += 2;
  }
  CheckScreen();
} 
