#ifndef MAZEFACTORY_H
#define MAZEFACTORY_H


#include "Door.h"
#include "Maze.h"
#include "Wall.h"
class Mazefactory
{
    public:
        Mazefactory(){};
        virtual Maze* MakeMaze() const
        {
            return new Maze;
        }
        virtual Wall * MakeWall() const
        {
            return new Wall;
        }
        virtual Room* MakeRoom(int n) const
        {
            return new Room(n);
        }
        virtual Door* MakeDoor(Room* r1,Room* r2) const
        {
            return new Door(r1,r2);
        }
        virtual ~Mazefactory(){};

    private:
};

#endif // MAZEFACTORY_H
