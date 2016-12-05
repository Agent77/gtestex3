
#ifndef EX2_TESTCITY_H
#define EX2_TESTCITY_H
#include "gtest/gtest.h"
#include "City.h"
#include "GameFlow.h"

/*
 * Test class for City class
 */
class TestCity:public::testing::Test {
protected:
    City c;
public:
    void SetUp() {
        c = City();
    }
};


#endif //EX2_TESTCITY_H
