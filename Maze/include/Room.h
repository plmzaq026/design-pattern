#ifndef ROOM_H
#define ROOM_H
#include "MapSite.h"

#include <stdlib.h>
#include <iostream>
using namespace std;
class Room:public MapSite
{
    public:
        Room(int roomNo=0)
        {
            _roomNumber = roomNo;
        };
        MapSite* GetSide(Direction d) const
        {
            return _sides[d];
        };
        void SetSide(Direction d,MapSite* m)
        {
            _sides[d] = m;
        };
        void Enter()
        {
            cout<<"Entering a room"<<endl;
        };
        virtual ~Room()
        {
            for(int i = 0;i < 4;i ++)
                if(_sides[i])
                    free(_sides[i]);
        }
    private:
        MapSite* _sides[4];
        int _roomNumber;
};

#endif // ROOM_H
