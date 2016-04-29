#include "JoyReader.h"

JoyReader::JoyReader(int argc, char **argv, int rate):TortugaNode() {
    ros::Rate loop_rate(rate);
    subscriber = n.subscribe("joy", 1000, &JoyReader::joyPub, this);
    publisher = n.advertise<std_msgs::Float64MultiArray>("/joy_pub", 1000);
}

JoyReader::~JoyReader(){}

void JoyReader::update(){
	ros::spinOnce();
	
  	std_msgs::Float64MultiArray msg;
        msg.layout.dim[0].label = "Input";
        msg.layout.dim[0].size = 4;
        msg.layout.dim[0].stride = 4;
        msg.data[0] = x;
        msg.data[1] = y;
        msg.data[2] = z;
        msg.data[3] = mag;

        publisher.publish(msg);
}

void JoyReader::joyPub(const sensor_msgs::Joy::ConstPtr &joyInput) {
	x = joyInput->axes[0]; /* Side-to-side, between -1 and +1 */
	y = joyInput->axes[1]; 	
	z = -1*joyInput->axes[5]; 
	mag = (joyInput->axes[3]+1)/2; /* Magnitude, from 0 to +1 */
}

void JoyReader::publish() {

}
