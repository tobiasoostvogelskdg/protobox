#define startButton 8
#define pirPin 9
#define tmpPin A0
#define lightPin A1

#include <LiquidCrystal.h>                    
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);        

bool programStarted = false;
int selectedSensor = 0;

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);                     
  lcd.setCursor(0,0);
  lcd.print("Hello stranger!");          
  lcd.setCursor(0, 1);                  
  lcd.print("Press start");             
  pinMode(startButton, INPUT_PULLUP);
  pinMode(pirPin, INPUT); // PIR motion sensor pin
}

void loop() {
  if (digitalRead(startButton) == LOW) {
    programStarted = !programStarted;
    startingState(programStarted);
    delay(350); // Debouncing delay
  }
  
}

void startingState(bool &programStarted) {
  if (programStarted) {
    lcd.clear();
    lcd.print("Oh, you pressed");          
    lcd.setCursor(0, 1);                  
    lcd.print("start?");
    delay(4000);
    lcd.clear();
    lcd.print("Ready to test");          
    lcd.setCursor(0, 1);                  
    lcd.print("our sensors?");
    delay(3000);
    lcd.clear();
    lcd.print("Start moving");          
    lcd.setCursor(0, 1);                  
    lcd.print("above the box.");
    movementAction();
    delay(3000);
    lcd.clear();
    lcd.print("Lets move on to");          
    lcd.setCursor(0, 1);                  
    lcd.print("the heat sensor");
    delay(3000);
    lcd.clear();
    lcd.print("Make some heat");          
    lcd.setCursor(0, 1);                  
    lcd.print("above the sensor");
    tempAction();
    delay(3000);
    lcd.clear();
    lcd.print("Lets move on to");          
    lcd.setCursor(0, 1);                  
    lcd.print("the light sensor");
    delay(3000);
    lcd.clear();
    lcd.print("Make some light");          
    lcd.setCursor(0, 1);                  
    lcd.print("above the sensor");
    lightAction();
    delay(3000);
    lcd.clear();
    lcd.print("Thanks for");          
    lcd.setCursor(0, 1);                  
    lcd.print("testing");
    delay(3000);
    lcd.clear();
    lcd.print("We hope you like");          
    lcd.setCursor(0, 1);                  
    lcd.print("the project");
    delay(3000);
    lcd.clear();
    lcd.print("Press start to");          
    lcd.setCursor(0, 1);                  
    lcd.print("reset the box.");
    delay(3000);
    
    
  } else {
    lcd.clear();
    lcd.print("Hello stranger");          
    lcd.setCursor(0, 1);                  
    lcd.print("Press start");
  }
}

void movementAction(){
  int movementValue = 0;
  while(movementValue < 20){
    int sensorValue = digitalRead(pirPin);
    Serial.println(sensorValue);
    if(sensorValue == 1){
      movementValue += 1;
    }
    Serial.println(sensorValue);
    delay(200);
  }
  lcd.clear();
  lcd.print("Amazing! task 1");          
  lcd.setCursor(0, 1);                  
  lcd.print("was a success!");
}

void tempAction(){
  int tempCounter = 0;
  while (tempCounter < 15){
    Serial.println(analogRead(tmpPin));
    if(analogRead(tmpPin) > 155){
      tempCounter += 1;
    }
    delay(200);
  }
  lcd.clear();
  lcd.print("Awsome! task 2");          
  lcd.setCursor(0, 1);                  
  lcd.print("completed;"); 
}

void lightAction(){
  int lightCounter= 0;
  while(lightCounter < 25){
    Serial.println(analogRead(lightPin));
    if(analogRead(lightPin) > 700){
      lightCounter ++;
    }
    delay(200);
  }
  lcd.clear();
  lcd.print("You did it!");          
  lcd.setCursor(0, 1);                  
  lcd.print("Great job!"); 
}
