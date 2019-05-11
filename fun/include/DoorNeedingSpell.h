#ifndef DOORNEEDINGSPELL_H
#define DOORNEEDINGSPELL_H

#include "Door.h"
class DoorNeedingSpell:public Door
{
    public:
        DoorNeedingSpell(Room * r= 0,Room*rr = 0){};
        void Enter(){};
        Room* OtherSideFrom(Room*){};
        virtual ~DoorNeedingSpell(){};
};

#endif // DOORNEEDINGSPELL_H
