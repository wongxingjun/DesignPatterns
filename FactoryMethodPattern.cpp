#include <iostream>
#include "math.h"
using namespace std;

class Operation
{
public:
    double op_a;
    double op_b;
    Operation(double a, double b)
    {
        op_a = a;
        op_b = b;

    }
    virtual double getRes() {}
    ~Operation() {}

};

class Add : public Operation
{
public:
    Add(double a, double b):Operation(a, b) {}
    double getRes()
    {
        return this->op_a + this->op_b;

    }

};

class Sub : public Operation
{
public:
    Sub(double a, double b):Operation(a, b) {}
    double getRes()
    {
        return this->op_a - this->op_b;

    }

};

class Mul : public Operation
{
public:
    Mul(double a, double b):Operation(a, b) {}
    double getRes()
    {
        return this->op_a * this->op_b;

    }

};

class Div : public Operation
{
public:
    Div(double a, double b):Operation(a, b) {}
    double getRes()
    {
        try
        {
            return this->op_a / this->op_b;

        }
        catch(double)
        {
            cout<< "Error" <<endl;

        }

    }

};

class Factory
{
public:
    virtual Operation* createOperation(double a,double b){}
};

class AddFactory: public Factory
{
public:
    Operation* createOperation(double a,double b)
    {
        return new Add(a,b);
    }
};

class SubFactory: public Factory
{
public:
    Operation* createOperation(double a,double b)
    {
        return new Sub(a,b);
    }
};

class MulFactory: public Factory
{
public:
    Operation* createOperation(double a,double b)
    {
        return new Mul(a,b);
    }
};

class DivFactory: public Factory
{
public:
    Operation* createOperation(double a,double b)
    {
        return new Div(a,b);
    }
};

int main()
{
    Factory* f1 = new AddFactory();
    Operation* o1 = f1 ->createOperation(1.0,2.0);
    cout<< "1.0+2.0="<<o1->getRes()<<endl;
    Factory* f2 = new DivFactory();
    Operation* o2 = f2->createOperation(1.0,2.33);
    cout<< "1.0/2.33="<<o2->getRes()<<endl;
    return 0;
}
