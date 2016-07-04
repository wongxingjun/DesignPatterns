#include <iostream>
using namespace std;

class DrawPicture
{
private:
    string picKind;
    string pen;
public:
    DrawPicture(string pic,string pen):picKind(pic),pen(pen){}
    virtual void getPen(){}
    virtual void getWaterColor(){}
    virtual void mixColor(){}
    virtual void doDraw(){}
};

class DrawPerson: public DrawPicture
{
public:
    DrawPerson(string pic,string pen):DrawPicture(pic,pen){}
    void getPen()
    {
        cout<<"Get a pen"<<endl;
    }
    void getWaterColor()
    {
        cout<<"Get water color for person"<<endl;
    }
    void mixColor()
    {
        cout<<"Mix color for person"<<endl;
    }
    void doDraw()
    {
        cout<<"Let's draw a person"<<endl;
    }
};

class DrawTiger: public DrawPicture
{
public:
    DrawTiger(string pic,string pen):DrawPicture(pic,pen){}
    void getPen()
    {
        cout<<"Get a pen"<<endl;
    }
    void getWaterColor()
    {
        cout<<"Get water color for tiger"<<endl;
    }
    void mixColor()
    {
        cout<<"Mix color for tiger"<<endl;
    }
    void doDraw()
    {
        cout<<"Let's draw an tiger"<<endl;
    }
};

class Director
{
private:
    DrawPicture* dp;
public:
    Director(DrawPicture* dp):dp(dp){}
    void draw()
    {
        dp->getPen();
        dp->getWaterColor();
        dp->mixColor();
        dp->doDraw();
    }
};

int main()
{
    string picKind="waterColor";
    string pen="waterColorBrush";
    DrawPerson* dPerson=new DrawPerson(picKind,pen);
    Director* dir1=new Director(dPerson);
    dir1->draw();
    DrawTiger* dTiger=new DrawTiger(picKind,pen);
    Director* dir2=new Director(dTiger);
    dir2->draw();
    return 0;
}
