#include "ros/ros.h"
#include "robot.h"
#include "std_msgs/Int64.h"


class PositionPublisher
{
public:
    PositionPublisher();
    void init();
    int64_t getPosition();
    void publishPosition();

private:
    ros::NodeHandle m_nodeHandle;
    ros::Publisher m_posPub;
    std_msgs::Int64 m_position;
    Robot m_robot;
};