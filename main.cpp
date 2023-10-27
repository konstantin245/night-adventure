#include "TXLib.h"
#include <string>
#include "kostia.h"
#include "nikita.h"

int randPlatform()
{
    int x; //х платформы 1
    int x1; //х платформы 2
    int y; //y платформы 1
    int y1; //y платформы 2

    if (Picle.personX>b2.x+50)
        {
            x=random(10, 1100); x1=random(10, 1100); y=random(583, 10); y1=random(583, 10);
            p[i]=Platform(x,y,"platform.bmp",480,128);
        }


}
int main()


    {
    txCreateWindow(1300,700);
    txClear();
    txSetColour(TX_BLACK,2);
    HDC  pic = txLoadImage("background.bmp");

    Person Picle(100,100,5,0);
    Vragi Vrag(500,140,8);

    Background b(pic,1290,700);
    Background b2(pic,1290,700);

    Platform p[1000]={
    Platform(200,400,"platform.bmp",480,128),
    Platform(800,400,"platform.bmp",480,128)
    };

    b2.x=1285;

    //Person.picture;
    //picture.picRun[0]=txLoadImage("pickleidle.bmp");

    Platform  Plat(800,400,"platform.bmp",480,128);

    while (Picle.cik)
    {
    txBegin();
    int NaPlatform=0;
    Picle.JumpH=250;

    if (GetAsyncKeyState('D'))
        {b.MoveLeft(7);b2.MoveLeft(7);}
    if (GetAsyncKeyState('A'))
        {b.MoveLeft(-7);b2.MoveLeft(-7);}

    b.Draw();
    b2.Draw();


    for (int i=0;i<2;i++)
    {
    p[i].Draw();
    Plat=p[i];

    if ((Plat.OnPlatformX(Picle.personX))&&(Plat.OnPlatformY(Picle.personY))){ Picle.BaseY=Plat.platformY; NaPlatform=1;}

    if (Plat.OnPlatformX(Picle.personX)&&Picle.personY>400) Picle.JumpH=25;

    if (GetAsyncKeyState('D'))
        p[i].MoveLeft(7);

     if (GetAsyncKeyState('A'))
        p[i].MoveLeft(-7);
    }
    if ((Picle.BaseY!=583)&&NaPlatform==0) {Picle.BaseY=583; Picle.GravityOn=1;} //проверка находиться хотя бы на одной платформе

    Vrag.Move(Picle.personX,Picle.personY);
    Vrag.Draw();

    Picle.Move();
    Picle.Draw();
    Picle.Fall();
    Picle.Jump();
    Picle.Death(Vrag.vragiX,Vrag.vragiY);

    txLine(0,600,1300,600);

    txEnd();
    Sleep(30);
    txClear();

    }
    }



