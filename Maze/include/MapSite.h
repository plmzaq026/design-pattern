#ifndef MAPSITE_H
#define MAPSITE_H

enum Direction {North,South,East,West};

class MapSite
{
    public:
        MapSite(){};
        virtual ~MapSite(){};
        virtual void Enter() = 0;
};

#endif // MAPSITE_H
