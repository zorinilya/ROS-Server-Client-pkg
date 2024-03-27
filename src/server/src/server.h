#ifndef SERVER
#define SERVER

#include "pos_action_service_node.h"
#include "pos_service_node.h"
#include "pos_pub_node.h"

class Server
{
public:
    Server(Robot& robot);
    void publish();
private:
PositionAction m_posActionService;
PositionPublisher m_posPub;
PositionService m_posService;
std::shared_ptr<Robot> m_robot;
};
#endif // SERVER