#include "user_interface.h"

UserInterface::UserInterface(Battery& b, Robot& r) : Process("user input"), _battery(b), _robot(r) {
    initscr();   // Start ncurses
    timeout(1);  // Timeout for waiting for user input
    noecho();    // Do not echo user input to the screen
    curs_set(0); // Do not show the cursor
}

void UserInterface::show_battery(int x, int y, Battery::battery_status_type status, double charge) {
    mvprintw(x,y, "Battery Level  : %.2f %%", charge);
                   
    if(status == Battery::STANDBY) {
        mvprintw(x+1,y,"Battery Status : Standby");
    } else if(status == Battery::RUNNING) {
        mvprintw(x+1,y,"Battery Status : Running");
    } else if(status == Battery::LOW_BATTERY) {
        mvprintw(x+1,y,"Battery Status : Low Battery!");
    } else if(status == Battery::CHARGING) {
        mvprintw(x+1,y,"Battery Status : Charging");
    } else {
        mvprintw(x+1,y,"BATTERY FAULT!");
    }
}

void UserInterface::show_robot(int x, int y, std::string state) {
    if(state == "Idle") {
        mvprintw(x,y,"Robot Status   : Idle");
    } else if(state == "Recharge") {
        mvprintw(x,y,"Robot Status   : Charging");
    } else if(state == "Wander") {
        mvprintw(x,y,"Robot Status   : Patrolling");
    } else if(state == "Find Recharge Station") {
        mvprintw(x,y,"Robot Status   : Looking for recharge station");
    } else if(state == "Evade") {
        mvprintw(x,y,"Robot Status   : Hiding!");
    } else if(state == "Make Noise") {
        mvprintw(x,y,"Robot Status   : Intruder detected!");
    } else {
        mvprintw(x,y,"ROBOT FAULT!");
    }
}

void UserInterface::update() {
    int c = getch();

    switch ( c ) {            
        case 's':
            emit(Event("start"));
            break;
        case 'r':
            emit(Event("reset"));                   // Hidden command for testing (reset)
            break;
        case 'i':
            emit(Event("intruder detected"));       // Hidden command for testing (intruder!)
            break;
        case 'p':
            emit(Event("proximity warning"));       // Hidden command for testing (proximity!)
            break;
        case 'f':
            emit(Event("found recharge station"));  // Hidden command for testing (found recharge)
            break;
    }

    clear();
    show_battery(1, 1, _battery.status(), _battery.charge());
    show_robot(3, 1, _robot.current().name());
    mvprintw(5,1,"start robot(s)");


    usleep(9999);
}