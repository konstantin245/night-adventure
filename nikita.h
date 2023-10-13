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

    int OnPlatform(int x1)
    {
        if (x1>x && x1<x+w) return 1;
        return 0;

    }

      int MoveLeft(int n)
    {
    x=x-n;

    }




};

class Background1
{
    public:
     int x, y;
    string file;
    int w, h;
    HDC  image;
 Background1(HDC b , int w1 , int h1){
 x=0;y=0;image=b;w=w1;h=h1;}

int Draw()
{
   txBitBlt (txDC(),   0,   0, w, h,land,0,0);

};

    int MoveLeft(int b)
    {
    x=x-b;

    }
};


int Background(HDC land, int w,int h)
{
   txBitBlt (txDC(),   0,   0, w, h,land,0,0);

};

