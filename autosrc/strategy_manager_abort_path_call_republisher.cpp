///////////////////////////////////////////////////////////////////////
// This source was automatically generated by the ark_bridge package
///////////////////////////////////////////////////////////////////////
//
// Source message:    Empty.msg
// Creation:          Thu 13 Apr 2017 12:03:13 PM EDT
//
///////////////////////////////////////////////////////////////////////
#include <ros/ros.h>
#include <ros/console.h>
#include <string>

#include <lcm/lcm-cpp.hpp>

#include "ark_bridge/Empty.h"
#include "ark/Empty.hpp"

class ROSToLCMRepublisher
{
    public:
        ROSToLCMRepublisher(ros::NodeHandle& n, lcm::LCM* lh);
        ~ROSToLCMRepublisher();
        void rosCallback(const ark_bridge::Empty::ConstPtr& msg);
        
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
    ros_sub = nh.subscribe<ark_bridge::Empty>("strategy_manager_abort_path_call", 10, &ROSToLCMRepublisher::rosCallback, this);
};

ROSToLCMRepublisher::~ROSToLCMRepublisher() 
{    
    ROS_INFO("strategy_manager_abort_path_call ROSToLCMRepublisher destructor.");
}

void ROSToLCMRepublisher::rosCallback(const ark_bridge::Empty::ConstPtr& ros_msg)
{
    const ark::Empty* lcm_msg = reinterpret_cast<const ark::Empty*>( ros_msg.get() );
    lcm_handle->publish("strategy_manager_abort_path_call", lcm_msg);
};
        

int main(int argc, char** argv)
{
    lcm::LCM* lcm_handle = new lcm::LCM("udpm://239.255.76.67:7667?ttl=1");
    if(!lcm_handle->good())
        return 1;

    ros::init(argc, argv, "strategy_manager_abort_path_call_ros2lcm");
    ros::NodeHandle nh;   

    ROSToLCMRepublisher handlerObject(nh, lcm_handle);
    
    ros::spin();

    delete lcm_handle;
    return 0;
}

