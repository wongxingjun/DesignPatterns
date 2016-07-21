#include <iostream>
#include <stdlib.h>
#include <string>
#include <map>
using namespace std;

class Flyweight
{
public:
    virtual void operation(int externState){}
};

class ConcreteFlyweight: public Flyweight
{
public:
    void operation(int externState)
    {
        cout<<"Concrete flyweight: "<<externState<<endl;
    }
};

class UnshareConcreteFlyweight: public Flyweight
{
public:
    void operation(int externState)
    {
        cout<<"Unshare concrete flyweight: "<<externState<<endl;
    }
};

class FlyweightFactory
{
public:
    map<string,ConcreteFlyweight*> f;

    FlyweightFactory()
    {
        f["a"]=new ConcreteFlyweight();
        f["b"]=new ConcreteFlyweight();
        f["c"]=new ConcreteFlyweight();
    }

    Flyweight* getFlyweight(string k)
    {
        return f[k];
    }
};


int main()
{
    int e = 100;

    FlyweightFactory* f = new FlyweightFactory();

    Flyweight* fa = f->getFlyweight("a");
    fa->operation(--e);

    Flyweight* fb = f->getFlyweight("b");
    fb->operation(--e);

    Flyweight* uf = new UnshareConcreteFlyweight();
    uf->operation(--e);

    return 0;
}
