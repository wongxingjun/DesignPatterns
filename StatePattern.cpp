#include <iostream>
#include <string>
using namespace std;

class Context;
class State
{
public:
    virtual void Handle(Context* context){}
    virtual string getState(){}
};

class Context
{
public:
    State* state;
    Context(State* s):state(s){}
    void request()
    {
        state->Handle(this);
    }
};

class StateB;

class StateA: public State
{
public:
    void Handle(Context* context);
    string getState();
};

class StateB: public State
{
public:
    void Handle(Context* context);
    string getState();
};

inline void StateA::Handle(Context* context)
{
    context->state = new StateB();
}

inline string StateA::getState()
{
    return "StateA";
}

inline void StateB::Handle(Context* context)
{
    context->state = new StateA();
}

inline string StateB::getState()
{
    return "StateB";
}

int main()
{
    Context* con = new Context(new StateA());
    cout<<"Initial State: "<<con->state->getState()<<endl;
    con->request();
    cout<<"State: "<<con->state->getState()<<endl;
    con->request();
    cout<<"State: "<<con->state->getState()<<endl;
    return 0;
}
