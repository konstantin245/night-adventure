#include "TXLib.h"
#include <string>
#include "kostia.h"
#include "nikita.h"

int main()


    {
    txCreateWindow(1300,700);
    txClear();
    txSetColour(TX_BLACK,2);
    HDC  pic = txLoadImage("background.bmp");

    Person Picle(100,100,5,0);
    Vragi Vrag(140,140,8);

    Background b(pic,1290,700);
    Background b2(pic,1290,700);
    b2.x=1290;

    Platform p[2]={
    Platform(200,400,"platform.bmp",480,128),
    Platform(800,400,"platform.bmp",480,128)
    };

    //Person.picture;
    //picture.picRun[0]=txLoadImage("pickleidle.bmp");

    Platform  Plat(800,400,"platform.bmp",480,128);

    while (1)
    {
    txBegin();
    int NaPlatform=0;
    Picle.JumpH=250;


    if (GetAsyncKeyState('D'))
        {b.MoveLeft(5);b2.MoveLeft(5);}
    if (GetAsyncKeyState('A'))
        {b.MoveLeft(-5);b2.MoveLeft(-5);}

    b.Draw();
    b2.Draw();


    for (int i=0;i<2;i++)
    {
    p[i].Draw();
    Plat=p[i];

    if ((Plat.OnPlatformX(Picle.personX))&&(Plat.OnPlatformY(Picle.personY))){ Picle.BaseY=Plat.platformY; NaPlatform=1;}

    if (Plat.OnPlatformX(Picle.personX)&&Picle.personY>500) Picle.JumpH=25;

    if (GetAsyncKeyState('D'))
        p[i].MoveLeft(5);

     if (GetAsyncKeyState('A'))
        p[i].MoveLeft(-5);
    }
    if ((Picle.BaseY!=583)&&NaPlatform==0) {Picle.BaseY=583; Picle.GravityOn=1;} //�������� ���������� ���� �� �� ����� ���������

    Vrag.Move(Picle.personX,Picle.personY);
    Vrag.Draw();

    Picle.Move();
    Picle.Draw();
    Picle.Fall();
    Picle.Jump();
    txLine(0,600,1300,600);

    txEnd();
    Sleep(30);
    txClear();

    }
    }



