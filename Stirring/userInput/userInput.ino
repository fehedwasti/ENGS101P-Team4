//REMOVE EXTRA PRINT STATEMENTS ONCE COMPLETE
//DONT EDIT UNLESS YOU KNOW WHAT YOURE DOING

int input_rpm;

void setup() {

Serial.begin(9600);
  //pinMode(sensorPin, INPUT);
  Serial.print("Enter the rpm for the stirirng: ");
  while (Serial.available() == 0);  //While Loops until user input.
    input_rpm = Serial.parseInt();

}

void loop() {
  
  
  if (Serial.available() == 0) {    //Checks if input field has no value
   
    Serial.println(input_rpm);      //input_rpm remains unchanged
  }
  
  else {                        //input field has a value
    input_rpm = Serial.parseInt();    //Changes input_rpm
    Serial.print("SETTING A NEW VALUE OF:");
    Serial.println(input_rpm);
    delay(1000);
  }
  
}
