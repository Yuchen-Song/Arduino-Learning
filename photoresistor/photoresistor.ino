int ledPin=11;
int sensorPin=14;
int sensorValue,brightness=0;
void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  sensorValue=analogRead(sensorPin);
  brightness=map(sensorValue,100,500,0,255);
  if(brightness>0)
    analogWrite(ledPin, brightness);
  Serial.print("brightness:");
  Serial.println(brightness);
  //Serial.print("sensorValue:");
  //Serial.println(sensorValue);
}
