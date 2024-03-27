#include "server.h"
#include "pos_action_service_node.h"
#include "pos_pub_node.h"
#include "pos_service_node.h"


int main(int argc, char **argv) {
    ros::init(argc, argv, "server");
    ros::Time::init();
    ros::Rate loop_rate(1);
    Robot robot_A;
    Server server(robot_A);
//    PositionAction posAction("pos_action", robot_A);
//    PositionPublisher posPubNode("current_pos_topic", robot_A);
//    PositionService posService("pos_service", robot_A);
   
    while (ros::ok()) {
        server.publish();
        ros::spinOnce();
        loop_rate.sleep();
    }

    return 0;
}