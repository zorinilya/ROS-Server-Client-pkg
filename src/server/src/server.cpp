#include "server.h"

Server::Server(Robot& robot)
    : m_posActionService("pos_action", robot)
    , m_posPub("current_pos_topic", robot)
    , m_posService("pos_service", robot)
{
    m_robot = std::make_shared<Robot>(robot);
    ROS_INFO("Start server");
}

void Server::publish() {
    m_posPub.publishPosition();
}