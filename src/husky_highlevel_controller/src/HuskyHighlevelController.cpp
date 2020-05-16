#include "husky_highlevel_controller/HuskyHighlevelController.hpp"
//#include <sensor_msgs/LaserScan.h>
#include <ros/console.h>>
namespace husky_highlevel_controller {

HuskyHighlevelController::HuskyHighlevelController(ros::NodeHandle& nodeHandle) :
  nodeHandle_(nodeHandle)
{
	initSubscriber();
}

HuskyHighlevelController::~HuskyHighlevelController()
{
}

void HuskyHighlevelController::functionCallback(const sensor_msgs::LaserScan& message){
	ROS_INFO("Inside callback");
	ROS_INFO("%f and %f \n", message.range_min, message.range_max);
}

void HuskyHighlevelController::initSubscriber(){
	ros::Rate loop_rate(1.0);
	while(ros::ok()){
		std::string nameValue = "";
		int sizeValue=0;
		std::string topicName = 
			"topic/scan/name";
		std::string topicSize = 
			"topic/scan/queuesize";
		if(!nodeHandle_.getParam(topicName, nameValue)){
			ROS_ERROR("Could not found: topic name");
		}
		if(!nodeHandle_.getParam(topicSize, sizeValue)){
			ROS_ERROR("Could node found: toppic size");
		}
		ROS_INFO("Obtained : %s %d", nameValue.c_str(), sizeValue);
		subscriber_ = nodeHandle_.subscribe(nameValue, 1, &HuskyHighlevelController::functionCallback, this);
		std::string output = subscriber_.getTopic();
		//ROS_ERROR(output.c_str());
		ros::spin();
	}	
}
}/* namespace */
