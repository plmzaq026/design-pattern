#ifndef DOOR_H
#define DOOR_H
#include <stdlib.h>
#include "Room.h"
class Door:public MapSite
{
    public:
        Door(Room * r= 0,Room*rr = 0)
        {

        };
        virtual void Enter(){};
        Room* OtherSideFrom(Room*)
        {

        };
        virtual ~Door()
        {
            if(_room1)
                free(_room1);
            if(_room2)
                free(_room2);
        }
    private:
        Room* _room1;
        Room* _room2;
        bool _isOpen;
};

#endif // DOOR_H
