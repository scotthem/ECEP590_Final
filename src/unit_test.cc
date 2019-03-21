#include <iostream>
#include <string>
#include "gtest/gtest.h"

#include "robot.h"

namespace {
 
    using namespace elma;

    TEST(BATTERY, BASIC) {
        Battery battery = Battery("Li_Ion");

        Manager m;
        m.schedule(battery, 10_ms)
        .init();
        
        EXPECT_EQ(battery.status(), Battery::STANDBY);
        EXPECT_EQ(battery.charge(), 100);
        // std::cout << "Battery charge: " << battery.charge() << std::endl;

        m.emit(Event("start"));
        EXPECT_EQ(battery.status(), Battery::RUNNING);

        m.run(500_ms);

        EXPECT_NEAR(battery.charge(), 50, 2);
        // std::cout << "Battery charge: " << battery.charge() << std::endl;

        m.run(350_ms);

        EXPECT_EQ(battery.status(), Battery::LOW_BATTERY);
        EXPECT_NEAR(battery.charge(), 15, 2);
        // std::cout << "Battery charge: " << battery.charge() << std::endl;

        m.emit(Event("found recharge station"));
        EXPECT_EQ(battery.status(), Battery::CHARGING);

        m.run(1_s);

        EXPECT_EQ(battery.status(), Battery::RUNNING);
    }

    TEST(ROBOT, BASIC) {
        // create a new robot
        Robot robot = Robot("Johnny Five");
        // Robot robot = Robot(); // << this should also work

        // init manager
        Manager m;
        m.schedule(robot, 10_ms)
        .init()
        .start()
        .emit(Event("start"));

        string wander = "Wander";
        string noise = "Make Noise";
        string evade = "Evade";

        /*
        * Send signals to robot and test
        */
        // std::cout << robot.current().name() << std::endl;
        EXPECT_EQ(robot.current().name(), wander.c_str());

        m.emit(Event("intruder detected"));
        // std::cout << robot.current().name() << std::endl;
        EXPECT_EQ(robot.current().name(), noise.c_str());

        m.emit(Event("proximity warning"));
        // std::cout << robot.current().name() << std::endl;
        EXPECT_EQ(robot.current().name(), evade.c_str());

        m.emit(Event("battery full"));
        // std::cout << robot.current().name() << std::endl;
        EXPECT_EQ(robot.current().name(), evade.c_str());
    }

    TEST(COMBINED, BASIC) {
        Battery battery = Battery("Li_Ion");
        Robot robot = Robot("Johnny Five");

        Manager m;
        m.schedule(battery, 10_ms)
         .schedule(robot, 10_ms)
         .init()
         .start();

        string wander = "Wander";
        string noise = "Make Noise";
        string evade = "Evade";
        string idle = "Idle";
        string recharge = "Recharge";
        string find = "Find Recharge Station";

        EXPECT_EQ(robot.current().name(), idle.c_str());
        EXPECT_EQ(battery.status(), Battery::STANDBY);
        EXPECT_EQ(battery.charge(), 100);

        m.emit(Event("start"));
        EXPECT_EQ(battery.status(), Battery::RUNNING);
        EXPECT_EQ(robot.current().name(), wander.c_str());

        m.run(500_ms);

        EXPECT_NEAR(battery.charge(), 50, 2);

        m.run(350_ms);

        EXPECT_EQ(robot.current().name(), find.c_str());
        EXPECT_EQ(battery.status(), Battery::LOW_BATTERY);
        EXPECT_NEAR(battery.charge(), 15, 2);

    }
}