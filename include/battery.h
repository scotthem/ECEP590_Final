#include <iostream>
#include <chrono>
#include "elma/elma.h"

using namespace elma;

class Battery : public Process {
    public:
    Battery(std::string name) : Process(name) {}

    void init() {
        _status = RUNNING;
        _charge = 100;

        watch("found recharge station", [this](Event&) {
            _status = CHARGING;
        });
        watch("battery full"), [this](Event&) {
            _status = RUNNING;
        });
    }
    void start() {}
    void update() {}
    void stop() {}

    inline double charge() { return _charge};
    inline battery_status_type status() { return _status};
    
    typedef enum { RUNNING, CHARGING } battery_status_type;

    private:
    battery_status_type _status
    double _charge
}