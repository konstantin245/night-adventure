#include "TXLib.h"
#include <string>
#include "nikita.h"


int main()
    {
        txCreateWindow (1300, 700);
        HDC pic=txLoadImage("background.bmp");
 Background b(pic,1300,700);
 Background b2(pic,1300,700);
 b2.x=1300;
    while (1)
    {
txBegin();
    b.Draw();
    b2.Draw();
//p1.Draw();
//p2.Draw();
 if (GetAsyncKeyState('D'))
        {b.MoveLeft(1);b2.MoveLeft(1);}
 if (GetAsyncKeyState('A'))
        {b.MoveLeft(-1);b2.MoveLeft(-1);}
    Sleep(1);
    txEnd();
    }
    return 0;
    }

