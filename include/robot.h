#include <iostream>
#include <chrono>
#include "elma/elma.h"

using namespace elma;

/*!
 * This is an internally used by Robot. We won't be testing this class.
 */
class RobotState : public State {
public:
    RobotState(std::string name) : State(name) {}
    void entry(const Event& e) {}
    void during() {}
    void exit(const Event&) {}
};

class Robot : public StateMachine {
public:
    Robot(std::string name) : StateMachine(name) {
        set_initial(Idle);
        add_transition("start", Idle, Wander);

        add_transition("battery low", Wander, FindRechargeStation);
        add_transition("intruder detected", Wander, MakeNoise);
        
        add_transition("found recharge station", FindRechargeStation, Recharge);

        add_transition("battery full",Recharge, Wander);

        add_transition("reset", MakeNoise, Wander);
        add_transition("proximity warning", MakeNoise, Evade);
        
        add_transition("reset", Evade, MakeNoise);
        add_transition("battery low", Evade, FindRechargeStation);
    }

    Robot() : StateMachine("Some unnamed robot") {
        set_initial(Idle);
        add_transition("start", Idle, Wander);

        add_transition("battery low", Wander, FindRechargeStation);
        add_transition("intruder detected", Wander, MakeNoise);
        
        add_transition("found recharge station", FindRechargeStation, Recharge);

        add_transition("battery full",Recharge, Wander);

        add_transition("reset", MakeNoise, Wander);
        add_transition("proximity warning", MakeNoise, Evade);
        
        add_transition("reset", Evade, MakeNoise);
        add_transition("battery low", Evade, FindRechargeStation);
    }

private:
    RobotState Idle = RobotState("Idle");
    RobotState Recharge = RobotState("Recharge");
    RobotState Wander = RobotState("Wander");
    RobotState FindRechargeStation = RobotState("Find Recharge Station");
    RobotState Evade = RobotState("Evade");
    RobotState MakeNoise = RobotState("Make Noise");
};