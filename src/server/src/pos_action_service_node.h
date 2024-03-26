#include <ros/ros.h>
#include <actionlib/server/simple_action_server.h>
#include <server/PositionAction.h>
#include "std_msgs/Int64.h"
#include "robot.h"

class PositionAction
{
protected:
   ros::NodeHandle m_nodeHandle;
   actionlib::SimpleActionServer<server::PositionAction> m_actionService;
   server::PositionFeedback m_feedback;
   server::PositionResult m_result;
   std::shared_ptr<Robot> m_robot;
   std::string m_actionName;

public:
   PositionAction(std::string name);
   ~PositionAction(void) {}
   void executeCB(const server::PositionGoalConstPtr &goal);
};