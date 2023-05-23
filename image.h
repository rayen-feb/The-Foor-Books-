/* Author : YANN DROY */
/******** 2015 ********/

#ifndef __IMAGE__
#define __IMAGE__

void split_image (SDL_Surface* image, SDL_Rect* clip, int n);

int** create_table (int lines, int columns);

SDL_Rect* create_clip (int n);

void init_table (int** table, int n);

void scramble (int** table, int moves, int n);

void swap (int direction, int** table, int i, int j);

int win_test (int** table, int n);

#endif
