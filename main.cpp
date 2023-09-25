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

