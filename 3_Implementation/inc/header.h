#ifndef __HEADER_H__
#define __HEADER_H__
void fill_grid_block();
void ghost_move(enum move dir);
void ghost_dir_int();
void ghost_path_possible();
void ghost_dir_final(enum move dir);
void print_maze();
#endif 