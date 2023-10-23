#include "TXLib.h"
#include <string>
class Platform
{
    public:
    int platformX, platformY;
    string file;
    int platformW, platformH;
    HDC  image;



    Platform(int x1, int y1, string file1, int w1, int h1)
    {
        platformX=x1;platformY=y1;file=file1;platformW=w1;platformH=h1;
        image = txLoadImage(file.c_str());

    }

    int OnPlatformX(int x1)
    {
        if (x1>platformX && x1<platformX+platformW) return 1;
        return 0;

    }

    int OnPlatformY(int y1)
    {
        if (y1>platformY && y1<platformY+platformH) return 1;
        return 0;

    }
    int Draw()
    {
        txTransparentBlt(txDC(),   platformX,   platformY, platformW, platformH,image,0,0,TX_WHITE);
    }

    int MoveLeft(int n)
    {
        platformX=platformX-n;
    }

    };
class Background
{
    public:
    int x=0, y=0;
    string file;
    int w, h;
    HDC  image;
    Background(HDC b , int w1 , int h1){x=0;y=0;image=b;w=w1;h=h1;}

int Draw()
{
   txBitBlt (txDC(),   x,   y, w, h,image,0,0);

};

    int MoveLeft(int b)
    {
    if(x<-1300 )x=1300;
    else x=x-b;
    }

};


