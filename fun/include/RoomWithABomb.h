#ifndef ROOMWITHABOMB_H
#define ROOMWITHABOMB_H

#include "Room.h"
class RoomWithABomb:public Room
{
    public:
        RoomWithABomb(int roomNo=0){};
        void Enter(){};
        virtual ~RoomWithABomb(){};
};

#endif // ROOMWITHABOMB_H
