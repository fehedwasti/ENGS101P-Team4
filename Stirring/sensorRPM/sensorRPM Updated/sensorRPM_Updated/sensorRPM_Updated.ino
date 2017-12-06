int sensorPin = 3; // P1.1
int readings[3];

void setup() {
  Serial.begin(9600);
  pinMode(sensorPin, INPUT);
}


int rootms(int list[3]) {    //Function calculates the average of a list
  int rms = 0;
  for (int i = 0; i < 3; i++){
    rms += list[i];
  }
  rms = rms / 3;
  return rms;
  
  
}


void loop() {
  while (readings[3] == 0) {
    
    int iteration = 0;
    
    float time;
    int sensorStatus = digitalRead(sensorPin);
    int initialStatus = sensorStatus;    //Initialise inital status
    
    
    while (sensorStatus == initialStatus){    //Waits until state changes
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
      readings[iteration] = time;
      iteration += 1;
    }
  }    //EXIT WHILE LOOP
  
  //Test values for code
  /*readings[0] = 4;
  readings[1] = 5;
  readings[2] = 6;*/
  
  Serial.print("[");
  for (int i = 0; i < 3; i++) {
    
    Serial.print(readings[i]);
    Serial.print(" ");
  }
  Serial.println("]");
  

  int averageTime = rootms(readings);
  
  Serial.println(averageTime);  //IN MICROSECONDS
  
   averageTime = averageTime / pow(10,6); //convert from micros to seconds.        
      //This time is equivalent to time for one revolution.
      //Convert to rpm using sensor_rpm = 60/time
      
      long sensor_rpm = 60/averageTime;
      Serial.print("RPM: ");
      Serial.println(sensor_rpm);
}
