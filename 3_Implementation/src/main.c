#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<stdbool.h>
#include<windows.h>
#include "header.h"
#define ROW 21
#define COL 72




int row1,col1,row2,col2;
int row1ghost, col1ghost;
int row2ghost,col2ghost,ghost11,ghost22;


char layout[ROW][COL]= {
"***********************************************************************",
"*                                          &                          *",
"*   ********   *********   ***************   ********************     *",
"*   *      *   *       *   *             *   *                  *     *",
"*   *      *   *       *   *             *   *                  *     *",
"*   *      *   *       *   *             *   *                  *     *",
"*   *      *   *       *   *             *   *                  *     *",
"*   ********   *********   ***************   ********************     *",
"*                                ::                                   *",
"*   ****************************   ******************************     *",
"*   *                          *   *                            *     *",
"*   *                          *   *                            *     *",
"*   *                          *   *                            *     *",
"*   *                          *   *                            *     *",
"*   *                          *   *                            *     *",
"*   *                          *   *                            *     *",
"*   *                          *   *                            *     *",
"*   *                          *   *                            *     *",
"*   ****************************   ******************************     *",
"*                 $                                                   *",
"***********************************************************************"};
void print_layout()
{   
    int i;

    for(i=0;i<ROW;i++)
    printf("%s\n",layout[i]);

    printf("\ng2:%d dir: %d\n",ghost22,ghost2_dir);

    printf("\ng2:%d g2:%d\n",row2ghost,col2ghost);
    

}
void move_car(enum move dir)
{
    if(dir==UP)
    {
        if(layout[row1-1][col1]!= '*'& layout[row2-1][col2]!='*')
        {
           layout[row1][col1]=' ';
           layout[row1-1][col1]=':';
           layout[row2][col2]=' ';
           layout[row2-1][col2]=':';
           row1--;
           row2--;
            //printf("\nUP UP UP\n");
        }
    }
    else if(dir==DOWN)

    {
        if(layout[row1+1][col1]!= '*'& layout[row2+1][col2]!='*')
      {
           layout[row1][col1]=' ';
           layout[row1+1][col1]=':';
           layout[row2][col2]=' ';
           layout[row2+1][col2]=':';
           row1++;
           row2++;
           //printf("\nDOWN\n");
      }
    }
    if(dir==LEFT)
    {
       if(layout[row1][col1-1]!= '*'& layout[row2][col2-1]!='*')
       {
           layout[row1][col1]=' ';
           layout[row1][col1-1]=':';
           layout[row2][col2]=' ';
           layout[row2][col2-1]=':';
           col1--;
           col2--;
      }
    }
    else if(dir==RIGHT)

    {
       if(layout[row1][col1+1]!= '*'& layout[row2][col2+1]!='*')
       {
           layout[row2][col2]=' ';
           layout[row2][col2+1]=':';
           layout[row1][col1]=' ';
           layout[row1][col1+1]=':';

           col1++;
           col2++;
       }
    }
}
void ghost1_move(enum ghost_move g1_dir)
{
 // Beep(200,200);
  int x,y;
  if(g1_dir==UP1)
  {

      if(layout[row1ghost-1][col1ghost]!= '*')
      {
          layout[row1ghost][col1ghost]=' ';
          layout[row1ghost-1][col1ghost]='&';
          row1ghost--;

          if(layout[row1ghost][col1ghost]==layout[1][12]||layout[row1ghost][col1ghost]==layout[1][24]||layout[row1ghost][col1ghost] == layout[1][43])
          {
              x=rand()%2;
                switch (x)
                {
                case 0:

                        ghost1_dir = LEFT1;
                         break;


                case 1:

                        ghost1_dir = RIGHT1;
                        break;


                }
          }


          else if(layout[row1ghost][col1ghost]==layout[8][3])
            {
                x=rand()%2;
                switch (x)
                {
                case 0:
                    break;
                case 1:

                        ghost1_dir = RIGHT1;
                    break;


                }
            }
         else if(layout[row1ghost][col1ghost]==layout[1][3])
         {
             x=rand()%2;
            switch (x)
            {
                case 0:

                        ghost1_dir = RIGHT1;
                    break;


                case 1:

                        ghost1_dir = DOWN1;
                    break;


            }
         }
         else if(layout[row1ghost][col1ghost]==layout[8][68])
         {
             x=rand()%2;
            switch (x)
            {
                case 0:
                    break;
                case 1:

                        ghost1_dir = LEFT1;
                    break;


            }
         }
         else if(layout[row1ghost][col1ghost]==layout[1][68])
         {
             x=rand()%2;
            switch (x)
            {
                case 0:

                        ghost1_dir = LEFT1;
                    break;


                case 1:

                        ghost1_dir = DOWN1;
                    break;


            }
         }
         else if(layout[row1ghost][col1ghost]==layout[8][33])
         {
             x=rand()%2;
            switch (x)
            {
                case 0:

                        ghost1_dir = LEFT1;
                    break;


                case 1:

                        ghost1_dir = RIGHT1;
                    break;


            }

         }

    }
  }
  else if (g1_dir==DOWN1)
  {
      if(layout[row1ghost+1][col1ghost]!= '*')
      {
          layout[row1ghost][col1ghost]=' ';
          layout[row1ghost+1][col1ghost]='&';
          row1ghost++;

           if(layout[row1ghost][col1ghost]==layout[8][12]||layout[row1ghost][col1ghost]
              ==layout[8][24]||layout[row1ghost][col1ghost]== layout[8][43]||layout[row1ghost][col1ghost] == layout[19][33])
           {
               x=rand()%2;
            switch (x)
            {
                case 0:

                        ghost1_dir = LEFT1;
                    break;


                case 1:

                        ghost1_dir = RIGHT1;
                    break;



            }
           }


           else if(layout[row1ghost][col1ghost]==layout[8][3])
         {
             x=rand()%2;
            switch (x)
            {
                case 0:
                    break;
                case 1:

                        ghost1_dir = RIGHT1;
                    break;


            }
         }
         else if(layout[row1ghost][col1ghost]==layout[19][3])
         {
             x=rand()%2;
            switch (x)
            {
                case 0:

                        ghost1_dir = RIGHT1;
                    break;


                case 1:

                        ghost1_dir = UP1;
                    break;


            }
         }
         else if(layout[row1ghost][col1ghost]==layout[8][68])
         {
             x=rand()%2;
            switch (x)
            {
                case 0:
                    break;
                case 1:

                        ghost1_dir = LEFT1;
                    break;


            }
         }
         else if(layout[row1ghost][col1ghost]==layout[19][68])
         {
             x=rand()%2;
            switch (x)
            {
                case 0:

                        ghost1_dir = LEFT1;
                    break;


                case 1:

                        ghost1_dir = UP1;
                    break;


            }
         }
      }

  }
  if(g1_dir==LEFT1)
  {

      if(layout[row1ghost][col1ghost-1]!= '*')
      {
          layout[row1ghost][col1ghost]=' ';
          layout[row1ghost][col1ghost-1]='&';
          col1ghost--;
          if(layout[row1ghost][col1ghost]==layout[1][12]||layout[row1ghost][col1ghost]==layout[1][24]||layout[row1ghost][col1ghost] == layout[1][43])
          {
              x=rand()%2;
            switch (x)
            {
                case 0:
                    break;
                case 1:
                    {
                        ghost1_dir = DOWN1;
                    break;
                    }

            }
          }
          else if(layout[row1ghost][col1ghost]==layout[8][12]||layout[row1ghost][col1ghost]==layout[8][24]||layout[row1ghost][col1ghost] == layout[8][43])
          {
             x=rand()%2;
            switch (x)
            {
                case 0:
                    break;
                case 1:
                    {
                        ghost1_dir = UP1;
                    break;
                    }

            }
          }
         else if(layout[row1ghost][col1ghost]==layout[8][33])
         {
             x=rand()%2;
            switch (x)
            {
                case 0:
                    break;
                case 1:
                    {
                        ghost1_dir = DOWN1;
                    break;
                    }

            }
         }
         else if(layout[row1ghost][col1ghost]==layout[1][3])
         {
             x=rand()%2;
            switch (x)
            {
                case 0:
                    {
                        ghost1_dir = RIGHT1;
                    break;
                    }

                case 1:
                    {
                        ghost1_dir = DOWN1;
                    break;
                    }

            }
         }
         else if(layout[row1ghost][col1ghost]==layout[8][3])
         {
             x=rand()%2;
            switch (x)
            {
                case 0:
                    {
                        ghost1_dir = UP1;
                    break;
                    }

                case 1:
                    {
                        ghost1_dir = DOWN1;
                    break;
                    }

            }
         }
         else if(layout[row1ghost][col1ghost]==layout[19][3])
         {
             x=rand()%2;
            switch (x)
            {
                case 0:
                    {
                        ghost1_dir = UP1;
                    break;
                    }

                case 1:
                    {
                        ghost1_dir = RIGHT1;
                    break;
                    }

            }
         }

      }


  }
  else if (g1_dir==RIGHT1)
  {
      if(layout[row1ghost][col1ghost+1]!= '*')
      {
          layout[row1ghost][col1ghost]=' ';
          layout[row1ghost][col1ghost+1]='&';
          col1ghost++;

          if(layout[row1ghost][col1ghost]==layout[1][12]||layout[row1ghost][col1ghost]==layout[1][24]||layout[row1ghost][col1ghost] == layout[1][43])
          {

            x=rand()%2;
            switch (x)
            {
                case 0:
                    break;
                case 1:
                    {
                        ghost1_dir = DOWN1;
                    break;
                    }

            }
          }
          else if(layout[row1ghost][col1ghost]==layout[8][12]||layout[row1ghost][col1ghost]==layout[8][24]||layout[row1ghost][col1ghost] == layout[8][43])
          {
             x=rand()%2;
            switch (x)
            {
                case 0:
                    break;
                case 1:
                    {
                        ghost1_dir = UP1;
                    break;
                    }

            }
          }
          else if(layout[row1ghost][col1ghost]==layout[8][33])
         {
             x=rand()%2;
            switch (x)
            {
                case 0:
                    break;
                case 1:
                    {
                        ghost1_dir = DOWN1;
                    break;
                    }

            }
         }
         else if(layout[row1ghost][col1ghost]==layout[1][68])
         {
             x=rand()%2;
            switch (x)
            {
                case 0:
                    {
                        ghost1_dir = LEFT1;
                    break;
                    }

                case 1:
                    {
                        ghost1_dir = DOWN;
                    break;
                    }

            }
         }
         else if(layout[row1ghost][col1ghost]==layout[8][68])
         {
             x=rand()%2;
            switch (x)
            {
                case 0:
                    {
                        ghost1_dir = UP1;
                    break;
                    }

                case 1:
                    {
                        ghost1_dir = DOWN1;
                    break;
                    }

            }
         }
         else if(layout[row1ghost][col1ghost]==layout[19][68])
         {
             x=rand()%2;
            switch (x)
            {
                case 0:
                    {
                        ghost1_dir = UP1;
                    break;
                    }

                case 1:
                    {
                        ghost1_dir = LEFT1;
                    break;
                    }

            }
         }
      }

  }
}


