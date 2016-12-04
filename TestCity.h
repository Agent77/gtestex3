//
// Created by nirbs on 29/11/16.
//

#ifndef EX2_TESTCITY_H
#define EX2_TESTCITY_H
#include "gtest/gtest.h"
#include "City.h"
#include "GameFlow.h"
class TestCity:public::testing::Test {
protected:
    City c;
public:
    void SetUp() {
        c = City();
    }
};


#endif //EX2_TESTCITY_H
