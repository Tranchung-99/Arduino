#include "ros.h"
#include "std_msgs/Empty.h"

ros::NodeHandle nh;

void messageCb(const std_msgs::Empty&toggle_msg)
{
  digitalWrite(3,HIGH);
  digitalWrite(5,HIGH);
}

ros::Subscriber<std_msgs::Empty> sub("dcmotor", &messageCb );

void setup() {
  // put your setup code here, to run once:
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  analogWrite(4,150);
  analogWrite(6,150);
  nh.initNode();
  nh.subscribe(sub);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  nh.spinOnce();
  delay(1);
  
  
}
