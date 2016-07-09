#include <iostream>
#include <string>
using namespace std;

class Memento
{
private:
    string state;
public:
    Memento(string s):state(s){}
    string getState()
    {
        return state;
    }
};

class Originator
{
private:
    string state;

public:

    string getState()
    {
        return state;
    }

    void setState(string s)
    {
        this->state= s;
    }

    Memento* createMemento()
    {
        return new Memento(state);
    }

    void setMemento(Memento* m)
    {
        this->state=m->getState();
    }

    void show()
    {
        cout<<"Now my state is: "<<state<<endl;
    }
};

class Caretaker
{
public:
    Memento* memento;
    void setMemento(Memento* m)
    {
        this->memento=m;
    }
    Memento* getMemento()
    {
        return memento;
    }
};


int main()
{
    Originator* o = new Originator();
    o->setState("alive");
    o->show();

    Caretaker* c = new Caretaker();
    c->setMemento(o->createMemento());

    o->setState("dead");
    o->show();

    o->setMemento(c->memento);
    o->show();

    return 0;
}
