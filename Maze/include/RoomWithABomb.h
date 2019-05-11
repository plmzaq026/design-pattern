#ifndef ROOMWITHABOMB_H
#define ROOMWITHABOMB_H

#include "Room.h"
class RoomWithABomb:public Room
{
    public:
        RoomWithABomb(int roomNo=0){};
        void Enter()
        {
            cout<<"Entering a room with a bomb"<<endl;
        };
        virtual ~RoomWithABomb(){};
};

#endif // ROOMWITHABOMB_H
