#include "ros/ros.h"
#include <thread>
#include "tortuga_node.h"
#include "sensor_msgs/Joy.h"
#include "std_msgs/Float64MultiArray.h"


class JoyReader : public TortugaNode {

 public:
  JoyReader(int, char**, int);
  ~JoyReader();

  ros::NodeHandle n;

  ros::Subscriber subscriber;
  ros::Publisher publisher;

  void update();
  void publish();
  void joyPub(const std_msgs::Float64MultiArray );

};
