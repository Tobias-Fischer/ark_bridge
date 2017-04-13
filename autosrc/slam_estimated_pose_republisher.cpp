///////////////////////////////////////////////////////////////////////
// This source was automatically generated by the ark_bridge package
///////////////////////////////////////////////////////////////////////
//
// Source message:    PoseWithCovarianceStamped.msg
// Creation:          Thu 13 Apr 2017 12:03:13 PM EDT
//
///////////////////////////////////////////////////////////////////////
#include <ros/ros.h>
#include <ros/console.h>
#include <string>

#include <lcm/lcm-cpp.hpp>

#include "ark_bridge/PoseWithCovarianceStamped.h"
#include "ark/PoseWithCovarianceStamped.hpp"

class LCMToROSRepublisher
{
    public:
        LCMToROSRepublisher(ros::NodeHandle& n);
        ~LCMToROSRepublisher();
        void lcmCallback(const lcm::ReceiveBuffer* rbuf,
                const std::string& channel_name,
                const ark::PoseWithCovarianceStamped* msg);
        
    private:        
        ros::NodeHandle nh;
        ros::Publisher ros_pub;   
};

LCMToROSRepublisher::LCMToROSRepublisher(ros::NodeHandle& n) 
{
    nh = n;
   
    // Publisher/s
    ros_pub = nh.advertise<ark_bridge::PoseWithCovarianceStamped>("slam_estimated_pose", 10);
    ROS_DEBUG("slam_estimated_pose publisher created");
};

LCMToROSRepublisher::~LCMToROSRepublisher() 
{    
    ROS_INFO("slam_estimated_pose LCMToROSRepublisher destructor.");
}

void LCMToROSRepublisher::lcmCallback(const lcm::ReceiveBuffer* rbuf,
        const std::string& channel_name,
        const ark::PoseWithCovarianceStamped* msg)
{
    ROS_DEBUG("Received message on channel \"%s\"", channel_name.c_str());
    
    const ark_bridge::PoseWithCovarianceStamped * new_ros_msg = reinterpret_cast<const ark_bridge::PoseWithCovarianceStamped *>(msg);
    ros_pub.publish(*new_ros_msg);
};
        

int main(int argc, char** argv)
{
    lcm::LCM lcm;
    if(!lcm.good())
        return 1;

    ros::init(argc, argv, "slam_estimated_pose_republish");
    ros::NodeHandle nh;   

    LCMToROSRepublisher handlerObject(nh);
    lcm.subscribe("slam_estimated_pose", &LCMToROSRepublisher::lcmCallback, &handlerObject);

    int lcm_timeout = 100; //ms
    while( ( lcm.handleTimeout(lcm_timeout) >= 0 ) && (ros::ok()) ) //
        ros::spinOnce();

    return 0;
}

