#include <iostream>
using namespace std;

class Software
{
public:
    virtual void run()=0;
};

class Game: public Software
{
public:
    void run()
    {
        cout<<"Let's play the game"<<endl;
    }
};

class Memo: public Software
{
public:
    void run()
    {
        cout<<"Let's start the memo"<<endl;
    }
};


class Brand
{
public:
    Software* s;

    void setSoftware(Software* s)
    {
        this->s=s;
    }

    virtual void run()=0;
};


class Huawei: public Brand
{
public:
    void run()
    {
        this->s->run();
    }
};

class Xiaomi: public Brand
{
public:
    void run()
    {
        this->s->run();
    }
};


int main()
{
    Brand* b1 = new Huawei();
    b1->setSoftware(new Game());
    b1->run();


    Brand* b2 = new Xiaomi();
    b2->setSoftware(new Memo());
    b2->run();

    return 0;
}
