#ifndef WALL_H
#define WALL_H
#include "MapSite.h"

class Wall:public MapSite
{
    public:
        Wall(){};
        virtual void Enter()
        {
            cout<<"Entering a WALL!!!"<<endl;
        };
        virtual ~Wall(){};
};

#endif // WALL_H
