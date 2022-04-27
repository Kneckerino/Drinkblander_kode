//Alle brugte biblioteker
//---------------------------------------------------------------------------------------
#include <Keypad.h>
#include <LiquidCrystal.h>
#include <EEPROM.h>
//---------------------------------------------------------------------------------------

//Pins på Arduino
//---------------------------------------------------------------------------------------
/*Keypad*/
const byte rows = 4;
const byte columns = 4;
byte rowPins[rows] {A3, A2, A1, A0};
byte columnPins[columns] {2, 3, A5, A4};

/*Liquid Crystal Display*/
const int rs = 8, e = 9, d4 = 10, d5 = 11, d6 = 12, d7 = 13;  
LiquidCrystal lcd(rs, e, d4, d5, d6, d7);

/*Pumper*/
byte pump1 = 6;
byte pump2 = 7;
//---------------------------------------------------------------------------------------

//Opsætning til keypad
//---------------------------------------------------------------------------------------
char keys[rows][columns] = {
  {'1', '2', '3', 'F'},
  {'4', '5', '6', 'E'},
  {'7', '8', '9', 'D'},
  {'A', 'O', 'B', 'C'}
};
Keypad keypad = Keypad(makeKeymap(keys), rowPins, columnPins, rows, columns);
//---------------------------------------------------------------------------------------

//Diverse variabler
//---------------------------------------------------------------------------------------
unsigned long timestamp;
unsigned long pump1Time;
unsigned long pump2Time;
unsigned long millisToFull;
int dotsPerSec = 1;
unsigned long millisToLitre = 72759;
int procent;
int chosenDrink;
int i;
int blinkSpeed = 500;
bool invCharacters = 0;
bool editVar = 0;
bool pump1_enable;
bool pump2_enable;
uint8_t MC_Booziness;
uint8_t MC_B_Address = 0;
uint8_t VRB_Booziness;
uint8_t VRB_B_Address = 1;
uint8_t volume;
uint8_t volAddress = 2;
int baseVol = 25;
int baseMC_B = 10;
int baseVRB_B = 10;
uint8_t boozeAddress[] {
  MC_B_Address,
  VRB_B_Address
};
int boozeKind;
int maxVolume = 50;
int morganAlcoPercent = 35;
int vodkaAlcoPercent = 38;
int maxBooziness[] {
  morganAlcoPercent,
  vodkaAlcoPercent
};
int v_firstDigit;
int v_secondDigit;
int b_firstDigit;
int b_secondDigit;
int screenType = 1;
char key;
//---------------------------------------------------------------------------------------

void setup() {

  Serial.begin(9600);

  //Hent gemte værdier fra EEPROM
  //---------------------------------------------------------------------------------------
  volume = EEPROM.read(volAddress);
  if (volume < 2 || volume > 50) { //Hvis EEPROM har en ikke-passende variabel, går vi tilbage til standarden
    volume = baseVol;
    EEPROM.write(volAddress, volume);
  }

  MC_Booziness = EEPROM.read(MC_B_Address);
  if (MC_Booziness < 0 || MC_Booziness > maxBooziness[0]) {  //Hvis EEPROM har en ikke-passende variabel, går vi tilbage til standarden
    MC_Booziness = baseMC_B;
    EEPROM.write(MC_B_Address, MC_Booziness);
  }

  VRB_Booziness = EEPROM.read(VRB_B_Address);
  if (VRB_Booziness < 0 || VRB_Booziness > maxBooziness[1]) { //Hvis EEPROM har en ikke-passende variabel, går vi tilbage til standarden
    VRB_Booziness = baseVRB_B;
    EEPROM.write(VRB_B_Address, VRB_Booziness);
  }
  //---------------------------------------------------------------------------------------
  
  //Til LCD
  lcd.begin(20, 4);

  //Til Keypad
  /*Rækker*/
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);

  /*Kolonner*/
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);

  pinMode(pump1, OUTPUT);
  pinMode(pump2, OUTPUT);
  
  //Start med almindelige custom-symboler
  StandardChars();

  //Start Display
  CheckScreen();

}

void loop() {

  //Er en knap trykket?
  //---------------------------------------------------------------------------------------
  key = keypad.getKey();
  if (key != NO_KEY) {
    
    if (key == '4') { //Skift skærm mod venstre
      SwitchLeft(); 
    }
    if (key == '6') { //Skift skærn mod højre
      SwitchRight(); 
    }
    if (key == '5') { //Lav drinken
      chosenDrink = screenType;
      screenType = 3;
      CheckScreen(); 
    }
    if (key == 'E') { //Ændr variabler
      chosenDrink = screenType; 
      screenType = 5;
      CheckScreen();
    }
    if (key == 'C') { //Synkroniser pumperne
      chosenDrink = screenType;
      screenType = 6;
      CheckScreen();
    }
  }
  //---------------------------------------------------------------------------------------
}

//Ændr skærmen efter bestemt skærmtype
//---------------------------------------------------------------------------------------
void CheckScreen() {
  switch (screenType) {
    
    case 1: //Morgan & Cola
      lcd.clear();
      MC_Screen();

      break;

    case 2: //Vodka & Redbull
      lcd.clear();
      VRB_Screen();

      break;

    case 3: //Lav drink
      lcd.clear();
      LoadingChars(); //Skift til andre brugerdefinerede karakterer
      LoadingScreen();
      LoadingBar();

      //Drinken er færdig
      screenType++;
      CheckScreen();
      break;

    case 4: //Drink er færdig
      lcd.clear();
      lcd.setCursor(3, 1);
      lcd.print("NYD DIN DRINK!");
      delay(1000);
      StandardChars(); //Skift til normale brugerdefinerede karakterer

      //Gå tilbage til oprindelig drink
      screenType = chosenDrink;
      CheckScreen();
      break;

    case 5: //Ændr variabler
      EditScreen();
      
      //Gå tilbage til oprindelig drink
      screenType = chosenDrink;
      CheckScreen();
      break;

    case 6: //Synkroniser pumperne
      SyncScreen();
      
      //Gå tilbage til oprindelig drink
      screenType = chosenDrink;
      CheckScreen();
      break;
      
    default: //ERROR-skærm hvis de andre ikke fungerer
      lcd.clear();
      lcd.setCursor(2, 1);
      lcd.print("ERROR!");
      break;
  }
}
//---------------------------------------------------------------------------------------
