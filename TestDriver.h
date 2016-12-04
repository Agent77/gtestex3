//
// Created by Tiki Lobel on 12/1/16.
//

#ifndef EX2_TESTDRIVER_H
#define EX2_TESTDRIVER_H

#include <gtest/gtest.h>
#include "Driver.h"
class TestDriver:public::testing::Test {
protected:
    Driver d;
public:
    void SetUp() {
        d = Driver(345, 22, "WIDOW");
    }
};


#endif //EX2_TESTDRIVER_H
