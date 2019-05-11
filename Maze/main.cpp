#include <iostream>
#include "MazeGame.h"
#include "BombedMazeFactory.h"
#include "EnchantedMazeFactory.h"

using namespace std;

int main()
{
    MazeGame game;
    BombedMazeFactory factory;
    game.CreateMaze(factory);
    return 0;
}
