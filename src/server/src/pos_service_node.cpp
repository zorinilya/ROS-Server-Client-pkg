#include "pos_service_node.h"

PositionService::PositionService(std::string service_name, Robot& robot)
    : m_serviceName(service_name)
{
    m_robot = std::make_shared<Robot>(robot);
}

void PositionService::init() {
    m_service = m_nodeHandle.advertiseService("pos_service", &PositionService::goToPosition, this);
    ROS_INFO("PositionService initialized");
}

void PositionService::setPosition(int pos) {
    m_robot->setPosition(pos);
}

int PositionService::getPosition() {
    return m_robot->getPosition();
}

bool PositionService::goToPosition(server::Position::Request &req, server::Position::Response &res) {
    setPosition(req.X);
    res.X = getPosition();
    return req.X == res.X;
}