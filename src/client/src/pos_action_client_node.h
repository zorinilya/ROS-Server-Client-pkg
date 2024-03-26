#include <ros/ros.h>
#include <actionlib/client/simple_action_client.h>
#include <actionlib/client/terminal_state.h>
#include <server/PositionAction.h>
#include "std_msgs/Int64.h"


class PositionActionClient
{
public:
    PositionActionClient(std::string name);
    void sendGoal(int64_t goal);
    void cancelGoal();

public:
   ros::NodeHandle m_nodeHandle;
   actionlib::SimpleActionClient<server::PositionAction> m_actionService;
   std::string m_actionName;
//   actionlib::SimpleClientGoalState m_state;
   server::PositionGoal m_goal;

};
/*
int main (int argc, char **argv)
{
  ros::init(argc, argv, "test_fibonacci");

  // create the action client
  // true causes the client to spin its own thread
  actionlib::SimpleActionClient<actionlib_tutorials::FibonacciAction> ac("fibonacci", true);

  ROS_INFO("Waiting for action server to start.");
  // wait for the action server to start
  ac.waitForServer(); //will wait for infinite time

  ROS_INFO("Action server started, sending goal.");
  // send a goal to the action
  actionlib_tutorials::FibonacciGoal goal;
  goal.order = 20;
  ac.sendGoal(goal);

  //wait for the action to return
  bool finished_before_timeout = ac.waitForResult(ros::Duration(30.0));

  if (finished_before_timeout)
  {
    actionlib::SimpleClientGoalState state = ac.getState();
    ROS_INFO("Action finished: %s",state.toString().c_str());
  }
  else
  {
    ROS_INFO("Action did not finish before the time out.");
    ac.cancelGoal();
  }

  //exit
  return 0;
}
*/