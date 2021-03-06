int input_rpm;

void setup() {

Serial.begin(9600);
input_rpm = 0;

}

void loop() {
  
  if (Serial.available() == 0) {    //Checks if input field has no value
   
    Serial.println(input_rpm);      //input_rpm remains unchanged
    delay(100);
  }
  
  else {                        //input field has a value
    input_rpm = Serial.parseInt();    //Changes input_rpm
    Serial.print("SETTING A NEW VALUE OF:");
    Serial.println(input_rpm);
    delay(1000);
  }
  
  /* Calculate rpm from sensor value - Work in Progress
    The sensor will return a Bool value each time the light reaches the sensor
    Measure the time taken for the value to change from 1 to 0.
    This time is equivalent to 1/4 of a revolution.
    Convert to rpm using sensor_rpm = 60/(4*time) = 15/time
  */
  
  int set_rpm = input_rpm;
  /*Compare set_rpm to rpm from sensor. - Work in Progress
    If sensor_rpm < set_rpm --> speed of motor should increase.
    elif sensor_rpm > set_rpm --> decrease.
    else --> Speed remains unchanged
    */
  
}
