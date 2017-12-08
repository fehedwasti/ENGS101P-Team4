/*
* This is the code for the Launchpad which will be used in the heating system of the bioreactor.
* All parameters can only be amended by changing the code and no input is required.
*/


#include<math.h>
int buttonstate = 0;
double MediumTemp = 30;

    double getTemperature(double resistence){
      //This function calculate the temperature of the water according to the steinhart-hart equation and return the value rounded to the nearest 0.1 degree celsius
      double temp = 1/(0.001257995159 + 0.0002205992525 * logf(resistence) + 0.00000008220364928 * powf(logf(resistence), 3));
      temp = floor(temp * 10 + 0.5 )/10;
      return temp;
    }




void setup() {

Serial.begin(9600);
pinMode(P1_0, INPUT);
pinMode(PUSH2, INPUT_PULLUP);
pinMode(P2_0, OUTPUT);

  
}

/********************************************************************************/

void loop() {
Serial.println("Waiting");
if (Serial.available() != 0) {   
    MediumTemp = Serial.parseInt();    
    Serial.print("SETTING A NEW VALUE OF:");
    Serial.println(MediumTemp);
    delay(1000);
  }

  /*Pressing the button will turn the heater controller system on.*/
  if(digitalRead(PUSH2) == LOW)
  {
    buttonstate = 1;
    delay(2000);
  }

  while(buttonstate == 1)
  {
    double rawVoltageReading = analogRead(P1_0);
    double voltage = rawVoltageReading / 880 * 3.3;
    double thermistorResistence = (3.3 - voltage)/ (voltage - 0.0) * 10000;
    double Temperature = getTemperature(thermistorResistence);
    Temperature -= 273.15;
    /*Pressing the button again will turn the system off.*/

    /*For Testing*/
    Serial.println(Temperature);
    if(digitalRead(PUSH2) == LOW)
    {
      buttonstate = 0;
      delay(10000);
    }

    /*
     * Based on the knowledge I have, The launchpad could only be used as a controller 
     * that controls ON or OFF of the heater power system. Therefore, the power of the heater is 
     * determined by the frequency of powering up, although this might be less efficient. It will
     * be better if I could use PWM output to control the power of the heater.
     */


     /*PWM control system*/
     /*
    If (Temperature < 28)
    {
      analogWrite(Heaterpin, CurrentHIGH);
    }
    else if(Temperature >= 28 && Temperature <= 32)
    {
      analogWrite(Heatermin, CurrentMedi);
    }
    else if(Temperature > 32)
    {
      analogWrite(Heaterpin, 0);
    }
*/
    /*Digital control system*/

    if (Temperature < MediumTemp - 2)
    {
      digitalWrite(P2_0, HIGH);
      delay(10000);
      digitalWrite(P2_0, LOW);
      delay(300);
    }
    else if(Temperature >= MediumTemp - 2 && Temperature < MediumTemp - 0.5)
    {
      digitalWrite(P2_0, HIGH);
      delay(4000);
      digitalWrite(P2_0, LOW);
      delay(3000);
    }
    else if(Temperature >= MediumTemp - 0.5)
    {
      digitalWrite(P2_0, LOW);
      delay(2000);
      
    }

    
  }

  }

