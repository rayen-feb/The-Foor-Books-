/* Author : YANN DROY */
/******** 2015 ********/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SDL/SDL.h>
#include "image.h"
#include "defs.h"

void split_image (SDL_Surface* image, SDL_Rect* clip, int n){
  int i, j, x = 0;

  for(i = 0; i < image->w; i += (image->w / n)){
    for(j = 0; j < image->h; j += (image->h / n)){
      clip[x].w = image->w / n;
      clip[x].h = image->h / n;
      clip[x].x = j;
      clip[x].y = i;
      x++;
    }
  }
}

int** create_table (int lines, int columns){
  int** tab = (int**) malloc(sizeof(int*) * lines);
  int* tab2 = (int*) malloc(sizeof(int) * columns * lines);
  int i;

  for(i = 0; i < lines; i++)
    tab[i] = &tab2[i * columns];

  if(tab == NULL){
    fprintf(stderr, "Table allocation failure\n");
    exit(EXIT_FAILURE);
  }

  return tab;
}

SDL_Rect* create_clip (int n){
  SDL_Rect* clip = NULL;

  clip = malloc(n * n * (sizeof(SDL_Rect)));
  return clip;
}

void init_table (int** table, int n){
  int i, j, k = 0;
  
  for(i = 0; i < n; i++){
    for(j = 0; j < n; j++){
      table[i][j] = k;
      k++;
    }
  }
}

void scramble (int** table, int moves, int n){
  int hole_i, hole_j;
  int i = 0, j, k;
  int direction, previous = -1;

  while(i < moves){
    for(j = 0; j < n; j++){
      for(k = 0; k < n; k++){
	if(table[j][k] == (n * n - 1)){
	  hole_i = j;
	  hole_j = k;
	}
      }
    }
    
    direction = rand() % 4;
    switch(direction){
    case UP:
      if(hole_i < n - 1 && previous != DOWN){
	swap(UP, table, hole_i, hole_j);
	i++;
	previous = direction;
      }
      break;
    case DOWN:
      if(hole_i > 0 && previous != UP){
	swap(DOWN, table, hole_i, hole_j);
	i++;
	previous = direction;
      }
      break;
    case RIGHT:
      if(hole_j > 0 && previous != LEFT){
	swap(RIGHT, table, hole_i, hole_j);
	i++;
	previous = direction;
      }
      break;
    case LEFT:
      if(hole_j < n - 1 && previous != RIGHT){
	swap(LEFT, table, hole_i, hole_j);
	i++;
	previous = direction;
      }
      break;
    }
  }
}

void swap (int direction, int** table, int i, int j){
  int tmp;

  switch(direction){
  case UP:
    tmp = table[i][j];
    table[i][j] = table[i + 1][j];
    table[i + 1][j] = tmp;
    break;
  case DOWN:
    tmp = table[i][j];
    table[i][j] = table[i - 1][j];
    table[i - 1][j] = tmp;
    break;
  case RIGHT:
    tmp = table[i][j];
    table[i][j] = table[i][j - 1];
    table[i][j - 1] = tmp;
    break;
  case LEFT:
    tmp = table[i][j];
    table[i][j] = table[i][j + 1];
    table[i][j + 1] = tmp;
    break;
  default:
    break;
  }
}

int win_test (int** table, int n){
  int i, j, k = 0;

  for(i = 0; i < n; i++){
    for(j = 0; j < n; j++){
      if(table[i][j] != k)
	return 0;
      k++;
    }
  }
  return 1;
}
