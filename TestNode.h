#ifndef EX2_TESTNODE_H
#define EX2_TESTNODE_H
#include <gtest/gtest.h>
#include "Node.h"
/*
 * Test class for Node.
 */
class TestNode:public::testing::Test {
protected:
    Node n;
};


#endif //EX2_TESTNODE_H