//Aluno: Mateus Brazil de Oliveira
//Matricula: 202003447031

//Questão 1
/*
Criar um circuito e o respectivo programa em C para aquisição de dados com a 
plataforma Arduino no simulador Tinkercad.
*/

#include<LiquidCrystal.h>

#define tempSensor A1
#define soilSensor A2

const int rs = 9, en = 8, d4 = 4, d5 = 5, d6 = 6, d7 = 7;

LiquidCrystal lcd(rs,en,d4,d5,d6,d7);

void setup()
{
	pinMode(tempSensor, INPUT);
  	pinMode(soilSensor, INPUT);
  	Serial.begin(9600);
  	lcd.begin(16,2);
}

void loop()
{
	double temperatureRaw = 0, parsedTemp = 0, soilSensorRaw = 0, parsedSoilSensor = 0;
    
  	temperatureRaw = analogRead(tempSensor); 
  	soilSensorRaw = analogRead(soilSensor);
   	
  	parsedTemp = (temperatureRaw*0.004882814-0.5)*100;
  	parsedSoilSensor = map(soilSensorRaw, 0, 1024, 0, 100);
	
  	//Serial print
  	Serial.print("Temp C:");
  	Serial.println(parsedTemp);
  	Serial.print("Water %:");
  	Serial.println(parsedSoilSensor);
  	
  	//LCD print
    lcd.setCursor(0,0);
	lcd.print("Temp: ");
  	lcd.print(parsedTemp);
	lcd.print(" C");
  	lcd.setCursor(0,1);
  	lcd.print("Water %:");
  	lcd.print(parsedSoilSensor);
  
  	delay(1000);
  	lcd.clear();
}
