int redled = 5;
int blueled = 6;
int greenled = 2;
int buttonpin = 3;
int x = 0;
#define echoPin 9
#define trigPin 8

long duration;
int distance;


void setup() {
pinMode(redled, OUTPUT);
pinMode(greenled, OUTPUT);
pinMode(blueled, OUTPUT);
pinMode(buttonpin, INPUT);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
Serial.begin(9600);
Serial.println("Ultasonic Sensor test");

}

void loop() {
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance = duration * 0.034/2;
Serial.print("Distance: ");
Serial.print(distance);
Serial.println(" cm");
if (distance <= 20) 
{
  digitalWrite(redled, HIGH);
  digitalWrite(greenled, LOW);
  digitalWrite(blueled, LOW);
}  
if (distance > 20 && distance <= 50) {
digitalWrite(redled, LOW);
digitalWrite(greenled, HIGH);
digitalWrite(blueled,LOW);
}
if (distance > 50)
{
  digitalWrite(redled, LOW);
  digitalWrite(greenled, LOW);
  digitalWrite(blueled, HIGH);
}

//delay(1000);
//digitalWrite(ledpin,LOW);
//delay(1000);

}
