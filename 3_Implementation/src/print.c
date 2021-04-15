#include<stdio.h>

void print_maze()
{
  int x;

   for(x=0;x<ROW;x++)
   {
     printf("%s\n",grid[x]);
   }
}