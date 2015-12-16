
// ROS
#include <ros/ros.h>
#include <std_msgs/String.h>
#include <sensor_msgs/Image.h>

// Local
#include "test_package/ImageConverter.h"

void chatterCallback(const std_msgs::String::ConstPtr & msg)
{
	ROS_INFO("Received message '%s'", msg->data.c_str());
}

int main(int argc, char ** argv) 
{

	ros::init(argc, argv, "listener_node");
	
    ROS_INFO("Listener node started");
    ROS_INFO("Listener node can receive : ");
    ROS_INFO("    a) text messges from 'talker_node' ");
    ROS_INFO("    b) images from 'cv_camera_no_yaml'");

    ros::NodeHandle nodeMsg;
	
	// Subscribe on the topic 'chatter'
    ros::Subscriber subMsg = nodeMsg.subscribe("chatter", 1000, &chatterCallback);

    // Initialize image converter
    ImageConverter ic("/cv_camera_no_yaml/image_raw", "/cv_camera_no_yaml/image_processed");

	// Enter a loop
	ros::spin();
	
	return 0;

}
