#ifndef _ELMA_USERIF_H
#define _ELMA_USERIF_H

#include <iostream>
#include <ncurses.h>
#include "elma/elma.h"
#include "robot.h"

using namespace elma;

//! A user interface for the a Robot object
class UserInterface : public Process {

    public:

    //! Create a new robot user interface using ncurses
    //! \param b A reference to a battery object
    //! \param r A reference to a robot object
    UserInterface(Battery& b, Robot& r);

    //! Initialization method. Overrides the Process method. Sets 
    //! up the initial values and defaults for the user interface.  
    void init() {}

    //! Nothing to do to start
    void start() {}

    //! Method called by update() that displays information about the battery.
    //! \param x Position on the screen to print the battery information
    //! \param y Position on the screen to print the battery information
    //! \param status The status of the battery (a battery_status_type)
    //! \param charge The charge remaining on the batter in percent
    void show_battery(int x, int y, Battery::battery_status_type status, double charge);

    //! Method called by update() that displays information about the robot.
    //! \param x Position on the screen to print the battery information
    //! \param y Position on the screen to print the battery information
    //! \param status The status of the battery (a battery_status_type)
    void show_robot(int x, int y, std::string state);

    //! Update the user interface by showing the battery charge level
    //! and robot status on the screen
    void update();

    //! Nothing to do to stop.
    void stop() {}

    private:
    Battery& _battery;
    Robot& _robot;
    std::string _stby = "Standby";
    std::string _run = "Running";
    std::string _low_batt = "Low Battery";
    std::string _charge = "Charging";
};

#endif