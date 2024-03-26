#include "ros/ros.h"
#include "robot.h"
#include "server/Position.h"
#include "std_msgs/Int64.h"
#include <string>


class PositionService
{
public:
    PositionService() = delete;
    PositionService(std::string service_name);
    void init();
    void setPosition(int pos);
    int getPosition();
    bool goToPosition(server::Position::Request &req, server::Position::Response &res);

private:
    ros::NodeHandle m_nodeHandle;
    ros::ServiceServer m_service;
    std_msgs::Int64 m_position;
    Robot m_robot;
    std::string m_serviceName;
};