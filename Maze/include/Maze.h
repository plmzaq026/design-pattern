#ifndef MAZE_H
#define MAZE_H

#include "Room.h"
class Maze
{
    public:
        Maze(){};
        virtual ~Maze(){};
        void AddRoom(Room*){};
        Room* RoomNo(int num) const
        {

        };//find a certain room with No.num,hash is possible
    private:
};

#endif // MAZE_H
