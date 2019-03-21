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

    void show_battery();
    void show_robot();

    //! Update the user interface by (a) reading keyboard input and (b) writing to the screen
    void update();
    void stop() {}

    private:
    Battery& _battery;
    Robot& _robot;
};

#endif