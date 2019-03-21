#ifndef _ELMA_ROBOTSTATE_H
#define _ELMA_ROBOTSTATE_H
#include <iostream>
#include "elma/elma.h"

using namespace elma;

//! A robot state, that inherits from State and used in the Robot class
class RobotState : public State {
    public:
    RobotState(std::string name) : State(name) {}
    void entry(const Event& e) {
        std::cout << "entering " + name() << "\n";
    }
    void during() {}
    void exit(const Event&) {
        std::cout << "leaving " + name() << "\n";
    }
};

#endif