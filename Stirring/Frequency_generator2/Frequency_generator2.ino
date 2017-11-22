int PWM = 4;

void setup() {
  // put your setup code here, to run once:
pinMode(PWM, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
analogWrite(PWM, 150);
}
