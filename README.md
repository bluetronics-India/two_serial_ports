### ROS package for connecting two serial ports and establising publisher & subscriber ### 
### Bluetronics ###


The section contains ROS package and sample arduino codes to establish serial communication between two serial ports 
of arduino where one arduino connected with LDR (analog sensor) acts as publisher and the other arduino connected with LED(PWM output) acts as subscriber.
the LED brightness is controlled depending upon the LDR output values. 


The publisher and subcriber nodes are created for the respective arduino boards and managed and monitored by ROS. ROS kinetic is used here.
The values are monitored in ROS by both serial and in rqt_plot.   