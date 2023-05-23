/* Author : YANN DROY */
/******** 2015 ********/

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include "resources_puzzle/display.h"
#include "resources_puzzle/image.h"
#include "resources_puzzle/menu_puzzle.h"
#include "resources_puzzle/file_rw.h"
#include "defs.h"

void game (SDL_Surface* window, SDL_Surface* image, int** table, SDL_Rect* clip, int* nb_moves, int* n, int* run, char* name){
  SDL_Event event;
  char player[12] = {0};
  int wait = 1, win;
  int i, j, hole_i, hole_j;
  int click_x, click_y;

  while(wait){
    SDL_WaitEvent(&event);

    if((*nb_moves) == 1000000)
      wait = 0;

    win = win_test(table, *n);
    if(win){
      wait = 0;
      display_fullimage(window, name);
      SDL_Delay(1000);
      if((*n) != 2){
	get_player(window, player, (*nb_moves));
	save_score((*nb_moves), (*n), player);
      }
    }

    for(i = 0; i < *n; i++){
      for(j = 0; j < *n; j++){
	if(table[i][j] == (*n * *n - 1)){
	  hole_i = i;
	  hole_j = j;
	}
      }
    }

    switch(event.type){
    case SDL_QUIT:
      wait = 0;
      (*run) = 0;
      break;
    case SDL_KEYDOWN:
      switch(event.key.keysym.sym){
      case SDLK_UP:
	if(hole_i < (*n) - 1){
	  display_moveup(window, image, table, *n, clip);
	  swap(UP, table, hole_i, hole_j);
	  (*nb_moves)++;
	}
	break;
      case SDLK_DOWN:
	if(hole_i > 0){
	  display_movedown(window, image, table, *n, clip);
	  swap(DOWN, table, hole_i, hole_j);
	  (*nb_moves)++;
	}
	break;
      case SDLK_RIGHT:
	if(hole_j > 0){
	  display_moveright(window, image, table, *n, clip);
	  swap(RIGHT, table, hole_i, hole_j);
	  (*nb_moves)++;
	}
	break;
      case SDLK_LEFT:
	if(hole_j < (*n) - 1){
	  display_moveleft(window, image, table, *n, clip);
	  swap(LEFT, table, hole_i, hole_j);
	  (*nb_moves)++;
	}
	break;
      case SDLK_q:
	wait = 0;
	(*run) = 0;
	break;
      case SDLK_ESCAPE:
	//wait = 0;
	(*run) = 0;
	break;
      case SDLK_p:
	wait = 0;
	break;
      case SDLK_m:
	display_fullimage(window, name);
	menu_puzzle(run, 0);
	if((*run))
	  display_image(window, image, table, *n, clip);
	else
	  wait = 0;
	break;
      case SDLK_KP3:
	load_leaderboards(window, 3);
	menu_puzzle(run, 1);
	if((*run))
	  display_image(window, image, table, *n, clip);
	else
	  wait = 0;
	break;
      case SDLK_KP4:
	load_leaderboards(window, 4);
	menu_puzzle(run, 1);
	if((*run))
	  display_image(window, image, table, *n, clip);
	else
	  wait = 0;
	break;
      case SDLK_KP5:
	load_leaderboards(window, 5);
	menu_puzzle(run, 1);
	if((*run))
	  display_image(window, image, table, *n, clip);
	else
	  wait = 0;
	break;
      case SDLK_KP6:
	load_leaderboards(window, 6);
	menu_puzzle(run, 1);
	if((*run))
	  display_image(window, image, table, *n, clip);
	else
	  wait = 0;
	break;
      case SDLK_z:
	if((*n) < 6){
	  (*n)++;
	  wait = 0;
	}
	break;
      case SDLK_a:
	if((*n) > 3){
	  (*n)--;
	  wait = 0;
	}
	break;
      default:
	break;
      }
      break;
    case SDL_MOUSEBUTTONDOWN:
      click_x = event.button.x / (image->w / (*n));
      click_y = event.button.y / (image->h / (*n));
      switch(event.button.button){
      case SDL_BUTTON_LEFT:
	if(click_x == hole_j - 1 && click_y == hole_i){
	  display_moveright(window, image, table, *n, clip);
	  swap(RIGHT, table, hole_i, hole_j);
	  (*nb_moves)++;
	}else if(click_x == hole_j + 1 && click_y == hole_i){
	  display_moveleft(window, image, table, *n, clip);
	  swap(LEFT, table, hole_i, hole_j);
	  (*nb_moves)++;
	}else if(click_x == hole_j && click_y == hole_i + 1){
	  display_moveup(window, image, table, *n, clip);
	  swap(UP, table, hole_i, hole_j);
	  (*nb_moves)++;
	}else if(click_x == hole_j && click_y == hole_i - 1){
	  display_movedown(window, image, table, *n, clip);
	  swap(DOWN, table, hole_i, hole_j);
	  (*nb_moves)++;
	}
	break;
      case SDL_BUTTON_RIGHT:
	display_which_place(window, image, table, clip, (*n), click_x, click_y);
	break;
      default:
	break;
      }
      break;
    case SDL_MOUSEBUTTONUP:
      switch(event.button.button){
      case SDL_BUTTON_RIGHT:
	display_which_clip(window, image, table, clip, (*n), click_x, click_y);
	display_image(window, image, table, *n, clip);
	break;
      default:
	break;
      }
      break;
    default:
      break;
    }
  }
}

void menu_puzzle (int* run, int leaderboards){
  SDL_Event event;
  int wait = 1;
  int ctrl = 0;

  while(wait){
    SDL_WaitEvent(&event);
    switch(event.type){
    case SDL_QUIT:
      wait = 0;
      (*run) = 0;
      break;
    case SDL_KEYDOWN:
      switch(event.key.keysym.sym){
      case SDLK_q:
	wait = 0;
	(*run) = 0;
	break;
      case SDLK_ESCAPE:
	wait = 0;
	(*run) = 0;
	break;
      case SDLK_RETURN:
	wait = 0;
	break;
      case SDLK_KP_ENTER:
	wait = 0;
	break;
      case SDLK_BACKSPACE:
	wait = 0;
	break;
      case SDLK_LCTRL:
	ctrl = 1;
	break;
      case SDLK_RCTRL:
	ctrl = 1;
	break;
      case SDLK_d:
	if(leaderboards && ctrl){
	  wait = 0;
	  delete_leaderboard("resources_puzzle/leaderboard3.txt");
	  delete_leaderboard("resources_puzzle/leaderboard4.txt");
	  delete_leaderboard("resources_puzzle/leaderboard5.txt");
	  delete_leaderboard("resources_puzzle/leaderboard6.txt");
	  ctrl = 0;
	}
	break;
      case SDLK_KP3:
	if(leaderboards && ctrl){
	  wait = 0;
	  delete_leaderboard("resources_puzzle/leaderboard3.txt");
	  ctrl = 0;
	}
	break;
      case SDLK_KP4:
	if(leaderboards && ctrl){
	  wait = 0;
	  delete_leaderboard("resources_puzzle/leaderboard4.txt");
	  ctrl = 0;
	}
	break;
      case SDLK_KP5:
	if(leaderboards && ctrl){
	  wait = 0;
	  delete_leaderboard("resources_puzzle/leaderboard5.txt");
	  ctrl = 0;
	}
	break;
      case SDLK_KP6:
	if(leaderboards && ctrl){
	  wait = 0;
	  delete_leaderboard("resources_puzzle/leaderboard6.txt");
	  ctrl = 0;
	}
	break;
      default:
	break;
      }
    default:
      break;
    }
  }
}
