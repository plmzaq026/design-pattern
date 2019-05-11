#ifndef ENCHANTEDROOM_H
#define ENCHANTEDROOM_H


#include "Room.h"
class EnchantedRoom:public Room
{
    public:
        EnchantedRoom(int roomNo=0){};
        void Enter(){};
        virtual ~EnchantedRoom(){};
};

#endif // ENCHANTEDROOM_H
