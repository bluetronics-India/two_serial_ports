#!/usr/bin/env python
#  Project:two_serial_port
#  Publisher Node:analog_data
#  Subscriber Node:LED
#  This program subscribes from publisher.ino(analog_data) and publishes it to subscriber.ino(LED)
#  Change the serial port in the launch file
#  The analog values can be viewed in rqt_plot and terminal
#  Author:Visnu Ritesh, Research Trainee, Bluetronics

import rospy

from std_msgs.msg import Int32

var=None

#define the display text
def callback(msg):
    global var
    var=msg.data

 
if __name__=='__main__':
    rospy.init_node('random_LED')
    rospy.Subscriber('analog_data',Int32, callback)
    pub=rospy.Publisher('LED', Int32)
    rate=rospy.Rate(10)

    while not rospy.is_shutdown():
        if var>=0 and var<=255:
            varP=var
            rospy.loginfo("Value: %s", var)
            pub.publish(var)
            rate.sleep()
