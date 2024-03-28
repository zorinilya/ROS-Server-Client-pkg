#include "server/robot.h"
#include <ros/ros.h>
#include <cstdint>

Robot::Robot()
    : m_Position(0)
{
}

void Robot::setPosition(int pos) {
    m_Position = pos;
}

int Robot::getPosition() const {
    return m_Position;
}