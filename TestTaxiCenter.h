
#ifndef EX2_TESTTAXICENTER_H
#define EX2_TESTTAXICENTER_H
#include <gtest/gtest.h>
#include "TaxiCenter.h"
//c
/*
 * Test class for taxiCenter.
 */
class TestTaxiCenter:public::testing::Test {
private:
    TaxiCenter tc;
public:
    void SetUp() {
        tc = TaxiCenter();
            cout << "Setting up.";
    }
    void TearDown() {
            cout << "Tearing Down.";

    }
};


#endif //EX2_TESTTAXICENTER_H
