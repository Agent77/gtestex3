/*
 * The main class of the project is in charge of parsing
 * the input and creating the relevant
 * objects. then calling the method of the
 * BFS in order to get the right path.
 */

#include <iostream>
#include "Point.h"
#include "BFS.h"
#include "Driver.h"
#include "City.h"
#include "TaxiCenter.h"
#include <boost/lexical_cast.hpp>
#include <boost/tokenizer.hpp>
#include "GameFlow.h"
typedef boost::tokenizer<boost::char_separator<char>> tokenizer;

using namespace std;

int main() {
    GameFlow gf = GameFlow();
    gf.initialize();
    gf.run();
}

//int size[2];
//int i = 0;
/*boost::char_separator<char> sep{" "};
tokenizer tok{s, sep};
for (const auto &t : tok) {
    size[i] = boost::lexical_cast<int>(t);
    i++;
}*/

/*
    Point start = Point(1,1);
    Point end = Point(2,3);
    //Coordinate* obs = new Point(1,2);
    //Coordinate* obs2 = new Point(2,2);
    Graph* graphPointer;
    //sizes sent to grid
    Grid g = Grid(4,4);
    graphPointer = &g;
    BFS* bfs = new BFS(graphPointer, 6, 6, &start, &end);
    //bfs->addObstacles(obs);
    //bfs->addObstacles(obs2);
    bfs->getPath();
    delete bfs;
    return 0;*/


/*
 * converts the char to an int.
 */

