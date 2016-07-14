#include <iostream>
#include <list>
using namespace std;

class Cook
{
public:
    void makeSoup()
    {
        cout<<"make a bowl of bone soup, it is delicious!"<<endl;
    }

    void makeChicken()
    {
        cout<<"barbecue a chicken, it is sweet!"<<endl;
    }

};


class Command
{
public:
    Cook *cook;
    Command(Cook* c):cook(c){}

    virtual void exeCommand(){};
};

class SoupCommand: public Command
{
public:
    SoupCommand(Cook* c):Command(c){}

    void exeCommand()
    {
        this->cook->makeSoup();
    }
};

class ChickenCommand: public Command
{
public:
    ChickenCommand(Cook* c):Command(c){}

    void exeCommand()
    {
        this->cook->makeChicken();
    }
};

class Waiter
{
public:
    list<Command*> *orders = new list<Command*>();

    void giveOrders(Command* c)
    {
        cout<<"Add a command"<<endl;
        orders->push_back(c);
    }

    void cancelOrders(Command* c)
    {
        cout<<"Cancel a command"<<endl;
        orders->remove(c);
    }

    void notify()
    {
        for(auto i=orders->begin();i!=orders->end();i++)
        {
            (*i)->exeCommand();
        }
    }
};


int main()
{
    Cook* c1 = new Cook();

    Command* soup1 = new SoupCommand(c1);
    Command* soup2 = new SoupCommand(c1);
    Command* chicken1 = new ChickenCommand(c1);

    Waiter* w1 = new Waiter();

    w1->giveOrders(soup1);
    w1->giveOrders(soup2);
    w1->giveOrders(chicken1);

    w1->cancelOrders(soup2);

    w1->notify();

    return 0;
}
