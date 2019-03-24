#ifndef _ELMA_ROBOT_H
#define _ELMA_ROBOT_H

#include "battery.h"
#include "robot_state.h"

using namespace elma;

//! A robot class, that inherits from StateMachine
class Robot : public StateMachine {
public:
    //! Constructor that creates a named RobotTester object
    //! Contains state declaration and transitions
    Robot(std::string name);

    //! Constructor that creates an unnamed named RobotTester object
    //! Contains state declaration and transitions
    Robot();

private:
    RobotState Idle = RobotState("Idle");
    RobotState Recharge = RobotState("Recharge");
    RobotState Wander = RobotState("Wander");
    RobotState FindRechargeStation = RobotState("Find Recharge Station");
    RobotState Evade = RobotState("Evade");
    RobotState MakeNoise = RobotState("Make Noise");
};

#endif