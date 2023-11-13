#include <iostream>
#include "TXLib.h"

using namespace std;
class Person
{
public:
int personX;
int personY;
int personHP;
int personAR;
int BaseY=583;
int JumpH=250;
int GravityOn=0;
int BaseSpeed=9;
int JumpOn=1;
int cik=1;
int i;
//HDC picRun[3];
//HDC pic;

    Person(int x,int y,int hp,int ar)
    {
        personX=x;
        personY=y;
        personHP=hp;
        personAR=ar;
    }

    int Draw()
    {
        //txTransparentBlt(txDC(),personX,personY,100,100,picRun,0,0,TX_WHITE);
        txCircle(personX,personY,15);
    }

    int Fall()
    {
    if (personY<BaseY+100&&GravityOn) personY=personY+12;
    }


    int Jump()
    {
        if (personY>BaseY+10) {JumpOn=0;GravityOn=0;personY=personY-10;}
        if (JumpOn==1)
        {
        if ((BaseY-JumpH<personY)&&GravityOn==0) {personY=personY-25;}
        else {GravityOn=1;}
        /*if (BaseY<1000){if((BaseY-600<personY)&&GravityOn==0) {personY=personY-25;}
        else {GravityOn=1;}}*/
        }
    }


    int Move()
    {
        if (GetAsyncKeyState('A'))
        {
        i++;
        if (personX>15) personX=personX-BaseSpeed;
        //pic=p1[i%3];
        personAR=0;
        }

        if (GetAsyncKeyState('D'))
        {
        i++;
        if (personX<1236) personX=personX+BaseSpeed;
        //pic=p[i%3];
        personAR=1;
        }
        if (GetAsyncKeyState(VK_SPACE))
        {
        JumpOn=1;
        }
    }

    int Death(int x, int y)
    {
    if ((personX>x-25&&personX<x+25) && personY>y-25&&personY<y+25) {cik=0;}
    }

};

class Vragi
{
public:
int vragiX;
int vragiY;
int vragiHP;
int arrow=1;

    Vragi(int x,int y,int hp)
    {
        vragiX=x;
        vragiY=y;
        vragiHP=hp;
    }

    int Draw()
    {
        txCircle(vragiX,vragiY,20);
    }

    int Move(int x, int y, int NaPlatformV, int BaseY=583)
    {
        if (NaPlatformV!=1) {if (x>vragiX) vragiX=vragiX+4; else vragiX=vragiX-4;
                                if (x>vragiX)arrow=1; else arrow=-1;}
        else
        {if (x-250>vragiX) arrow=1;
        if (x+250<vragiX) arrow=-1;

            vragiX=vragiX+4*arrow;}


    if (NaPlatformV!=1||vragiY>BaseY+10)
    {
        if (y>vragiY) vragiY=vragiY+4;
            else vragiY=vragiY-4;
    }
    }
};
