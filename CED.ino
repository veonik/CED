#include <Servo.h> 

Servo bottom;
int bottomPos = 0;
int bottomMin = 80;
int bottomMax = 100;
int bottomSpeed = 2;

Servo middle;
int middlePos = 0;
int middleMin = 100;
int middleMax = 180;
int middleSpeed = 2;

Servo top;
int topPos = 0;
int topMin = 0;
int topMax = 180;
int topSpeed = 1;

// PIR sensor pin
int pirPin = 3;
unsigned long lastMovement = 0;

// Laser pointer pin
int laserPin = 4;

void setup() 
{ 
  bottom.attach(9);
  middle.attach(10);
  top.attach(11);

  bottomPos = bottomMin;
  middlePos = middleMin;
  topPos = topMin;
  
  pinMode(pirPin, INPUT);
  
  pinMode(laserPin, OUTPUT);
  
  Serial.begin(9600);
} 
 
void loop() 
{
  unsigned long time = millis();
  int sensorReading = digitalRead(pirPin);
  if (sensorReading == 1) {
    lastMovement = time;
  }
  
  // If nothing has moved in 60 seconds, stop
  if (lastMovement + 60000 <= time) {
    move();
  } else {
    digitalWrite(laserPin, LOW);
  }

  delay(50);
}

void move() {
  digitalWrite(laserPin, HIGH);
  
  bottom.write(bottomPos);
  middle.write(middlePos);
  top.write(topPos);

  // Switch directions if either limit is reached
  if (bottomPos >= bottomMax || bottomPos < bottomMin) {
    bottomSpeed *= -1;
  }

  if (middlePos >= middleMax || middlePos < middleMin) {
    middleSpeed *= -1;
  }

  if (topPos >= topMax || topPos < topMin) {
    topSpeed *= -1;
  }

  bottomPos += bottomSpeed;
  middlePos += middleSpeed;
  topPos += topSpeed;
}
