#include "ros/ros.h"
#include "server/Position.h"
#include "std_msgs/Int64.h"
#include <string>


class PositionClient
{
public:
    PositionClient(const std::string& service_name);
    bool sendRequest(int pos);

private:
    ros::NodeHandle m_nodeHandle;
    ros::ServiceClient m_client;
    std_msgs::Int64 m_position;
    server::Position m_service;
    std::string m_serviceName;
};