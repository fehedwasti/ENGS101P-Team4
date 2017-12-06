#define pH_read P1_4
#define Acid P1_5
#define Alkali P1_6

int VpH = 0;
int pH = 0;
int pH_upper = 7;
int pH_lower = 3;

double pH_get(int initial_data)
{
  initial_data -= 512;
  double pH_value;

  // using equation to turn output into pH

  pH_value = 7 + (((399.6 - initial_data) * 96485) / (8.314510 * temp * 2.302585));
  return pH_value;

}
void setup ()
{
  Serial.begin (9600);
  pinMode(pH_read,INPUT);
  pinMode(Acid,OUTPUT);
  pinMode(Alkali,OUTPUT);
}

void loop()
{
  VpH = analogRead(pH_read);

  pH = pH_get(VpH); //apply the equation on the rawdata to find pH

  Serial.println(pH);

  // ADD ACID if the pH is higher than 7
  if(pH > pH_upper )
  {

   digitalWrite(Acid,HIGH);
   delay(10000);
   digitalWrite(Acid,LOW);
   delay(1000);

  }

   // Add alkali if the pH is lower than 3
  else if (pH < pH_lower)
  {

   digitalWrite(Alkali,HIGH)
   delay(10000);
   digitalWrite(Alkali,LOW);
   delay(1000);

  }


}
