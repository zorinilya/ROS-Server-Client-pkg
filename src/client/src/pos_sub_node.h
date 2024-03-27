#include "ros/ros.h"
#include "std_msgs/Int64.h"


class PositionSubscriber
{
public:
    PositionSubscriber(const std::string& topic_name);
    void printPosition(std_msgs::Int64 current_pos);

private:
    ros::NodeHandle m_nodeHandle;
    ros::Subscriber m_posSub;
    int64_t m_position;
};