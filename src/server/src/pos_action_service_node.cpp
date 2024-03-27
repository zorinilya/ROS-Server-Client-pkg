#include "pos_action_service_node.h"

PositionAction::PositionAction(const std::string& name, Robot& robot)
   : m_actionService(m_nodeHandle, name, boost::bind(&PositionAction::executeCB, this, _1), false),
      m_actionName(name)
{
   m_robot = std::make_shared<Robot>(robot);
   m_actionService.start();
   ROS_INFO("PositionAction initialized");
}

void PositionAction::executeCB(const server::PositionGoalConstPtr &goal)
{
   // helper variables
   ros::Rate r(1);
   bool success = true;

   m_feedback.position = m_robot->getPosition();

   // publish info to the console for the user
   ROS_INFO("%s: Executing, robot runs to target position %ld with seeds", m_actionName.c_str(), goal->order);

   // start executing the action
   ROS_INFO("Feedback: %ld, Goal: %ld", m_feedback.position, goal->order);
   while (m_feedback.position != goal->order) {
      // check that preempt has not been requested by the client
      ROS_INFO("Robot running");
      if (m_actionService.isPreemptRequested() || !ros::ok())
      {
         ROS_INFO("%s: Preempted", m_actionName.c_str());
         // set the action state to preempted
         m_actionService.setPreempted();
         success = false;
         break;
      }
      if (m_feedback.position < goal->order) {
         ++m_feedback.position;
      }
      else {
         --m_feedback.position;
      }
      ROS_INFO("Feedback: %ld", m_feedback.position);
      m_robot->setPosition(m_feedback.position);
      ROS_INFO("Robot position: %ld", m_robot->getPosition());
      m_feedback.position = m_robot->getPosition();
      ROS_INFO("Feedback after robot->getPosition(): %ld", m_feedback.position);
      m_actionService.publishFeedback(m_feedback);
      r.sleep();
   }
   if (success)
   {
      m_result.position = m_feedback.position;
      ROS_INFO("%s: Succeeded", m_actionName.c_str());
      // set the action state to succeeded
      m_actionService.setSucceeded(m_result);
   }
}