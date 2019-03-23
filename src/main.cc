#include <iostream>
#include <ncurses.h>
#include "elma/elma.h"

#include "robot.h"
#include "user_interface.h"

using namespace elma;

int main() {
    Battery battery = Battery("Li_Ion");
    Robot robot = Robot("Johnny Five");
    UserInterface ui = UserInterface(battery, robot);
    Manager m;

    m.schedule(ui, 10_ms)
     .schedule(battery, 1_s)
     .schedule(robot, 100_ms)
     .init()
     .run();

    endwin();
}