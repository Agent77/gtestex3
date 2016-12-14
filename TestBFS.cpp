
#include "gtest/gtest.h"
#include "TestBFS.h"
#include "BFS.h"
/*
 * Checks if the path printing by the BFS
 * comes out in correct order and correct format.
 */
TEST_F(TestBFS, getPath) {
    bfs->getPath();
    testing::internal::CaptureStdout();
    bfs->PrintPath(bfs->getSource(), bfs->getDest());
    std::string output = testing::internal::GetCapturedStdout();
    string str = "(0,0)\n(0,1)\n";
    ASSERT_EQ(output, str) << "Incorrect Path!";
}

TEST_F(TestBFS, NextPlaceInPath) {
    Point* p = new Point(0,0);
    Point* p2 = new Point(0,2);
    Point* correctNext = new Point(0,1);
    Coordinate* next = bfs->getNextInPath(p, p2);
    ASSERT_TRUE(next->getMyLocation()->equalTo(correctNext)) << "Next In Path incorrect.";
    delete correctNext;
    Grid* g = new Grid(3, 3);
    g->addObstacle(correctNext);
    BFS bfsWithObstacles = BFS(g);
    next = bfsWithObstacles.getNextInPath(p,p2);
    correctNext = new Point(1,0);
    ASSERT_TRUE(next->getMyLocation()->equalTo(correctNext)) << "Next In Path incorrect with Obstacles.";
    delete p;
    delete p2;
    delete correctNext;
    delete g;
}

/*
 * Tests the visit neighbors function of the BFS,
 * ensuring they are returned in the right order
 * and with the right values.
 */
TEST_F(TestBFS,visitNeighbors){
    Point* np = new Point(1,1);
    Node *n= new Node(np);
    Point p[4];
    std::vector<Node*> neighbors = bfs->visitNeighbors(n);
    //Neighbors of (1,1)
     p[0] =  Point(0,1);
     p[1] =  Point(1,2);
     p[2] =  Point(2,1);
     p[3] =  Point(1,0);
    vector<Node *>::iterator v = neighbors.begin();
    int i = 0;
    while (v != neighbors.end()) {
        Point* neighbor = (Point*)(*(*(v))).getMyLocation();
        //Checks that points are identical
        ASSERT_TRUE(p[i].equalTo(neighbor)) << "visitNeighbors didn't find the correct neighbors";
        i++;
        v++;
    }
    delete np;
    delete n;

}
//c