#include <iostream>
#include <string>
#include<stdio.h>

using namespace std;

int map[10][10];

int main()
{
    string a, b, inp;
    int n;
    int ky, kx;
    int sy, sx;
    cin >> a >> b >> n;

    ky = 8 - (a.at(1) - '0');
    kx = a.at(0) - 'A';

    sy = 8 - (b.at(1) - '0');
    sx = b.at(0) - 'A';

    map[ky][kx] = 1;
    map[sy][sx] = 2;

    while (n--)
    {
        cin >> inp;
        int ny = 0, nx = 0;
        if (inp == "R")
        {
            nx = 1;
        }
        else if (inp == "L")
        {
            nx = -1;
        }
        else if (inp == "B")
        {
            ny = 1;
        }
        else if (inp == "T")
        {
            ny = -1;
        }
        else if (inp == "RT")
        {
            nx = 1;
            ny = -1;
        }
        else if (inp == "LT")
        {
            nx=-1;
            ny=-1;
        }
        else if (inp == "RB")
        {
            nx=1;
            ny=1;
        }
        else if (inp == "LB")
        {
            nx=-1;
            ny=1;
        }

        if(ky+ny<0||ky+ny>7||kx+nx<0||kx+nx>7){
            continue;
        }

        if(map[ky+ny][kx+nx]==2){
            if (sy + ny < 0 || sy + ny > 7 || sx + nx < 0 || sx + nx > 7)
            {
                continue;
            }else{
                map[sy][sx]=0;
                sy+=ny;
                sx+=nx;
                map[sy][sx]=2;
                map[ky][kx]=0;
                ky+=ny;
                kx+=nx;
                map[ky][kx]=1;
            }
        }else{
            map[ky][kx]=0;
            ky+=ny;
            kx+=nx;
            map[ky][kx]=1;
        }

    }

    


    printf("%c%d\n",'A' + kx,8-ky);
    printf("%c%d\n",'A' + sx, 8 - sy);
}