#include "pos_pub_node.h"


PositionPublisher::PositionPublisher()
{
}
    
void PositionPublisher::init() {
    m_posPub = m_nodeHandle.advertise<std_msgs::Int64>("current_pos_topic", 10);
    ROS_INFO("PositionPublisher initialized");
}

int64_t PositionPublisher::getPosition() {
    return m_robot.getPosition();
}

void PositionPublisher::publishPosition() {
    m_position.data = getPosition();
    ROS_INFO("Server: current robot position: %ld", m_position.data);
    m_posPub.publish(m_position);
}