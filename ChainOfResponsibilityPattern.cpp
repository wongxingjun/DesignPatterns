#include <iostream>
using namespace std;

class Handler
{
public:
    Handler* successor;
    void setSuccessor(Handler* s)
    {
        this->successor=s;
    }
    virtual void handleRequest(int request){}
};

class ConcreteHandler1: public Handler
{
public:
    void handleRequest(int request)
    {
        if(request>1&&request<10)
            cout<<"ConcreteHandler1 handles the request"<<endl;
        else if(this->successor)
            this->successor->handleRequest(request);
    }
};

class ConcreteHandler2: public Handler
{
public:
    void handleRequest(int request)
    {
        if(request>=10&&request<20)
            cout<<"ConcreteHandler2 handles the request"<<endl;
        else if(this->successor)
            this->successor->handleRequest(request);
    }
};

class ConcreteHandler3: public Handler
{
public:
    void handleRequest(int request)
    {
        if(request>=20&&request<30)
            cout<<"ConcreteHandler3 handles the request"<<endl;
        else if(this->successor)
            this->successor->handleRequest(request);
    }
};

int main()
{
    Handler* h1 = new ConcreteHandler1();
    Handler* h2 = new ConcreteHandler2();
    Handler* h3 = new ConcreteHandler3();
    h1->setSuccessor(h2);
    h2->setSuccessor(h3);

    for(int i=0;i<30;i+=4)
    {
        cout<<"Request: "<<i<<endl;
        h1->handleRequest(i);
    }
    return 0;
}
