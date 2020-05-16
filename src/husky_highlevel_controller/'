#include <ros/ros.h>
#include "husky_highlevel_controller/HuskyHighlevelController.hpp"


int main(int argc, char** argv)
{
  ros::init(argc, argv, "subscriber_node");
  ros::NodeHandle nodeHandle("~");
  husky_highlevel_controller::HuskyHighlevelController hcontroller(nodeHandle);
  
  ros::spin();
  return 0;
}
