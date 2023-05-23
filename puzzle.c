
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "resources_puzzle/display.h"
#include "resources_puzzle/image.h"
#include "resources_puzzle/menu_puzzle.h"
#include "resources_puzzle/file_rw.h"
#include "defs.h"
#include"structs.h"
void  puzzle (SDL_Surface* screen){
  int** table = NULL;
  SDL_Rect* clip = NULL;
  SDL_Surface *image=NULL;
  char name[8] = {0};
  int x, rune = 1;
  int n = 4, nb_moves, n_tmp;
  int change_image = 1;
  
  srand(time(NULL));
  init_puzzle();
  n_tmp = n;

  while(rune){
    nb_moves = 0;

    if(change_image)
      x = rand() % 8;
    change_image = 1;

    //sprintf(name, "./Pictures/%d.jpg", x);
    image = IMG_Load("5.jpg");
    
    if(image == NULL){
      fprintf(stderr, "Image loading failure : %s.\n", SDL_GetError());
      exit(EXIT_FAILURE);
    }
    
    init_window(&screen, image->w, image->h);

    table = create_table(n, n);
    init_table(table, n);

    clip = create_clip(n);    
    split_image(image, clip, n);
    scramble(table, (2 * n * n), n);
    display_image(screen, image, table, n, clip);
    
    game(screen, image, table, clip, &nb_moves, &n, &rune, name);
    
    if(n != n_tmp){
      n_tmp = n;
      change_image = 0;
    }else if(rune){
      load_leaderboards(screen, n);
      menu_puzzle(&rune, 1);
    }
    
    SDL_FreeSurface(image);
   // SDL_FreeSurface(screen);
    free(table);
    free(clip);
  }
  
  sdl_kill();
  
}
