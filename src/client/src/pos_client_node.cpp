#include "pos_client_node.h"


PositionClient::PositionClient(const std::string& service_name)
    : m_serviceName(service_name)
    , m_client(m_nodeHandle.serviceClient<server::Position>(m_serviceName))
{
    ROS_INFO("PositionClient initialized");
}

bool PositionClient::sendRequest(int pos) {
    m_service.request.X = pos;
    if (m_client.call(m_service)) {
        ROS_INFO("Response: %ld", m_service.response.X);
        return true;
    }
    else {
        ROS_INFO("Fail to call the service");
        return false;
    }
}