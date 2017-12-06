int PWM = 4;  //P1.2

void setup() {

pinMode(PWM, OUTPUT);
}

void loop() {
analogWrite(PWM, 150);
}
