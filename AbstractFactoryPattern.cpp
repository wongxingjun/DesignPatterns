#include <iostream>
using namespace std;

class IProduct1
{
public:
    virtual void show()=0;
};

class IProduct2
{
public:
    virtual void show()=0;
};

class Product1: public IProduct1
{
public:
    void show()
    {
        cout<<"This is product1"<<endl;
    }
};

class Product2: public IProduct2
{
public:
    void show()
    {
        cout<<"This is product2"<<endl;
    }
};

class IFactory
{
public:
    virtual IProduct1* createProduct1()=0;
    virtual IProduct2* createProduct2()=0;
};

class Factory: public IFactory
{
public:
    IProduct1* createProduct1()
    {
        return new Product1();
    }
    IProduct2* createProduct2()
    {
        return new Product2();
    }
};

int main()
{
    IFactory* f= new Factory();
    f->createProduct1()->show();
    f->createProduct2()->show();
    return 0;
}


