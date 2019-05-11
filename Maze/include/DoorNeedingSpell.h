#ifndef DOORNEEDINGSPELL_H
#define DOORNEEDINGSPELL_H

#include "Door.h"
#include <iostream>
using namespace std;

class DoorNeedingSpell:public Door
{
    public:
        DoorNeedingSpell(Room * r= 0,Room*rr = 0){};
        void Enter()
        {
            if(_isOpen)
            {
                cout<<"Entering a Door needing spell!"<<endl;
            }
            else
            {
                cout<<"The door is closed. you should enter a spell."<<endl;
                string str;
                cin>>str;
                if(str == spell)
                {
                    _isOpen = true;
                    cout<<"Now it is open"<<endl;
                }else
                {
                    cout<<"Wrong Spell!"<<endl;
                }
            }
        };
        Room* OtherSideFrom(Room*){};
        virtual ~DoorNeedingSpell(){};
    private:
        string spell;
        bool _isOpen;
};

#endif // DOORNEEDINGSPELL_H
