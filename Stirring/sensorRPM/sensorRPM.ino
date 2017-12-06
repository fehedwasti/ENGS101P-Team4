int sensorPin = 3; // P1.1

void setup() {
  Serial.begin(9600);
  pinMode(sensorPin, INPUT);
}

void loop() {
  float time;
  int sensorStatus = digitalRead(sensorPin);
  int initialStatus = sensorStatus;    //Initialise inital status
  
  
  while (sensorStatus == initialStatus){    //Waits until state changes
    Serial.println("HELLO");
    sensorStatus = digitalRead(sensorPin);  //Status != Initial

  }
  int oppositeStatus = sensorStatus ;   //Opposite to initialStatus
  
  float t0 = micros();  //Start timer
  
  for (int i = 0; i < 2; i++){ 
    while (sensorStatus != initialStatus){
      sensorStatus = digitalRead(sensorPin);
    }
    initialStatus = oppositeStatus;
  }
  float t1 = micros();  //Stop timer once status has changed.
  
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
