///////////////////////////////////////////////////////////////////////
// This source was automatically generated by the ark_bridge package
///////////////////////////////////////////////////////////////////////
//
// Source message:    String.msg
// Creation:          Thu 13 Apr 2017 12:03:13 PM EDT
//
///////////////////////////////////////////////////////////////////////
#include <ros/ros.h>
#include <ros/console.h>
#include <string>

#include <lcm/lcm-cpp.hpp>

#include "ark_bridge/String.h"
#include "ark/String.hpp"

class ROSToLCMRepublisher
{
    public:
        ROSToLCMRepublisher(ros::NodeHandle& n, lcm::LCM* lh);
        ~ROSToLCMRepublisher();
        void rosCallback(const ark_bridge::String::ConstPtr& msg);
        
    private:        
        lcm::LCM* lcm_handle;
        ros::NodeHandle nh;
        ros::Subscriber ros_sub;   
};

ROSToLCMRepublisher::ROSToLCMRepublisher(ros::NodeHandle& n, lcm::LCM* lh) 
{
    nh = n;
    lcm_handle = lh;
   
    // Subscribers
    ros_sub = nh.subscribe<ark_bridge::String>("control_selection_autonomy_disable_call", 10, &ROSToLCMRepublisher::rosCallback, this);
};

ROSToLCMRepublisher::~ROSToLCMRepublisher() 
{    
    ROS_INFO("control_selection_autonomy_disable_call ROSToLCMRepublisher destructor.");
}

void ROSToLCMRepublisher::rosCallback(const ark_bridge::String::ConstPtr& ros_msg)
{
    const ark::String* lcm_msg = reinterpret_cast<const ark::String*>( ros_msg.get() );
    lcm_handle->publish("control_selection_autonomy_disable_call", lcm_msg);
};
        

int main(int argc, char** argv)
{
    lcm::LCM* lcm_handle = new lcm::LCM("udpm://239.255.76.67:7667?ttl=1");
    if(!lcm_handle->good())
        return 1;

    ros::init(argc, argv, "control_selection_autonomy_disable_call_ros2lcm");
    ros::NodeHandle nh;   

    ROSToLCMRepublisher handlerObject(nh, lcm_handle);
    
    ros::spin();

    delete lcm_handle;
    return 0;
}

