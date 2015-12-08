
// ROS
#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sensor_msgs/Image.h>


void chatterCallback(const std_msgs::String::ConstPtr & msg)
{
	ROS_INFO("Received message '%s'", msg->data.c_str());
}


void imageCallback(const sensor_msgs::Image::ConstPtr& image)
{
	ROS_INFO("Received image %d x %d ", image->height, image->width);
}


int main(int argc, char ** argv) 
{

	ros::init(argc, argv, "listener_node");
	
	ros::NodeHandle nodeMsg, nodeImage;
	
	// Subscribe on the topic 'chatter'
	ros::Subscriber sub1 = nodeMsg.subscribe("chatter", 1000, &chatterCallback);
	ros::Subscriber sub2 = nodeImage.subscribe("image_raw", 1, &imageCallback);
	// Enter a loop
	ros::spin();
	
	return 0;

}
