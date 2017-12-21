/*
  Project:two_serial_port
  Publisher Node:analog_data
  Subscriber Node:LED
  This program publishes analog sensor value(LDR) to a ROS node(ardrun.py)
  Change the serial port in the launch file
  Author:Visnu Ritesh, Research Trainee, Bluetronics
 */

#include <ros.h>
#include <ros/time.h>
#include <std_msgs/Int32.h>

ros::NodeHandle  nh;
std_msgs::Int32 range_msg;
ros::Publisher pub_range( "analog_data", &range_msg);

const int analog_pin = 0;
unsigned long range_timer;

float getData(int pin_num){
    int sample;
    // Get data
    sample = analogRead(pin_num);
    return sample;
    
}

char frameid[] = "/analog_sensor";

void setup()
{
  nh.initNode();
  nh.advertise(pub_range);
  Serial.begin(57600);
  
}

void loop()
{
    range_msg.data = getData(analog_pin);
    pub_range.publish(&range_msg);
  nh.spinOnce();
  delay(500);
}
