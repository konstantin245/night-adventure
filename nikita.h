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

    int OnPlatform(int x1)
    {
        if (x1>platformX && x1<platformX+platformW) return 1;
        return 0;

    }

    int Draw()
    {
    txTransparentBlt(txDC(),   platformX,   platformY, platformW, platformH,image,0,0,TX_WHITE);
    }


};

int Background(HDC land, int w,int h)
{
   txBitBlt (txDC(),   0,   0, w, h,land,0,0);

};

