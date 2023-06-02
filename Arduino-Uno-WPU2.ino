//* Definiert verwendete Libraries(Bibliotheken), die Pins für den Joystick und den Speed(Geschwindigkeit) der Motoren.

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <AFMotor.h>
#define x A0
#define y A1
#define Speed 180

//* Definiert wo welcher Motor eingesteckt ist.

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);


LiquidCrystal_I2C lcd(0x27,20,4);


// ** Diese Funktion läuft nur am anfang des Programmes ab, und definiert den Speed(Geschwindigkeit) aller Motoren
void setup() {
  Serial.begin(9600);
  motor1.setSpeed(Speed);
  motor2.setSpeed(Speed);
  motor3.setSpeed(Speed);
  motor4.setSpeed(Speed);
  begin();
}


void begin(){
  lcd.begin();
  lcd.print("Joystick:");
  lcd.setCursor(0, 1);
  lcd.print("X:");
  lcd.setCursor(0, 2);
  lcd.print("Y:");
  
}

  

//* Diese funktion läuft möglichst 10000 mal die Sekunde und ließt den Input von den pins des Joysticks ab und entscheidet dann basierend darauf
//* ob das Fahrzeug nach vorne,hinten,links oder rechts fahren soll

void loop() {
  int X = analogRead(x);
  int Y = analogRead(y);

  lcd.setCursor(1, 1);
  lcd.print(X);
  lcd.setCursor(1, 2);
  lcd.print(Y);


  Serial.print(X);
  Serial.print("\t");
  Serial.println(Y);

  if (X >= 800) {
    motor1.run(BACKWARD);
    motor2.run(BACKWARD);
    motor3.run(BACKWARD);
    motor4.run(BACKWARD);
  } else if (X <= 200) {
    motor1.run(FORWARD);
    motor2.run(FORWARD);
    motor3.run(FORWARD);
    motor4.run(FORWARD);
  } else if (Y >= 800) {
    motor1.run(FORWARD);
    motor2.run(BACKWARD);
  } else if (Y <= 200) {
    motor1.run(BACKWARD);
    motor2.run(FORWARD);
  } else {
    motor1.run(RELEASE);
    motor2.run(RELEASE);
  }
}