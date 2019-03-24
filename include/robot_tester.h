#ifndef _ELMA_ROBOTTEST_H
#define _ELMA_ROBOTTEST_H

#include "elma/elma.h"
#include "robot.h"

using namespace elma;

//! A RobotTester class that inherits from Process
//! Used to create stimulus to test the Robot and
//! battery class.
class RobotTester : public Process {
    public:
    
    //! Constructor that creates a named RobotTester object
    //! /param b A reference to a battery object
    //! /param r A reference to a robot object
    RobotTester(std::string name, Battery& b, Robot& r) : Process(name), _battery(b), _robot(r) {}

    //! Constructor that creates an unnamed RobotTester object
    //! /param name A string name for the object
    //! /param b A reference to a battery object
    //! /param r A reference to a robot object
    RobotTester(Battery& b, Robot& r) : Process("unnamed tester"), _battery(b), _robot(r) {}

    //! Initialization method. Overrides the Process method. Sets 
    //! initial variable values.    
    void init() {
        _updates_counter = 0;
        _made_noise = false;
    }

    //! Nothing to do to start
    void start() {}

    //! Update method. Overrides the Process method. Provides
    //! stimulus in the form of Event() that are used to test
    //! the Robot and Battery objects. 
    //!
    //! TODO, this is not very "DRY" code, should look into refactoring 
    //! this.
    void update() {
        if(_battery.status() == Battery::LOW_BATTERY && (_robot.current().name() == "FindRechargeStation")) {
            if(_updates_counter == 10) {
                emit(Event("found recharge station"));
                _updates_counter = 0;
            } else {
                _updates_counter++;
            }
        }

        if(_robot.current().name() == "Idle") {
            if(_updates_counter == 5) {
                emit(Event("start"));
                _updates_counter = 0;
            } else {
                _updates_counter++;
            }
        }

        if(_robot.current().name() == "Wander") {
            if(_updates_counter == 10) {
                emit(Event("intruder detected"));
                _updates_counter = 0;
            } else {
                _updates_counter++;
            }
        }

        if(_robot.current().name() == "Make Noise") {
            if(!_made_noise) {
                if(_updates_counter == 10){
                    emit(Event("proximity warning"));
                    _made_noise = true;
                    _updates_counter = 0;
                } else {
                    _updates_counter++;
                }
            } else {
                if(_updates_counter == 10){
                    emit(Event("reset"));
                    _made_noise = false;
                    _updates_counter = 0;
                } else {
                    _updates_counter++;
                }
            }
        }

        if(_robot.current().name() == "Evade") {
            if(_updates_counter == 10) {
                emit(Event("reset"));
                _updates_counter = 0;
            } else {
                _updates_counter++;
            }
        }
    }

    //! Nothing to do to stop.
    void stop() {}

    private:
    Battery& _battery;
    Robot& _robot;
    bool _made_noise;
    int _updates_counter;
};

#endif

