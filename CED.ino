#include <Servo.h> 

Servo bottom;
int bottomPos = 0;
int bottomMin = 70;
int bottomMax = 120;
int bottomSpeed = 1;

Servo middle;
int middlePos = 0;
int middleMin = 100;
int middleMax = 180;
int middleSpeed = 1;

Servo top;
int topPos = 0;
int topMin = 0;
int topMax = 180;
int topSpeed = 1;

void setup() 
{ 
  bottom.attach(9);
  middle.attach(10);
  top.attach(11);

  bottomPos = bottomMin;
  middlePos = middleMin;
  topPos = topMin;
} 
 
void loop() 
{ 
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

  delay(150);
} 
