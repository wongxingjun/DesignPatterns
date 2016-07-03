#include <iostream>
using namespace std;

class Initialization
{
public:
    void initialization()
    {
        cout<<"Now,system is initializing,please wait..."<<endl;
    }
};

class UserChecking
{
public:
    void userChecking()
    {
        cout<<"Checking user whether he is valid..."<<endl;
    }
};

class EnterSystem
{
public:
    void enterSys()
    {
        cout<<"Entering system,please wait..."<<endl;
    }
};

class SaveSession
{
public:
    void saveSession()
    {
        cout<<"Now is saving current session,please wait..."<<endl;
    }
};

class ExitSystem
{
public:
    void exitSys()
    {
        cout<<"Thank you for using,exiting..."<<endl;
    }
};

class System
{
private:
    Initialization* initSys;
    UserChecking* userCheck;
    EnterSystem* enterSys;
    SaveSession* saveSession;
    ExitSystem* exit;
public:
    System()
    {
        initSys = new Initialization();
        userCheck = new UserChecking();
        enterSys = new EnterSystem();
        saveSession = new SaveSession();
        exit = new ExitSystem();
    }

    void Run()
    {
        initSys->initialization();
        userCheck->userChecking();
        enterSys->enterSys();
    }

    void Save()
    {
        saveSession->saveSession();
    }

    void Exit()
    {
        exit->exitSys();
    }
};


int main()
{
    System* sys = new System();
    sys->Run();
    sys->Save();
    sys->Exit();
    return 0;
}
