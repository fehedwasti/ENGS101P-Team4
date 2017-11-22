//This code has two different functions combined into one. One of the functions will be removed when we implement it with the phototransistor.
//One of them is the frequency generator, which provides a test platform for the detector.
//The second part is the detector itself. The code for this will be modified to account for the bowtie shape of the paddle.

int pulsepin = 8; //This is the detector pin

int PWM = 5; //This is the frequency generating pin

int pulsehigh; //the time where the pulse is spent at high (us)
int pulselow; //the time where the pulse is spent at low (us)
float pulsetotal; //total time for one pulse
float frequency; //the reciprocal of the total time

void setup() {
  
Serial.begin(9600); //this is for the detector so we can have a reading of the frequency
pinMode(pulsepin, INPUT);
pinMode(PWM, OUTPUT);
delay(100); //give time for program to respond
}

void loop() {
  
analogWrite(PWM, 150); //this is the frequency generated. The duty cycle length doesnt matter, as PWM has a standard frequency.
pulsehigh = pulseIn(pulsepin, HIGH); //a built in function which measures the high pulse
pulselow = pulseIn(pulsepin, LOW); //""  low pulse

pulsetotal = pulsehigh + pulselow; //total pulse length
frequency = 1000000/pulsetotal; //because the units for time for pulsein are in microseconds we use 1 million
Serial.println(frequency); //visual output
delay(1000);
}

//RESULTS: The reading we get is around 980Hz, which is the quoted standard frequency for PWM pin 5. 
//REFERENCE https://www.arduino.cc/reference/en/language/functions/analog-io/analogwrite/ 
