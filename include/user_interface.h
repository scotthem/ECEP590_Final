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

    //! Create a new robot user interface using curses
    //! \param b A reference to a battery object
    //! \param r A reference to a robot object
    UserInterface(Battery& b, Robot& r);

    void init() {}
    void start() {}

    void show_battery(int x, int y, Battery::battery_status_type status, double charge);
    void show_robot(int x, int y, std::string state);

    //! Update the user interface by (a) reading keyboard input and (b) writing to the screen
    void update();
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