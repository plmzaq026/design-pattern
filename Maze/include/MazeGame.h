#ifndef MAZEGAME_H
#define MAZEGAME_H

#include "Mazefactory.h"

class MazeGame
{
    public:
        MazeGame();
        virtual ~MazeGame();
        Maze* CreateMaze(Mazefactory& factory);
};

#endif // MAZEGAME_H
