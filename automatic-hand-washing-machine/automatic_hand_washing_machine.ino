//Project Descriptions

//Declaring constants and variables
#define trig 5
#define echo 4
int waterRelay = 6;
int soapRelay = 7;
long duration;
int distance;

void setup() {
  // put your setup code here, to run once:
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(waterRelay, OUTPUT);
  pinMode(soapRelay, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trig, LOW);
  delayMicroseconds(5);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  
  duration = pulseIn(echo, HIGH);
  distance = (duration/2) * (331.3/10000); //Speed of sound in air = 331.29 m/s
  Serial.println(distance);
  
  if (distance > 1 && distance < 10) {
    digitalWrite(soapRelay, HIGH); //Turn on soap pump for 4 seconds
    delay(3000);
    digitalWrite(soapRelay, LOW); //Turn off soap pump
    digitalWrite(waterRelay, HIGH); //Turn on water pump for 20 seconds
    delay(20000);
    digitalWrite(waterRelay, LOW); //Turn off water pump
  }else{
    digitalWrite(soapRelay, LOW);
    digitalWrite(waterRelay, LOW);
  }
  
}
