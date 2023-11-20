#include "TXLib.h"
#include <string>
#include "kostia.h"
#include "nikita.h"

/*int randPlatform()
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


}*/
int main()


    {
    txCreateWindow(1300,700);
    txClear();
    txSetColour(TX_BLACK,2);
    HDC  pic = txLoadImage("background.bmp");
    int y;

    Person Picle(100,580,5,0);
    Vragi Vrag(500,140,8);

    Background b(pic,1290,700);
    Background b2(pic,1290,700);

    y = random(350,500);
    Platform p[10];
    p[0]= Platform(200,y,"platform.bmp",480,128);
    y = random(350,450);
    p[1]=Platform(800,y,"platform.bmp",480,128);
    y = random(350,450);
    p[2]=Platform(1400,y,"platform.bmp",480,128);
    y = random(350,450);
    p[3]=Platform(2000,y,"platform.bmp",480,128);
    y = random(350,450);
    p[4]=Platform(2600,y,"platform.bmp",480,128);
    y = random(350,450);

    b2.x=1285;

    //Person.picture;
    //picture.picRun[0]=txLoadImage("pickleidle.bmp");
   Platform  Plat(800,y,"platform.bmp",480,128);

    while (Picle.cik)
    {
    txBegin();
    int NaPlatform=0;
    int UnderPlatform=0;
    int NaPlatformVrag=0;

    if (GetAsyncKeyState('D'))
        {b.MoveLeft(10);b2.MoveLeft(7);} //7
    if (GetAsyncKeyState('A'))
        {b.MoveLeft(-10);b2.MoveLeft(-7);} //-7

    b.Draw();
    b2.Draw();


    for (int i=0;i<2;i++)
    {
    p[i].Draw();
    Plat=p[i];

    if (Plat.OnPlatformX(Vrag.vragiX)&&Plat.OnPlatformYVrag(Vrag.vragiY)) NaPlatformVrag=1;
    if ((Plat.OnPlatformX(Picle.personX))&&(Plat.OnPlatformYPerson(Picle.personY))){ Picle.BaseY=Plat.platformY; NaPlatform=1;}

    if (Plat.OnPlatformX(Picle.personX)&&Picle.personY<Plat.platformY) Picle.JumpH=250;
        /*Picle.JumpH=Picle.JumpH+Picle.BaseY-Plat.platformY;
    else Picle.JumpH=250;*/

    if (GetAsyncKeyState('D'))
        p[i].MoveLeft(7);

     if (GetAsyncKeyState('A'))
        p[i].MoveLeft(-7);


    if ((Plat.OnPlatformX(Picle.personX))&&Picle.personY>Plat.platformY) UnderPlatform=1;
        if (UnderPlatform==1) Picle.JumpH=583-Plat.platformY-81; //81
            else Picle.JumpH=250;
    }

    if ((Picle.BaseY!=583)&&NaPlatform==0) {Picle.BaseY=583; Picle.GravityOn=1;} //проверка находиться хотя бы на одной платформе
    Vrag.Move(Picle.personX,Picle.personY,NaPlatformVrag);
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
    txSetFillColour(TX_RED); txRectangle(0,0,1300,700); txSetColour(TX_BLACK); txSelectFont("Arial",150); txDrawText(0,0,1300,700,"YOU`RE DEAD");
    }



