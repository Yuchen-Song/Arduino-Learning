int LEDpin=13;
int sensorPin=12;

void setup() {
  // put your setup code here, to run once:
  pinMode(LEDpin,OUTPUT);
  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  int state=digitalRead(sensorPin);
  digitalWrite(LEDpin, state);
  Serial.println(state);
}
