#include "ros/ros.h"
#include "robot.h"
#include "std_msgs/Int64.h"


class PositionPublisher
{
public:
    PositionPublisher(const std::string& topic_name, Robot& robot);

    int64_t getPosition();
    void publishPosition();

private:
    std::string m_topicName;
    ros::NodeHandle m_nodeHandle;
    ros::Publisher m_posPub;
    std_msgs::Int64 m_position;
    std::shared_ptr<Robot> m_robot;
};