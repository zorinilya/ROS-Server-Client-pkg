#include "server/pos_service_node.h"

PositionService::PositionService(const std::string& service_name, Robot& robot)
    : m_service(m_nodeHandle.advertiseService(service_name, &PositionService::goToPosition, this))
    , m_serviceName(service_name)
{
    m_robot = std::make_shared<Robot>(robot);
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