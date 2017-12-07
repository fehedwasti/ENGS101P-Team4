int sensor = P1_1;
int buttonstate;
int a;
int totaltime;
int high;
int low;
long int frequency;
int motor = P1_6;

void setup()
{
  pinMode(sensor, INPUT);
  Serial.begin(9600);
  analogWrite(motor, 25);
  // put your setup code here, to run once:
  
}

void loop()
{
  buttonstate = analogRead(sensor);
  if (buttonstate < 600){
    a=0;
  }
  else {
  a=1;
  }  // put your main code here, to run repeatedly:
  high = pulseIn(a, 1);
  low = pulseIn(a, 0);
  totaltime = 2*(high+low);
  frequency = 1000000/totaltime;
  Serial.println(frequency);
}
