int readings[3];

void setup() {
Serial.begin(9600);
}

int rootms(int list[3]) {
  int average = 0;
  for (int i = 0; i < 3; i++){
    average += list[i];
  }
  average = average / 3;
  return average;
}

void loop() {
  Serial.print("ARRAY: [");
  for (int i = 0; i < 3; i++) {
    
    Serial.print(readings[i]);
    Serial.print(" ");
  }
  Serial.println("]");
  //int average = rootms(readings);
  Serial.print("AVERAGE: ");
  //Serial.println(average);
  
}
