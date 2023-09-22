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

int Background(string file, int w,int h)
{
   HDC  land = txLoadImage(file.c_str());
   txBitBlt (txDC(),   0,   0, w, h,land,0,0);

};


int main()

    {
        txCreateWindow (1300, 700);
        Background("background.bmp",1300,700);
        Platform  p1(200,400,"platform.bmp",480,128);
        Platform  p2(800,400,"platform.bmp",480,128);
        p1.Draw();
        p2.Draw();
        cout<<p2.x<<p2.y<<p1.x<<p1.y;
        cout<<p2.w<<p2.h<<p1.w<<p1.h;
    return 0;
    }

