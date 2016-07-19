#include <iostream>
#include <string>
using namespace std;

class Student;

class Mediator
{
public:
    virtual void send(string msg, Student* student){}
};

class Student
{
public:
    Mediator* mediator;
    Student(Mediator* m):mediator(m){}
};

class ConcreteStudent1: public Student
{
public:
    ConcreteStudent1(Mediator* m):Student(m){}

    void send(string msg)
    {
        this->mediator->send(msg,this);
    }

    void notify(string msg)
    {
        cout<<"Student1 got message: "<<msg<<endl;
    }
};

class ConcreteStudent2: public Student
{
public:
    ConcreteStudent2(Mediator* m):Student(m){}

    void send(string msg)
    {
        this->mediator->send(msg,this);
    }

    void notify(string msg)
    {
        cout<<"Student2 got message: "<<msg<<endl;
    }
};


class ConcreteMediator: public Mediator
{
public:
    ConcreteStudent1* s1;
    ConcreteStudent2* s2;

    void setStudent1(ConcreteStudent1* s)
    {
        this->s1=s;
    }

    void setStudent2(ConcreteStudent2* s)
    {
        this->s2=s;
    }

    void send(string msg,Student* s)
    {
        if(s==s1)
            s2->notify(msg);
        else
            s1->notify(msg);
    }

};


int main()
{
    ConcreteMediator* m = new ConcreteMediator();

    ConcreteStudent1* s1 = new ConcreteStudent1(m);
    ConcreteStudent2* s2 = new ConcreteStudent2(m);

    m->setStudent1(s1);
    m->setStudent2(s2);

    s1->send("How are you?");
    s2->send("Fine, thank you.");

    return 0;
}
