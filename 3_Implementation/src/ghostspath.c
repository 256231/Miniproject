#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h> 
#include "header.h"

#define ROW 16
#define COL 16
enum move {LT,RT,UP,DN,STP}direction;
extern char block;
extern char grid[ROW][COL];
extern int gR, gC;
extern int right,left,up,down;




void ghost_dir_int()
{
    int ghost1;

    if(right==0&left==0&up==0&down==0){

        ghost1=(rand()%3)+1;

         if(ghost1==1)
        direction=LT;
        else if(ghost1==2)
            direction=DN;
            else
              direction=RT;
    }
    else{

        ghost1=(rand()%4)+1;

         if(ghost1==1)
                direction=LT;
          else if(ghost1==2)
             direction=RT;

         if(ghost1==3)
                direction=UP;
            else if(ghost1==4)
              direction=DN;
    }

}
void ghost_path_possible()
{
   if(direction == RT)
    {
        left=0;
        if(grid[gR][gC+1]!=block)
            right=8;
            else
                right=0;
        if(grid[gR-1][gC]!=block)
            up=2;
            else
                up=0;
        if(grid[gR+1][gC]!=block)
            down=1;
            else
                down=0;
    }
    else if(direction == LT)
    {
        right = 0;
        if(grid[gR][gC-1]!=block)
            left=4;
            else
                left=0;
        if(grid[gR-1][gC]!=block)
            up=2;
            else
                up=0;
        if(grid[gR+1][gC]!=block)
            down=1;
            else
                down=0;
    }
    if(direction == DN)
    {
        up=0;
        if(grid[gR][gC+1]!=block)
            right=8;
            else
                right=0;
        if(grid[gR][gC-1]!=block)
            left=4;
            else
                left=0;
        if(grid[gR+1][gC]!=block)
            down=1;
            else
                down=0;
    }
    else if(direction == UP)
    {
        down = 0;
        if(grid[gR][gC-1]!=block)
            left=4;
            else
                left=0;
        if(grid[gR-1][gC]!=block)
            up=2;
            else
                up=0;
        if(grid[gR][gC+1]!=block)
            right=8;
            else
                right=0;
    }
}

