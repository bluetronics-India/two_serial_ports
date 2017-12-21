/*
  Project:two_serial_port
  Publisher Node:analog_data
  Subscriber Node:LED
  This program subscribes from ardrun.py and makes the LED glow accordingly.
  Change the serial port in launch file
  Author:Visnu Ritesh, Research Trainee, Bluetronics
 */

#include <ros.h>
#include <std_msgs/Int32.h>

ros::NodeHandle nh;

void messageCb(const std_msgs::Int32& msg)
{
  analogWrite(11,msg.data);
}

ros::Subscriber<std_msgs::Int32> sub("LED", &messageCb);

void setup()
{
  pinMode(11, OUTPUT);
  nh.initNode();
  nh.subscribe(sub);
}

void loop()
{
  nh.spinOnce();
  delay(10);
}
analogWrite(11,0);
