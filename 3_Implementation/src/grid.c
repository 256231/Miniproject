  
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>
#include "header.h"

#define ROW 16
#define COL 16

extern char block;
enum move {LT,RT,UP,DN,STP}direction;
extern char grid[ROW][COL];
extern int gR, gC;
extern int right,left,up,down;




void fill_grid_block()
{
    int r,c;
    for(r=0;r<ROW;r++)
        for(c=0;c<COL;c++)
       {
         if(grid[r][c]=='|')
         {
             grid[r][c] =block;
         }
       }
}
