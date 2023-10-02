#include "TXLib.h"
#include <string>
#include "kostia.h"
#include "nikita.h"

int main()


    {
    txCreateWindow(1300,700);
    txClear();
    txSetColour(TX_BLACK,2);
    HDC  land = txLoadImage("background.bmp");

    Person Picle(100,100,5,0);
    Platform  p1(200,400,"platform.bmp",480,128);
    Platform  p2(800,400,"platform.bmp",480,128);

    //Person.picture;
    //picture.picRun[0]=txLoadImage("pickleidle.bmp");



    while (1)
    {
    txBegin();
    Background(land,1300,700);
    p1.Draw();
    p2.Draw();
    p1.OnPlatform(Picle.personX);
    p2.OnPlatform(Picle.personX);
    Picle.Move();
    Picle.Draw();
    Picle.Fall();
    Picle.Jump();/*
    cout<<Picle.JumpOn;
    cout<<Picle.GravityOn;*/
    txLine(0,600,1300,600);

    //if (Picle.personY>p1.platformY && Picle.personX>p1.platformX && Picle.personX<p1.platformX+p1.platformW)  Picle.BaseY=p1.platformY;
    //else Picle.BaseY=583;
    txEnd();
    Sleep(30);
    txClear();
    }

    }

