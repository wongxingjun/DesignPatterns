#include <iostream>
using namespace std;

class AdapterInChina
{
public:
    virtual void use()=0;
};

class AdapterInUS
{
public:
    void specificUse()
    {
        cout << "No, you can use the adapter in the U.S." <<endl;
    }
};

class Adapter: public AdapterInChina
{
private:
    AdapterInUS* u = new AdapterInUS();
public:
    void use()
    {
        u->specificUse();
    }
};

int main()
{
    AdapterInChina *c = new Adapter();
    c->use();
    return 0;
}
