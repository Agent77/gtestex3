
#include "GameFlow.h"
#include "StandardCab.h"
#include "LuxuryCab.h"
#include <iostream>

typedef boost::tokenizer<boost::char_separator<char>> tokenizer;

void GameFlow::initialize() {
    string obstacles;
    string size1;
    string size2;

    //To be used later as graph size
    cin >> size1;
    cin >> size2;
    Graph *grid = city.createGraph(size1, size2);

    //Checks for obstacles
    cin >> obstacles;
    int obstacleCount = boost::lexical_cast<int>(obstacles);
    if (obstacleCount != 0) {
        string obstacle;
        for (int count = 0; count < obstacleCount; count++) {
            cin >> obstacle;
            Coordinate* c = city.createCoordinate(obstacle);
            grid->addObstacle(c);
        }
    }
    BFS *bfs = new BFS(grid);
    tc = TaxiCenter(grid);
}

void GameFlow::run() {
    int run = 1;
    int action1;
    int driverId;
    std::string s;


    while (run) {
        cin >> action1;
        int action = boost::lexical_cast<int>(action1);
        switch(action) {
            case 1: //Insert Driver
            {
                cin >> s;
                Driver d = city.createDriver(s);
                tc.addDriver(d);
                break;
            }
            case 2: {
                cin >> s;
                Trip t = city.createTrip(s);
                tc.addTrip(t);
                break;
            }
            case 3: {
                cin >> s;
                Taxi t = city.createTaxi(s);
                tc.addTaxi(t);
                break;
            }
            case 4: {
                cin >> driverId;
                tc.requestDriverLocation(driverId);
                break;
            }
            case 6: {
                tc.driveAll();
                break;
            }
            case 7:
                run = 0;
                break;
            default:
                break;
        }
    }
}

