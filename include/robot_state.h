#ifndef _ELMA_ROBOTSTATE_H
#define _ELMA_ROBOTSTATE_H
#include <iostream>
#include "elma/elma.h"

using namespace elma;

//! A robot state, that inherits from State and used in the Robot class
class RobotState : public State {
    public:
    
    //! Constructor that takes a name for the state
    RobotState(std::string name) : State(name) {}

    //! On entry show status message (comment out to hide!)
    void entry(const Event& e) {
        std::cout << "entering " + name() << "\n";
    }

    //! Nothing to do to during
    void during() {}

    //! On exit show status message (comment out to hide!)
    void exit(const Event&) {
        std::cout << "leaving " + name() << "\n";
    }
};

//! A robot state, that inherits from State and used in the Robot class.
//! Updates remote server upon entry, used to log significant events
class RobotPostState : public State {
    public:

    //! Constructor that takes a name for the state
    //! \param as A strting that is included in the alert message
    RobotPostState(std::string name, std::string as) : State(name), _alert_string(as) {}

    //! On entry show status message (comment out to hide!)
    //! and post message to the robot server (hard coded) at
    //! the moment but should be configurable somehow.
    //! TODO wrtie the bit that posts to the server.
    void entry(const Event& e) {
        json data;
        data["ALERT"] = _alert_string;
        std::cout << "entering " + name() << "\n";
    }

    //! Nothing to do to during
    void during() {}

    //! On exit show status message (comment out to hide!)
    void exit(const Event&) {
        std::cout << "leaving " + name() << "\n";
    }

    private:
    std::string _alert_string;
};

#endif