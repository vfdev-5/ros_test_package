
// STD
#include <sstream>

// Ros
#include <ros/ros.h>
#include <std_msgs/String.h>
//#include "sensor_msgs/Image.h"

// cv_camera
//#include "cv_camera/capture.h"


const int32_t PUBLISHER_BUFFER_SIZE = 1;
const std::string FILE_PATH="/home/vfdev/Documents/cv_camera/test/capture.avi";


int main(int argc, char** argv) 
{
	// Initialize ROS and create a node named 'talker'
	ros::init(argc, argv, "talker_node");


	// Create a node with video 	
//	ros::NodeHandle private_node("~");
//	std::string frame_id("camera");
//	boost::shared_ptr<cv_camera::Capture> camera;
//	camera.reset(new cv_camera::Capture(private_node,
//										"image_raw",
//			                            PUBLISHER_BUFFER_SIZE,
//						                frame_id));
//	camera->openFile(FILE_PATH);
	
	// Create a node 
	ros::NodeHandle n;

	// Get publisher on the topic 'chatter'
	ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);

	// create loop
	ros::Rate loop_rate(0.05);

	int count = 0;
	while (ros::ok()) 
	{
		std_msgs::String msg;
		
		std::stringstream ss;
		ss << "Send message n=" << count;
		msg.data = ss.str();
		
		// Display in conslore
		ROS_INFO("%s", msg.data.c_str());
		
		// publish messge
		chatter_pub.publish(msg);
		
		// caputure an publish image
//		if (camera->capture())
//		{
//			camera->publish();
//		}
				
		ros::spinOnce();
		loop_rate.sleep();
		++count;
			
	}

	return 0;
}
