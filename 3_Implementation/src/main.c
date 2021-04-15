#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>

int right,left,up,down;
int gR,gC;

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