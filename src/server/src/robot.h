#ifndef ROBOT
#define ROBOT

class Robot{
public:
    Robot();
    void SetPosition(int pos);
    int GetPosition() const;

private:
    int m_Position;
};
#endif