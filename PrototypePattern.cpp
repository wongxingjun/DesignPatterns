#include <iostream>
using namespace std;

class Prototype
{
private:
    string id;
public:
    Prototype(string id):id(id) {}
    string getid()
    {
        return id;
    }
    virtual Prototype* clone() {}
};

class ConcretePrototype : public Prototype
{
public:
    ConcretePrototype(string id):Prototype(id) {}
    Prototype* clone()
    {
        return new Prototype(this->getid());
    }
};

int main()
{
    ConcretePrototype* con = new ConcretePrototype("20160702");
    cout<<con->getid()<<endl;
    ConcretePrototype* con2 = (ConcretePrototype*)con->clone();
    cout<<con2->getid()<<endl;
    return 0;
}
