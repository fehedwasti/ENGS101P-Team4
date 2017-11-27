int sensorPin = 3; // Change value if necessary

void setup() {
  Serial.begin(9600);
  pinMode(sensorPin, INPUT);
}

void loop() {
  int time;
  int sensorStatus = digitalRead(sensorPin);
  int initialStatus = sensorStatus;
  
      int t0 = millis();  //Start timer
      while (sensorStatus == initialStatus){
        sensorStatus = digitalRead(sensorPin);
      }
    
      int t1 = millis();  //Stop timer once status has changed.
      
      time = t1 - t0; //Time for sensorStatus to change
      Serial.print("TIME TAKEN: ");
      Serial.println(time);
      
  //This time is equivalent to 1/4 of a revolution.
  //Convert to rpm using sensor_rpm = 60/(4*time) = 15/time
  int sensor_rpm = 15/time;
}
