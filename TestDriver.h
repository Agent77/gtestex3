#ifndef EX2_TESTDRIVER_H
#define EX2_TESTDRIVER_H

#include <gtest/gtest.h>
#include "Driver.h"

/*
 * Test class for Driver
 */
class TestDriver:public::testing::Test {
protected:
    Driver d;
public:
    void SetUp() {
        d = Driver(345, 22, 'W',3,15);
    }
};


#endif //EX2_TESTDRIVER_H
