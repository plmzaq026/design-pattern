#ifndef MAZE_H
#define MAZE_H

#include "Room.h"
class Maze
{
    public:
        Maze(){};
        virtual ~Maze(){};
        void AddRoom(Room*){};
        Room* RoomNo(int) const{};//find a certain room with no.XXX,hash 1 ha
    private:
};

#endif // MAZE_H
