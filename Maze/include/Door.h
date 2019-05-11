#ifndef DOOR_H
#define DOOR_H
#include <stdlib.h>
#include "Room.h"
class Door:public MapSite
{
    public:
        Door(Room * r= 0,Room*rr = 0)
        {
            _room1 = r;
            _room2 = rr;
            _isOpen = false;
        };
        virtual void Enter()
        {
            if(_isOpen)
                cout<<"Entering a Door!"<<endl;
            else
            {
                cout<<"The door is closed. you push it then."<<endl;
                _isOpen = true;
                cout<<"Now it is open"<<endl;
            }
        };
        Room* OtherSideFrom(Room* r)
        {
            if(r == _room1)
                return _room2;
            return _room1;
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
