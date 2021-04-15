#include<stdio.h>
#include "header.h"

#define ROW 16
#define COL 16
extern char grid[ROW][COL]; 

void print_maze()
{
  int x;

   for(x=0;x<ROW;x++)
   {
     printf("%s\n",grid[x]);
   }
}