#ifndef _ELMA_BATTERY_H
#define _ELMA_BATTERY_H

#define LOW_CHARGE 20
#define FULL_CHARGE 100

#include "elma/elma.h"

using namespace elma;

//! A battery class, that inherits from Process
//! Models the charge and discharge of a battery when used by the Robot class
class Battery : public Process {
    public:
    
    //! Constructor that takes a name for the process
    Battery(std::string name) : Process(name) {}

    //! Constructor that creates an unnamed battery process
    Battery() : Process("unnamed battery") {}

    //! Initialization method. Overrides the Process method
    //! to initialize the battery. Sets initial status and 
    //! charge as well as setting up the event watches.
    void init() {
        _status = STANDBY;
        _charge = FULL_CHARGE;

        watch("start", [this](Event&) {
            _status = RUNNING;
        });

        watch("found recharge station", [this](Event&) {
            _status = CHARGING;
        });

        watch("battery full", [this](Event&) {
            _status = RUNNING;
        });
    }

    //! Nothing to do to start
    void start() {}

    //! Update method. Overrides the Process method. Models
    //! the charge and discharge curves of the batter. A
    //! simple linear model. Further work may be done to extend
    //! this to be more realistic.
    void update() {
        if(_status == CHARGING) {
            if(_charge == FULL_CHARGE) {
                _status = RUNNING;
                emit(Event("battery full"));
            } else {
                _charge += 1;
            }
        } else {
            _charge -= 1;

            if(_charge == LOW_CHARGE && _status == RUNNING) {
                _status = LOW_BATTERY;
                emit(Event("battery low"));
            }
        }
    }

    //! Nothing to do to stop.
    void stop() {}

    //! Enumeration for the status of the battery. Status can
    //! be obtained by using the status() getter.
    typedef enum { STANDBY, RUNNING, LOW_BATTERY, CHARGING } battery_status_type;
    
    //! Getter
    //! \return The charge remaining in the battery
    inline double charge() { return _charge; }

    //! Getter
    //! \return The status of the battery
    inline Battery::battery_status_type status() { return _status; }
    
    private:

    battery_status_type _status;
    double _charge;
};

#endif