
#include "gtest/gtest.h"
#include "TestBFS.h"
#include "BFS.h"

TEST_F(TestBFS, getPath) {
    bfs->getPath();
    testing::internal::CaptureStdout();
    bfs->PrintPath(bfs->getSource(), bfs->getDest());
    std::string output = testing::internal::GetCapturedStdout();
    string str = "(0,0)\n(0,1)\n";
    ASSERT_EQ(output, str) << "Incorrect Path!";
}

TEST_F(TestBFS,visitNeighbors){
    Point* np = new Point(1,1);
    Node *n= new Node(np);
    Point p[4];
    std::vector<Node*> neighbors = bfs->visitNeighbors(n);
     p[0] =  Point(0,1);
     p[1] =  Point(1,2);
     p[2] =  Point(2,1);
     p[3] =  Point(1,0);
    /*Node* first = new Node(p);
    Node* second = new Node (p2);
    Node* third = new Node (p3);
    Node* fourth = new Node(p4);
    std::vector<Node*> v;
    v.push_back(first);
    v.push_back(second);
    v.push_back(third);
    v.push_back(fourth);*/
    vector<Node *>::iterator v = neighbors.begin();
    int i = 0;
    while (v != neighbors.end()) {
        Point* neighbor = (Point*)(*(*(v))).getMyLocation();
        ASSERT_TRUE(p[i].equalTo(neighbor)) << "visitNeighbors didn't find the correct neighbors";
        i++;
        v++;
    }
    delete np;
    delete n;

}