int sensorPin = 3; // P1.1
int PWM = 9;  //P1.2

void setup() {
  Serial.begin(9600);
  pinMode(sensorPin, INPUT);
  pinMode(PWM, OUTPUT);
  analogWrite(PWM, 125);
  
}

void loop() {
  double time;
  int sensorStatus = digitalRead(sensorPin);
  int initialStatus = sensorStatus;    //Initialise inital status
  
  
  while (sensorStatus == initialStatus){    //Waits until state changes
    Serial.println("1st WHILE LOOP");
    sensorStatus = digitalRead(sensorPin);  //Status != Initial


  }
  int oppositeStatus = sensorStatus ;   //Opposite to initialStatus
  
  double t0 = micros();  //Start timer
  
  for (int i = 0; i < 2; i++){ 
    while (sensorStatus != initialStatus){
      Serial.println("2nd WHILE LOOP");
      sensorStatus = digitalRead(sensorPin);
    }
    initialStatus = oppositeStatus;
  }
  double t1 = micros();  //Stop timer once status has changed.
  
  time = t1 - t0; //Time for sensorStatus to change
  if (time == 0){
     int a = 1;    //Doesn't print if time = 0.
  }
  else {
    Serial.print("TIME TAKEN (microseconds): ");
    Serial.println(time);
    time = time / pow(10,6); //convert from micros to seconds.
        
    //This time is equivalent to 1/4 of a revolution.
    //Convert to rpm using sensor_rpm = 60/(4*time) = 15/time
    long sensor_rpm = 60/time;
    Serial.print("RMP: ");
    Serial.println(sensor_rpm);
  }
}
