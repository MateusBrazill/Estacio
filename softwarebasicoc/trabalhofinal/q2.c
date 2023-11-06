//Aluno: Mateus Brazil de Oliveira
//Matricula: 202003447031

//Questão 2
/*
    Realizar um projeto de trena digital, utilizando montagem no Tinkercad.
*/

#include <LiquidCrystal.h>

//Ultrassonic Sensor Pins
const int trigger = 6, echo = 5;

//LCD Pinst
const int rs = 12, en = 11, d4 = 10, d5 = 9, d6 = 8, d7 = 7;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int getDistance(){
  long duration = 0;
  int distance = 0;
  
  digitalWrite(trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);
  duration = pulseIn(echo, HIGH);
  
  distance = duration * 0.034/2;
  
  return distance;
}

void showDistance(int distance){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Eletronic ruler");
    lcd.setCursor(0,1);
    lcd.print("Dist(cm):");
    lcd.setCursor(10,1);
    lcd.print(distance);
}
void setup()
{
  lcd.begin(16, 2);
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600);
}

void loop()
{
  int distance = 0;
  distance = getDistance();
  Serial.print("Distance -> ");  
  Serial.println(distance);
  showDistance(distance); 
  delay(500);
}