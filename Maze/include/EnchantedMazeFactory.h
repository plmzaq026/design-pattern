#ifndef ENCHANTEDMAZEFACTORY_H
#define ENCHANTEDMAZEFACTORY_H

#include "Mazefactory.h"
#include "EnchantedRoom.h"

#include "DoorNeedingSpell.h"

class EnchantedMazeFactory: public Mazefactory
{
    public:
        EnchantedMazeFactory(){};
        virtual ~EnchantedMazeFactory(){};
        Room* MakeRoom(int n) const
        {
            return new EnchantedRoom(n);
        }

        Door* MakeDoor(Room * r1,Room* r2) const
        {
            return new DoorNeedingSpell(r1,r2);
        }
    private:
        int * CastSpell() const{};
};

#endif // ENCHANTEDMAZEFACTORY_H
