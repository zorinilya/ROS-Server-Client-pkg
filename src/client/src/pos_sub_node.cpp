#include "pos_sub_node.h"


PositionSubscriber::PositionSubscriber()
{
}
    
void PositionSubscriber::init() {
    m_posSub = m_nodeHandle.subscribe("current_pos_topic", 10, &PositionSubscriber::printPosition, this);
    ROS_INFO("PositionSubscriber initialized");
}

void PositionSubscriber::printPosition(std_msgs::Int64 current_pos) {
    m_position = current_pos.data;
    ROS_INFO("Client: current robot position: %ld", m_position);
}

