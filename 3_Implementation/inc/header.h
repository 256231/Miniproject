//#include<stdlib>
#ifndef __HEADER_H__
#define __HEADER_H__

enum move {UP,DOWN,LEFT,RIGHT,STOP}direction;
enum ghost_move {UP1,DOWN1,LEFT1,RIGHT1,STOP1} ghost1_dir,ghost2_dir;
/**
*  Navigates ghost 1
* @return Returns 1 if successful
*/
int ghost1_direction();
/**
*  Navigates ghost 1
   @param[in] ghost22
* @return Returns 1 if successful
*/
int ghost2_direction(int a);
#endif 