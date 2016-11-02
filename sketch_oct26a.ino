int trigPin=10;
int echoPin=11;
int k;
void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(4, OUTPUT);
  pinMode(6, OUTPUT);      // sets the digital pin as output
  pinMode(9, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(2, INPUT);
}
void loop() {
  digitalWrite(4, HIGH);
  k = analogRead(2);
  k=k/29.1;
  Serial.println(k);
  long duration, distance;
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  if (distance < 4 || k>  5) {  
  digitalWrite(6, LOW);   // slow down the wheel
  digitalWrite(9, LOW);   // slow down the wheel
  delay(100);
  digitalWrite(7, HIGH);   // sets the wheel forward
  digitalWrite(8, HIGH);   // sets the wheel forward
}
  else {
  digitalWrite(7, LOW);   // slow down the wheel
  digitalWrite(8, LOW);   // slow down the wheel
  delay(100);
  digitalWrite(6, HIGH);   // sets the wheel reverse
  digitalWrite(9, HIGH);   // sets the wheel reverse
  }
  if (distance >= 200 || distance <= 0){
    Serial.println("Out of range");
  }
  else {
    Serial.print(distance);
    Serial.println(" cm");
  }
}
