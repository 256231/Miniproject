  
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>

#define ROW 16
#define COL 16


char block = 219; 

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
