#include <iostream>
using namespace std;

class Template
{
public:
    int a,b;
    Template(int a,int b):a(a),b(b){}
    virtual void func1(){}
    virtual void func2(){}
    void templateMethod()
    {
        func1();
        func2();
    }
};

class ConcreteClassA: public Template
{
public:
    ConcreteClassA(int a,int b):Template(a,b){}
    void func1()
    {
        cout<<"I do a add operation:"<<endl;
        cout<<a<<"+"<<b<<"="<<a+b<<endl;
    }
    void func2()
    {
        cout<<"I do a sub operation:"<<endl;
        cout<<a<<"-"<<b<<"="<<a-b<<endl;
    }
};

class ConcreteClassB: public Template
{
public:
    ConcreteClassB(int a,int b):Template(a,b){}
    void func1()
    {
        cout<<"I do a mul operation:"<<endl;
        cout<<a<<"*"<<b<<"="<<a*b<<endl;
    }
    void func2()
    {
        cout<<"I do a div operation:"<<endl;
        if(b!=0)
            cout<<a<<"/"<<b<<"="<<a/b<<endl;
        else
            cout<<"b cannot be 0!"<<endl;
    }
};


int main()
{
    Template* t;
    t=new ConcreteClassA(8,2);
    t->templateMethod();
    t=new ConcreteClassB(10,5);
    t->templateMethod();
    return 0;
}
