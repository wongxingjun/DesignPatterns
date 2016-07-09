#include <iostream>
#include <string>
#include <list>
using namespace std;

class Component
{
public:
    string name;
    Component(string n):name(n){}

    virtual void add(Component* c)=0;
    virtual void del(Component* c)=0;
    virtual void show(int depth)=0;
};

class Leaf: public Component
{
public:
    Leaf(string n):Component(n){}

    void add(Component* c)
    {
        cout<<"This is a leaf and you cannot add a leaf to it!"<<endl;
    }

    void del(Component* c)
    {
        cout<<"This is a leaf and you cannot delete from it!"<<endl;
    }

    void show(int depth)
    {
        string s="";
        for(int i=0;i<depth;i++)
            s.append("-");
        cout<<s<<name<<endl;
    }
};

class Bifurcation: public Component
{
public:
    list<Component*> *children = new list<Component*>();
    Bifurcation(string n):Component(n){}

    void add(Component* c)
    {
        children->push_back(c);
    }

    void del(Component* c)
    {
        children->remove(c);
    }

    void show(int depth)
    {
        string s="";
        for(int i=0;i<depth;i++)
            s.append("-");
        cout<<s<<name<<endl;
        for(list<Component*>::iterator it = children->begin();it != children->end();it++)
        {
            (*it)->show(depth+1);
        }
    }
};

int main()
{
    Bifurcation *company = new Bifurcation("Company");
    company->add(new Leaf("HR department"));
    company->add(new Leaf("Design department"));

    Bifurcation* dev = new Bifurcation("Development department");
    dev->add(new Leaf("Coding group"));
    dev->add(new Leaf("Testing group"));
    company->add(dev);

    Bifurcation *market = new Bifurcation("Market department");
    market->add(new Leaf("Advertising department"));
    market->add(new Leaf("Sales department"));
    company->add(market);

    company->show(1);

    company->del(dev);
    cout<<"*****Let's cut off the development department*****"<<endl;
    company->show(1);
    return 0;
}
