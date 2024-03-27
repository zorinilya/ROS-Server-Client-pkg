#include <ros/ros.h>
#include <actionlib/client/simple_action_client.h>
#include <actionlib/client/terminal_state.h>
#include <server/PositionAction.h>
#include "std_msgs/Int64.h"


class PositionActionClient
{
public:
    PositionActionClient(const std::string& name);
    void sendGoal(int64_t goal);
    void cancelGoal();

public:
   ros::NodeHandle m_nodeHandle;
   actionlib::SimpleActionClient<server::PositionAction> m_actionService;
   std::string m_actionName;
   server::PositionGoal m_goal;
};
