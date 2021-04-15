
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>
#include "header.h"
enum move {LT,RT,UP,DN,STP}direction;
#define ROW 16
#define COL 16
void ghost_dir_final(enum move dir);
void ghost_move(enum move dir);



char block = 219;
int gR,gC;  // track ghost row and column
int right,left,up,down; 

char grid[ROW][COL] ={
"|||||||||||||||",
"|      @      |",
"| ||| | | | | |",
"| |   | | | | |",
"| | ||| | | | |",
"|       | | | |",
"| | ||| | | | |",
"| | |   | |   |",
"| | | ||| ||| |",
"|             |",
"| ||||||| ||| |",
"|    |        |",
"| || | || ||| |",
"| || | || ||| |",
"|             |",
"|||||||||||||||"};

int main()
{
right=0; left=0; up=0; down=0;

srand((unsigned)time(NULL));
int x,count=1500;
gR= 1; gC= 7;
ghost_dir_int();
fill_grid_block();

while(count)
{
    print_maze();
    ghost_move(direction);
    Sleep(150);
    ghost_path_possible();
    ghost_dir_final(direction);
    system("cls");

    count--;
}
return 0;
}

void ghost_dir_final(enum move dir)
{
    // R L U D
    // 8 4 2 1
    int x,y;
    srand((unsigned)time(NULL));
    x=right+left+up+down;

    switch(x)
    {
      case 1:{
        direction = DN;
        break;
       }
      case 2:{
        direction =UP;
        break;
       }
      case 3:{
        y=rand()%2;
        if(y==0)
            direction = UP;
        else
            direction =DN;
        break;
       }
      case 4:{
        direction = LT;
        break;
       }
       case 5:{
           y=rand()%2;
           if(y==0)
            direction = LT;
           else
            direction = DN;
        break;
       }
       case 6:{
           y=rand()%2;
           if(y==0)
            direction = LT;
           else
            direction = UP;
        break;
       }
       case 7:{
           y=rand()%3;
           if(y==0)
            direction = LT;
           else if(y==1)
            direction = DN;
            else
                direction = UP;
        break;
       }
       case 8:{
           direction = RT;
           break;
       }
       case 9:{
       y=rand()%2;
           if(y==0)
            direction = RT;
           else
            direction = DN;
        break;
       }
       case 10:{
       y=rand()%2;
           if(y==0)
            direction = RT;
           else
            direction = UP;
        break;
       }

       case 11:{
       y=rand()%3;
           if(y==0)
            direction = RT;
           else if(y==1)
            direction = DN;
            else
                direction = UP;
        break;
       }
       case 12:{
        y=rand()%2;
           if(y==0)
            direction = LT;
           else
            direction = RT;
        break;
       }
       case 13:{
       y=rand()%3;
           if(y==0)
            direction = LT;
            else if(y==1)
                direction = DN;
           else
            direction = RT;
        break;
       }
       case 14:{
       y=rand()%3;
           if(y==0)
            direction = LT;
            else if(y==0)
                direction =RT;
           else
            direction = UP;
        break;
       }
       default:;
        }
}

void ghost_move(enum move dir)
{
    if(dir==LT&grid[gR][gC-1]!=block )
  {
      grid[gR][gC]=' ';
      grid[gR][gC-1]='@';
      gC--;
  }
  if(dir==RT&grid[gR][gC+1]!=block)
  {
      grid[gR][gC]=' ';
      grid[gR][gC+1]='@';
      gC++;
  }
  if(dir==DN&grid[gR+1][gC]!=block)
  {
      grid[gR][gC]=' ';
      grid[gR+1][gC]='@';
      gR++;
  }
  if(dir==UP&grid[gR-1][gC]!=block)
  {
      grid[gR][gC]=' ';
      grid[gR-1][gC]='@';
      gR--;
  }
}
