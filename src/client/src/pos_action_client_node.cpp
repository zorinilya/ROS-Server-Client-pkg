#include "pos_action_client_node.h"


PositionActionClient::PositionActionClient(std::string name)
    : m_actionService(name, true),
        m_actionName(name)
{
    ROS_INFO("Waiting for action server to start.");
    // wait for the action server to start
    m_actionService.waitForServer(); //will wait for infinite time
    ROS_INFO("Action server started");
}

void PositionActionClient::sendGoal(int64_t goal) {
    m_actionService.sendGoal(m_goal);
    bool finished_before_timeout = m_actionService.waitForResult(ros::Duration(30.0));
    if (finished_before_timeout)
    {
        actionlib::SimpleClientGoalState state = m_actionService.getState();
        ROS_INFO("Action finished: %s", state.toString().c_str());
    }
    else
    {
        ROS_INFO("Action did not finish before the time out.");
        cancelGoal();
    }
}

void PositionActionClient::cancelGoal() {
    m_actionService.cancelGoal();
}