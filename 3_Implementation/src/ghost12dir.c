#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<stdbool.h>
#include<windows.h>
#include "header.h"

#define ROW 21
#define COL 72


extern int car_1r,car_1c,car_2r,car_2c;
extern int ghost1_r, ghost1_c;
int ghost2_r,ghost2_c,ghost11,ghost22;


extern char grid[ROW][COL];
void ghost1_direction()
{
    int ghost1;
    srand((unsigned) time(NULL));

    ghost1=(rand()%4)+1;


    if(ghost1==1)
        ghost1_dir=UP1;
        else if(ghost1==2)
            ghost1_dir=DOWN1;
    if(ghost1==3)
       ghost1_dir=LEFT1;
       else
        ghost1_dir=RIGHT1;
}

void ghost2_direction()
    {
        int ghost2;
        //srand((unsigned) time(NULL));
        ghost2=(rand()%4)+1;

        switch(ghost2)
        {
        case 1:
        case 3:


                ghost2_dir=LEFT1;
                break;

        case 2:
        case 4:

                ghost2_dir=RIGHT1;
                break;

        }

        ghost22=ghost2;
    }
