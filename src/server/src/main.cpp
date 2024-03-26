//#include "server.h"
#include "pos_pub_node.h"
#include "pos_service_node.h"
#include "pos_client_node.h"


int main(int argc, char **argv) {
    ros::init(argc, argv, "server");
    ros::Time::init();
    ros::Rate loop_rate(10);
    PositionPublisher posPubNode;
    PositionService posService("pos_service");
    PositionClient posClient("pos_service");

    posPubNode.init();
    posService.init();
    posClient.init();
    ROS_INFO("Start server");
    
    while (ros::ok()) {
        posPubNode.publishPosition();
        ros::spinOnce();
        loop_rate.sleep();
    }

    return 0;
}