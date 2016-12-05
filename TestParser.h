
#ifndef TRY_TESTPARSER_H
#define TRY_TESTPARSER_H


#include <gtest/gtest.h>
#include "Parser.h"

class TestParser: public::testing::Test {
protected:
    Parser p;
public:
    void SetUp() {
        p = Parser();
    }
    void TearDown() {

    }
};


#endif //TRY_TESTPARSER_H
