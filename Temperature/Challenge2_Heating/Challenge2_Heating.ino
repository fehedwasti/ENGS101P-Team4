/*
* This is the code for the Launchpad which will be used in the heating system of the bioreactor.
* All parameters can only be amended by changing the code and no input is required.
*/


#include<math.h>
int buttonstate = 0;
int RAWTemp = 0;
int Temperature = 0;


/*Steinhart-Hart Equation*/

double getTemperature(int rawADC) {
rawADC -= 400; // Modify the input value to calibrate the temperature.
double temp;
temp = logf(((10240000/rawADC) - 10000));
temp = 1 / (0.001129148 +
(0.000234125 + (0.0000000876741 * temp * temp ))* temp );
return temp - 273.15; // Convert Kelvin to Celsius
//return (temp * 9.0)/ 5.0 + 32.0; // Celsius to Fahrenheit 
}


void setup() {

Serial.begin(9600);
pinMode(2, INPUT);
pinMode(PUSH2, INPUT_PULLUP);
pinMode(8, OUTPUT);

  
}

/********************************************************************************/

void loop() {

Serial.println("HW");  
  /*Pressing the button will turn the heater controller system on.*/
  if(digitalRead(PUSH2) == LOW)
  {
    buttonstate = 1;
    delay(2000);
  }

  while(buttonstate == 1)
  {
    /*Pressing the button again will turn the system off.*/
    
    RAWTemp = analogRead(2);
    /*Use Steinhart-Hart equation to get temperature*/
    Temperature = getTemperature(RAWTemp);
    /*For Testing*/
    Serial.println(RAWTemp);
    if(digitalRead(PUSH2) == LOW)
    {
      buttonstate = 0;
      delay(15000);
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
    
    if (Temperature < 28)
    {
      digitalWrite(8, HIGH);
      delay(10000);
      digitalWrite(8, LOW);
      delay(1000);
    }
    else if(Temperature >= 28 && Temperature <= 32)
    {
      digitalWrite(8, HIGH);
      delay(4000);
      digitalWrite(8, LOW);
      delay(3000);
    }
    else if(Temperature > 32)
    {
      digitalWrite(8, LOW);
      delay(2000);
      
    }
    
  }

  }

