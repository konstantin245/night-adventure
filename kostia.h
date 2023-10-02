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
int GravityOn=0;
int BaseSpeed=7;
int JumpOn=0;
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


   /* int RicLoad()
    {


    }
*/

    int Fall()
    {
    if (personY<BaseY+100&&GravityOn) personY=personY+12;
    }


    int Jump()
    {
        if (personY>BaseY+10) {JumpOn=0;GravityOn=0;personY=personY-10;}
        if (JumpOn==1)
        {
        if ((BaseY-250<personY)&&GravityOn==0) {personY=personY-25;}
        else {GravityOn=1;}
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
};
