#include "MazeGame.h"
//Client for the MazeFactory
MazeGame::MazeGame()
{
    //ctor
}

MazeGame::~MazeGame()
{
    //dtor
}


Maze* MazeGame::CreateMaze(Mazefactory& factory)
{
    Maze * aMaze = factory.MakeMaze();
    Room* r1 = factory.MakeRoom(1);
    Room* r2 = factory.MakeRoom(2);
    Door* aDoor = factory.MakeDoor(r1,r2);

    aMaze->AddRoom(r1);
    aMaze->AddRoom(r2);

    r1->SetSide(North, aDoor);
    r1->SetSide(East, factory.MakeWall());
    r1->SetSide(West, factory.MakeWall());
    r1->SetSide(South, factory.MakeWall());

    r2->SetSide(North,factory.MakeWall());
    r2->SetSide(East, factory.MakeWall());
    r2->SetSide(West, factory.MakeWall());
    r2->SetSide(South,aDoor);

    return aMaze;
}
