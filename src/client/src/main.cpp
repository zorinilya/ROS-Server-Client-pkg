#include "pos_sub_node.h"
#include "pos_action_client_node.h"
#include "pos_client_node.h"


int main(int argc, char **argv) {
    ros::init(argc, argv, "client");
    ros::Time::init();
    PositionSubscriber posSub("current_pos_topic");
//    PositionClient posClient("pos_service");
    PositionActionClient posActionClient("pos_action");

    ROS_INFO("Start client");
    
//    while (ros::ok) {
        posActionClient.sendGoal(100);
//        loop_rate.sleep();
//    }
    ros::spin();

    return 0;
}