#include "ros/ros.h"
//#include "robot.h"
#include "server/Position.h"
#include "std_msgs/Int64.h"

// *****************************************************************
class Robot{
public:
    Robot();
    void SetPosition(int pos);
    int GetPosition() const;

private:
    int m_Position;
};

Robot::Robot()
    : m_Position(0)
{
}

void Robot::SetPosition(int pos) {
    m_Position = pos;
}

int Robot::GetPosition() const {
    return m_Position;
}
// *****************************************************************

bool add(server::Position::Request &req, server::Position::Response &res) {
    res.X = req.X;
    return true;
}

int main(int argc, char **argv) {
    Robot robot;
    ros::init(argc, argv, "server");
    ros::NodeHandle nh;

    ros::Publisher current_pos_pub = nh.advertise<std_msgs::Int64>("current_pos", 10);
    ros::Rate loop_rate(1);

    // service
    ros::ServiceServer service = nh.advertiseService("robot_pos", add);
    ROS_INFO("Service ready");
    
    while (ros::ok()) {
        std_msgs::Int64 msg;
        msg.data = robot.GetPosition();
        ROS_INFO("Current robot position: %ld", msg.data);
        current_pos_pub.publish(msg);
        ros::spinOnce();

        loop_rate.sleep();
    }

    return 0;
}