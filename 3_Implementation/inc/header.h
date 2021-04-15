#include<stdlib>
#ifndef __HEADER_H__
#define __HEADER_H__

enum move {UP,DOWN,LEFT,RIGHT,STOP}direction;
enum ghost_move {UP1,DOWN1,LEFT1,RIGHT1,STOP1} ghost1_dir,ghost2_dir;
void ghost1_direction();
void ghost2_direction();
#endif 