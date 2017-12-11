int sensorPin = 3;
long t0, t1, t2, t3;
long timeTaken;
float rpm;
int i = 0;
int i2 = 0;
int store;
int m = analogRead(3);

void setup()
{
  Serial.begin(9600);
  pinMode(sensorPin, INPUT);
  
}

void loop()
{
  int timeTaken = 0;
  store = analogRead(sensorPin);
  determine();
  calculate1();
  calculate2();
  Serial.println(i);
  timeTaken = t3-t2 + t1 - t0;
  
  
  if (timeTaken != 0){
    Serial.print("TIME TAKEN: ");
    Serial.println(timeTaken);
    
    rpm = abs(60000000/timeTaken);
    Serial.print("RPM: ");
    Serial.println(rpm);
    t0, t1, t2, t3 = 0;
  }
}

void determine() {
  if (store <= 600){
    i = 0;
  }
  else if (store >= 970){
    i = 1;
  }
}

void calculate1(){
  if (i != i2 && i == 0){
    t0 = micros();
  }
  
  if (i != i2 && i == 1){
    t1 = micros();
  }
  
  
  i2 = i;
}

void calculate2(){
  if (i != i2 && i == 1){
    t2 = micros();
  }
  
  if (i != i2 && i == 0){
    t3 = micros();
  }
  
  
  i2 = i;
}

    
