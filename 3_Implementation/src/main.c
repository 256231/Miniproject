
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>
#include "header.h"

#define ROW 16
#define COL 16

enum move {LT,RT,UP,DN,STP}direction;

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