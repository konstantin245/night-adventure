#include "TXLib.h"
#include <string>
class Platform
{
    public:
    int x, y;
    string file;
    int w, h;
    HDC  image;

    Platform(int x1, int y1, string file1, int w1, int h1)
    {
        x=x1;y=y1;file=file1;w=w1;h=h1;
        image = txLoadImage(file.c_str());

    }

    int Draw()
    {
    txTransparentBlt(txDC(),   x,   y, w, h,image,0,0,TX_WHITE);
    }


};

int Background(HDC land, int w,int h)
{
   txBitBlt (txDC(),   0,   0, w, h,land,0,0);

};
