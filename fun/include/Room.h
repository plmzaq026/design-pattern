#ifndef ROOM_H
#define ROOM_H

#include "MapSite.h"

#include <stdlib.h>
class Room:public MapSite
{
    public:
        Room(int roomNo=0){};

        MapSite* GetSide(Direction) const;
        void SetSide(Direction,MapSite*){};

        virtual void Enter(){};
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
