#include <stdio.h>
#include <math.h>
#define Faraday 9.6485309*pow(10,4)
#define R 8.314510
#define ln10 2.302585093
#define VpH P1_4
#define acidPump P1_5
#define basePump P1_6

float T = 17.7 + 273; // temprature used to calculate sensitivity
const int pH_maintain = 5;

float pHX = 0;
int pumpLim = 10;//number of pump activation possible to prevent overflow

int limit = 10;
void setup()
{
  Serial.begin(9600);
  pinMode(acidPump, OUTPUT);
  pinMode(basePump, OUTPUT);
  pinMode(VpH, INPUT);
}
void loop()
{

  // read the electric potential at pH measuring electrode value
  // correct the value
  pHX = calcX(analogRead(VpH) * (2.9/100000));

  int acidPumpct = 0; //number of pump activation

  //display on serial

  Serial.print("pH value of solution is:  ");
  Serial.println(pHX);
  if(acidPumpct <= pumpLim)
  {
    if (pHX > pH_maintain)
    {
      digitalWrite(acidPump, HIGH); //turn on acid pump
      acidPumpct = acidPumpct + 1;
    }
    else if (pHX < pH_maintain)
    {
      digitalWrite(basePump, HIGH); //turn on base pump
      acidPumpct = acidPumpct + 1;
    }
  }
  delay(1000);
  digitalWrite(acidPump, LOW); //turn both off
  digitalWrite(basePump, LOW);

}

float calcX(double Ex)
{
  // Ex is the Electric potential at pH-measuring electrode
  Serial.print("The Ex is: ");
  Serial.println(Ex);
  float X;

 //turn the output into pH using equation
  X = 7 + (((190*2.9/100000 - Ex)*Faraday)/(R*T*ln10));

  return X;
}