void ghost2_move(enum ghost_move g2_dir)
{
 //Beep(200,250);
    int x,y;

    if(g2_dir==LEFT1)
    {

        if(layout[row2ghost][col2ghost-1]!= '*')
        {
          layout[row2ghost][col2ghost]=' ';
          layout[row2ghost][col2ghost-1]='$';
          col2ghost--;

            if(layout[row2ghost][col2ghost]==layout[19][33])
            {
              x=rand()%2;
              if(x==0||x==1)
                switch (x)
                {
                    case 0:
                    break;
                    case 1:
                    {
                        ghost2_dir = DOWN1;
                    break;
                    }

                }
           }
            else if(layout[row2ghost][col2ghost]==layout[19][3])
            {
                 x=rand()%2;
                 if(x==0||x==1)
                switch (x)
                {
                    case 0:
                        {
                            ghost2_dir= UP1;
                        break;
                        }

                    case 1:
                        {
                        ghost2_dir = RIGHT1;
                        break;
                        }

                }
            }
            if(layout[row2ghost][col2ghost]==layout[8][43]||layout[row2ghost][col2ghost]==layout[8][24]||layout[row2ghost][col2ghost]==layout[8][12])
            {
                x=rand()%2;
                if(x==0||x==1)
                switch (x)
              {
                case 0:
                    break;
                case 1:
                    {
                        ghost2_dir = UP1;
                    break;
                    }

              }
            }
           else if(layout[row2ghost][col2ghost]==layout[8][33])
           {
               x=rand()%2;
               if(x==0||x==1)
                switch (x)
              {
                case 0:
                    break;
                case 1:
                    {
                        ghost2_dir = DOWN1;
                    break;
                    }
              }

           }
           if(layout[row2ghost][col2ghost]==layout[1][3])
           {
               x=rand()%2;
               if(x==0||x==1)
                switch (x)
              {
                case 0:
                    {
                        ghost2_dir = RIGHT1;
                        break;
                    }

                case 1:
                    {
                        ghost2_dir = DOWN1;
                    break;
                    }
             }
          }
          else if(layout[row2ghost][col2ghost]==layout[1][12]||layout[row2ghost][col2ghost]==layout[1][24]||layout[row2ghost][col2ghost]==layout[1][43])
          {
              x=rand()%2;
              if(x==0||x==1)
                switch (x)
              {
                case 0:
                    {
                        ghost2_dir=LEFT1;
                        break;
                    }

                case 1:
                    {
                        ghost2_dir = DOWN1;
                        break;
                    }
             }
          }
        }
    }//if left
      if (g2_dir==RIGHT1)
        {
            if(layout[row2ghost][col2ghost+1]!= '*')
            {
                layout[row2ghost][col2ghost+1]='$';
                layout[row2ghost][col2ghost]=' ';
                col2ghost++;


                if(layout[row2ghost][col2ghost]==layout[19][33])
                {
                    x=rand()%2;
                    if(x==0||x==1)
                    switch (x)
                    {
                        case 0:
                        break;
                        case 1:
                        {
                            ghost2_dir = UP1;
                        break;
                        }

                    }
                }
               else if(layout[row2ghost][col2ghost]==layout[19][68])
                 {
                  x=rand()%2;
                  if(x==0||x==1)
                  switch (x)
                    {
                        case 0:
                        {
                            ghost2_dir = LEFT1;
                            break;
                        }
                        case 1:
                        {
                            ghost2_dir = UP1;
                            break;
                        }

                    }
                }
                if(layout[row2ghost][col2ghost]==layout[8][43]||layout[row2ghost][col2ghost]==layout[8][24]||layout[row2ghost][col2ghost]==layout[8][12])
                {


                   x=rand()%2;
                   if(x==0||x==1)
                  switch (x)
                    {
                        case 0:
                        {
                            break;
                        }
                        case 1:
                        {
                            ghost2_dir = UP1;
                            break;
                        }

                    }
                }
                else if(layout[row2ghost][col2ghost]==layout[8][33])
                {
                    x=rand()%2;
                    if(x==0||x==1)
                  switch (x)
                    {
                        case 0:
                        {
                            break;
                        }
                        case 1:
                        {
                            ghost2_dir = DOWN1;
                            break;
                        }

                    }
                }
        }//if with *

     }//if Right
     if (g2_dir==UP1)
     {

             if(layout[row2ghost-1][col2ghost]!= '*')
            {
                layout[row2ghost][col2ghost]=' ';
                layout[row2ghost-1][col2ghost]='$';
                row2ghost--;

                if(layout[row2ghost][col2ghost]==layout[8][3])
                {

                    x=rand()%2;
                    if(x==0||x==1)
                  switch (x)
                    {
                        case 0:
                        {
                            break;
                        }
                        case 1:
                        {
                            ghost2_dir = RIGHT1;
                            break;
                        }

                    }
                }
                else if (layout[row2ghost][col2ghost]==layout[8][68])
                {
                    x=rand()%2;
                  if(x==0||x==1)
                  switch (x)
                    {
                        case 0:
                        {
                            break;
                        }
                        case 1:
                        {
                            ghost2_dir = LEFT1;
                            break;
                        }

                    }
                }
                if(layout[row2ghost][col2ghost]==layout[8][33])
                {
                    x=rand()%2;
                    if(x==0||x==1)
                  switch (x)
                    {
                        case 0:
                        {
                            ghost2_dir= RIGHT1;
                            break;
                        }
                        case 1:
                        {
                            ghost2_dir = LEFT1;
                            break;
                        }

                    }
                }

                if(layout[row2ghost][col2ghost]==layout[1][12]||layout[row2ghost][col2ghost]==layout[1][24]||layout[row2ghost][col2ghost] == layout[1][43])
                {
                    x=rand()%2;
                    if(x==0||x==1)
                  switch (x)
                    {
                        case 0:
                        {
                            ghost2_dir= RIGHT1;
                            break;
                        }
                        case 1:
                        {
                            ghost2_dir = LEFT1;
                            break;
                        }

                    }
                }
                else if(layout[row2ghost][col2ghost]==layout[1][68])
                {
                    x=rand()%2;
                    if(x==0||x==1)
                  switch (x)
                    {
                        case 0:
                        {
                            ghost2_dir= DOWN1;
                            break;
                        }
                        case 1:
                        {
                            ghost2_dir = LEFT1;
                            break;
                        }

                    }
                }
                else if(layout[row2ghost][col2ghost]==layout[1][3])
                {
                    x=rand()%2;
                    if(x==0||x==1)
                  switch (x)
                    {
                        case 0:
                        {
                            ghost2_dir= DOWN1;
                            break;
                        }
                        case 1:
                        {
                            ghost2_dir = RIGHT1;
                            break;
                        }
                    }
                }
        }
     }// up1
     if (g2_dir==DOWN1)
     {
         if(layout[row2ghost+1][col2ghost]!= '*')
      {
          layout[row2ghost][col2ghost]=' ';
          layout[row2ghost+1][col2ghost]='$';
          row2ghost++;

           if(layout[row2ghost][col2ghost]==layout[8][3])
           {
                x=rand()%2;
                if(x==0||x==1)
               switch (x)
              {
                case 0:
                    {

                    break;
                    }

                case 1:
                    {
                        ghost2_dir = RIGHT1;
                    break;
                    }
              }


           }
           else if(layout[row2ghost][col2ghost]==layout[8][12])
           {
             x=rand()%2;
             if(x==0||x==1)
               switch (x)
              {
                case 0:
                    {
                       ghost2_dir = RIGHT1;
                       break;
                    }

                case 1:
                    {
                        ghost2_dir = RIGHT1;
                        break;
                    }
              }
           }
          else if(layout[row2ghost][col2ghost]==layout[8][43])
            {
                     x=rand()%2;
                     if(x==0||x==1)
                    switch (x)
                    {
                        case 0:
                            {
                                ghost2_dir = RIGHT1;
                                break;
                            }

                        case 1:
                            {
                                ghost2_dir = RIGHT1;
                                break;
                            }
                    }
            }
       }
     }
}
int main()
{
direction= STOP;
ghost1_dir = STOP1;
ghost2_dir = STOP1;
int i,count=20;
row1 = 8;
col1 =33;
row2 = 8;
col2 = 34;
row1ghost=1;
col1ghost=43;
row2ghost=19;
col2ghost=18;
char ch;
int* ptr;
    int bb=2;
    ptr= (int*)malloc(bb*sizeof(int));
    if(ptr==NULL)
    exit(0);
    free(ptr);
 print_layout();
ghost1_direction();
ghost2_direction();

 while(count)
 {
    if(_kbhit()){

       ch=_getch();
     switch(ch)
      {
        case '/':

                direction=RIGHT;
                break;


        case ',':

                direction=LEFT;
                break;


        case ';':

                direction = UP;
                break;


        case '.':

                direction = DOWN;
                break;


        default:;

      }
    }

    if(layout[row1ghost][col1ghost]==layout[row1][col1]||layout[row1ghost][col1ghost]==layout[row2][col2]||layout[row2ghost][col2ghost]==layout[row1][col1]||layout[row2ghost][col2ghost]==layout[row2][col2])
    {
        printf("\nGAME OVER\n");
        break;
    }
    move_car(direction);
   // ghost_direction();
    ghost1_move(ghost1_dir);

    ghost2_move(ghost2_dir);
    Beep(400,150);
    system("cls");
    print_layout();


 }
return 0;
}