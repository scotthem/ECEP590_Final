#include "robot.h"

Robot::Robot(std::string name) : StateMachine(name) {
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

Robot::Robot() : StateMachine("Some unnamed robot") {
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