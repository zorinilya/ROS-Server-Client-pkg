#include "robot.h"

Robot::Robot()
    : m_Position(0)
{
}

void Robot::SetPosition(int pos) {
    m_Position = pos;
}

int Robot::GetPosition() const {
    return m_Position;
}