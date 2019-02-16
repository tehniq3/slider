/*
 * program for control a DC motor (direction and speed)
 * program writted by Nicu FLORICA (niq_ro) from http://www.arduinotehniq.com
 * http;//nicuflorica.blogspot.ro
 * http://arduinotehniq.blogspot.com/
 * ver.0 - initial
 */

#define in1 2
#define in2 3
#define in3 4
#define in4 5
#define out1 9
#define out2 10

#define vitezamin 105  // minimum speed (for move device)
#define vitezamax 255  // maximum speed
#define treapta 25

int viteza = 0;  // speed
int procent = 0; // procent of speed (0-100) 

void setup() {
Serial.begin(9600);
Serial.println("------");
pinMode(in1, INPUT);
pinMode(in2, INPUT);
pinMode(in3, INPUT);
pinMode(in4, INPUT);
digitalWrite(in1, LOW);
digitalWrite(in2, LOW);
digitalWrite(in3, LOW);
digitalWrite(in4, LOW);
pinMode(out1, OUTPUT);
pinMode(out2, OUTPUT);
analogWrite(out1, 0);
analogWrite(out2, 0); 

viteza = (vitezamin+vitezamax)/2;  // default speed is medium
} // end setup

void loop() {
while (digitalRead(in1) == HIGH)  // if is push buton 'A'
{
  analogWrite(out1, viteza); // direction 1 
  Serial.println("Move in left");
}

while (digitalRead(in2) == HIGH)  // if is push buton 'B'
{
  analogWrite(out2, viteza); // direction 2 
  Serial.println("Move in Righ");
}

if (digitalRead(in3) == HIGH)  // if is push buton 'C'
{
  viteza = viteza - treapta; // decrease speed
  if (viteza < vitezamin)
  {
    viteza = vitezamin;
    Serial.println("Speed is at minimum !"); 
  }
  Serial.print("PWM = ");
  Serial.print(viteza);
  Serial.print("/255 ----> ");
  procent = map(viteza, 0,255,0,100);
  Serial.println("%");
  delay(100);
}
if (digitalRead(in4) == HIGH)  // if is push buton 'D'
{
  viteza = viteza + treapta; // increase speed
  if (viteza > vitezamax)
  {
    viteza = vitezamax;
    Serial.println("Speed is at maximum !"); 
  }
  Serial.print("PWM = ");
  Serial.print(viteza);
  Serial.print("/255 ----> ");
  procent = map(viteza, 0,255,0,100);
  Serial.println("%");
  delay(100);
}
//delay(100);
analogWrite(out1, 0); // direction 1 off
analogWrite(out2, 0); // direction 2 off
} // end main loop
