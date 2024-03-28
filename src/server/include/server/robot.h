#ifndef ROBOT
#define ROBOT

class Robot{
public:
    Robot();
    void setPosition(int pos);
    int getPosition() const;

private:
    int m_Position;
};
#endif