#ifndef BOMBEDMAZEFACTORY_H
#define BOMBEDMAZEFACTORY_H

#include "Mazefactory.h"
#include "BombedWall.h"
#include "RoomWithABomb.h"

class BombedMazeFactory:public Mazefactory
{
    public:
        BombedMazeFactory(){};
        virtual ~BombedMazeFactory(){};
        Wall * MakeWall() const
        {
            return new BombedWall;
        }
        Room* MakeRoom(int n) const
        {
            return new RoomWithABomb(n);
        }
};

#endif // BOMBEDMAZEFACTORY_H
