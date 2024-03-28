#include "server/pos_pub_node.h"


PositionPublisher::PositionPublisher(const std::string& topic_name, Robot& robot)
    : m_posPub(m_nodeHandle.advertise<std_msgs::Int64>(topic_name, 10))
    , m_topicName(topic_name)
{
    m_robot = std::make_shared<Robot>(robot);
    ROS_INFO("PositionPublisher initialized");
}

int64_t PositionPublisher::getPosition() {
    return m_robot->getPosition();
}

void PositionPublisher::publishPosition() {
    m_position.data = getPosition();
    ROS_INFO("Server: current robot position: %ld", m_position.data);
    m_posPub.publish(m_position);
}