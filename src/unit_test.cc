#include <iostream>
#include "gtest/gtest.h"

#include "battery.h"

using namespace elma;

TEST(BATTERY, BASIC) {
    Battery battery = Battery("Li_Ion");

    Manager m;
    m.schedule(battery, 10_ms)
        .init()
        .start()
    
    EXPECT_EQ(battery.status(),RUNNING);
    EXPECT_EQ(battery.charge(),100);

    m.emit(Event("found recharge station"));
}

GTEST_API_ int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}