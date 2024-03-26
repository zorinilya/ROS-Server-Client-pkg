#include "pos_sub_node.h"
#include "pos_client_node.h"


int main(int argc, char **argv) {
    ros::init(argc, argv, "client");
    ros::Time::init();
    PositionSubscriber posSub;
    PositionClient posClient("pos_service");

    posSub.init();
    posClient.init();
    ROS_INFO("Start client");
    
    ros::spin();

    return 0;
}