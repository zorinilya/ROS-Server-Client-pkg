#include "ros/ros.h"
#include "server/Position.h"


int main(int argc, char **argv) {
    ros::init(argc, argv, "client");
    ros::NodeHandle nh;

    ros::ServiceClient client = nh.serviceClient<server::Position>("robot_pos");
    
    server::Position srv;
    srv.request.X = 10;

    if(client.call(srv)) {
        ROS_INFO("Response: %ld", srv.response.X);
    }
    else {
        ROS_INFO("Fail to call the service");
        return 1;
    }

    ros::spin();

    return 0;
}