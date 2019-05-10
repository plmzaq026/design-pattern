#include <iostream>
using namespace std;

class Fruit
{
public:
    virtual void print() = 0;
};

class Banana:public Fruit
{
public:
    void print()
    {
        cout<<"Banana"<<endl;
    }
};

class Apple:public Fruit
{
public:
    void print()
    {
        cout<<"Apple"<<endl;
    }
};
class Orange:public Fruit
{
public:
    void print()
    {
        cout<<"Orange"<<endl;
    }
};
int main(void)
{
    Fruit * pFruit[] = {new Banana(), new Apple(), new Orange()};
    for(int i =0 ;i < 3;i ++)
    {
        (*pFruit[i]).print();
    }
    return 0;
}
