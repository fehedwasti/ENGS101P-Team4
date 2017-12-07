int control = P1_6;
int pwmspeed = 0;

int newrpm = 0; //the rpm which is set by the user, and the current rpm
int oldrpm = 0; //the rpm value stored by the program to compare user input to

void setup(){
  pinMode(control, OUTPUT);
  Serial.begin(9600);
  }




void loop(){
  int store = Serial.parseInt(); //this is a temporary storage to see if the user entered value is within the acceptable range
  if(store >= 500 && store <= 2000){ //comparing user input to range
  newrpm = store; //if user input has satisfied conditions, it is now set as the new rpm
  }
  if(newrpm != oldrpm){
  Serial.print("Setting RPM to "); 
  Serial.println(newrpm);  //indicates change to user
  Serial.print("Current RPM: ");
  Serial.println(newrpm);  //shows current RPM
  }
  
  pwmspeed = map(newrpm, 500, 2000, 50, 125);
  analogWrite(control, pwmspeed); 
  oldrpm = newrpm; //stores the current rpm for later comparison if a new value is entered by user
  delay(200);
}



void nothing(){ //tells program to do nothing
  
}
