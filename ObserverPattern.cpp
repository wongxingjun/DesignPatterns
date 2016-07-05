#include <iostream>
#include <list>
using namespace std;

class Observer
{
public:
    virtual void update(int){}
};

class Subject
{
public:
    list<Observer*> observers;
    virtual void attach(Observer* o){}
    virtual void detach(Observer* o){}
    virtual void setState(int){}
    virtual void notify(){}
};

class ConcreteSubject: public Subject
{
public:
    int state;
    ConcreteSubject(int sta):state(sta)
    {
        state=sta;
        cout<<"Subject is initialized with state:"<<state<<endl;
    }
    void attach(Observer* o)
    {
        observers.push_back(o);
    }
    void detach(Observer* o)
    {
        observers.remove(o);
    }
    void setState(int sta)
    {
        cout<<"Subject updates its state as:"<<sta<<endl;
        state=sta;
    }
    void notify()
    {
        for(list<Observer*>::iterator it=observers.begin();it!=observers.end();it++)
        {
            (*it)->update(state);
        }
    }
};

class ConcreteObserver: public Observer
{
public:
    Subject* sub;
    string id;
    ConcreteObserver(string id,Subject* sub):id(id),sub(sub){}
    void update(int state)
    {
        cout<<"Observer "<<id<<" updates its state as:"<<state<<endl;
    }
};



int main()
{
    ConcreteSubject* s = new ConcreteSubject(100);
    s->attach(new ConcreteObserver("20160701",s));
    s->attach(new ConcreteObserver("20160705",s));
    s->setState(200);
    s->notify();
    return 0;
}
