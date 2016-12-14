
#ifndef EX2_TESTBFS_H
#define EX2_TESTBFS_H

#include "Point.h"
#include "Grid.h"
#include "BFS.h"

#include <gtest/gtest.h>
/*
 * Test class for BFS.
 */
class TestBFS: public::testing::Test {
protected:
    BFS* bfs;
public:
    void SetUp() {
        Grid* g = new Grid(3, 3);
        bfs = new BFS(g);
    }
    void TearDown() {
        delete bfs;
    }
};


#endif //EX2_TESTBFS_H
