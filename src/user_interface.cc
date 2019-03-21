#include "user_interface.h"

UserInterface::UserInterface(Battery& b, Robot& r) : Process("user input"), _battery(b), _robot(r) {
    initscr();   // Start ncurses
    timeout(1);  // Timeout for waiting for user input
    noecho();    // Do not echo user input to the screen
    curs_set(0); // Do not show the cursor
}

void UserInterface::show_battery() {

}

void UserInterface::show_robot() {
    
}

void UserInterface::update() {
    int c = getch();

    switch ( c ) {            
        case 's':
            emit(Event("start"));
            break;
        case 'r':
            emit(Event("reset"));               // Hidden command for testing (reset)
            break;
        case 'i':
            emit(Event("intruder detected"));   // Hidden command for testing (intruder!)
            break;
        case 'p':
            emit(Event("proximity warning"));   // Hidden command for testing (proximity!)
            break;
    }

    mvprintw(3,1,"start robot(s)");


    usleep(9999);
}