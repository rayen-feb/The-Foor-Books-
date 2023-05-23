
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "resources_puzzle/display.h"
#include "resources_puzzle/file_rw.h"
#include "resources_puzzle/image.h"
#include "defs.h"

void init_puzzle (){
  if(SDL_Init(SDL_INIT_VIDEO) == -1){
    fprintf(stderr, "SDL loading failure : %s.\n", SDL_GetError());
    exit(EXIT_FAILURE);
  }
  if(TTF_Init() == -1){
    fprintf(stderr, "TTF loading failure : %s.\n", TTF_GetError());
    exit(EXIT_FAILURE);
  }
  
  test_file("resources_puzzle/leaderboard3.txt");
  test_file("resources_puzzle/leaderboard4.txt");
  test_file("resources_puzzle/leaderboard5.txt");
  test_file("resources_puzzle/leaderboard6.txt");
}

void init_window (SDL_Surface** window, int width, int heigth){
  *window = SDL_SetVideoMode(width, heigth, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);

  if(window == NULL){
    fprintf(stderr, "Window opening failure : %s.\n", SDL_GetError());
    exit(EXIT_FAILURE);
  }else{
    SDL_WM_SetCaption("THE FOOR BOOKS  PUZZLE ", NULL);
    SDL_Flip(*window);
  }
}

void sdl_kill (){
  SDL_Quit();
  TTF_Quit();
}

void display_image (SDL_Surface* window, SDL_Surface* image, int** table, int n, SDL_Rect* clip){
  SDL_Rect position;
  int i, j;

  position.x = 0;
  position.y = 0;

  for(i = 0; i < n; i++){
    for(j = 0; j < n; j++){
      if(table[i][j] == (n * n - 1))
	SDL_FillRect(image, &clip[table[i][j]], (SDL_MapRGB(window->format, 40, 40, 40)));
      SDL_BlitSurface(image, &clip[table[i][j]], window, &position);
      position.x += image->w / n;
    }
    position.x = 0;
    position.y += image->h / n;
  }
  SDL_Flip(window);
}

void display_fullimage(SDL_Surface* window, char* name){
  SDL_Surface* image;
  SDL_Rect position;

  position.x = 0;
  position.y = 0;

  image = IMG_Load(name);
  SDL_BlitSurface(image, NULL, window, &position);
  SDL_Flip(window);

  SDL_FreeSurface(image);
}

void display_moveup(SDL_Surface* window, SDL_Surface* image, int** table, int n, SDL_Rect* clip){
  SDL_Rect position_hole;
  SDL_Rect blit_position_piece;
  SDL_Rect blit_position_hole;
  int i, j;
  int hole_i, hole_j, piece_i, piece_j;

  for(i = 0; i < n; i++){
    for(j = 0; j < n; j++){
      if(table[i][j] == (n * n - 1)){
	hole_i = i;
	hole_j = j;
	piece_i = i + 1;
	piece_j = j;
      }
    }
  }

  position_hole.w = image->w / n;
  position_hole.h = 2;
  position_hole.x = clip[table[hole_i][hole_j]].x;
  position_hole.y = clip[table[hole_i][hole_j]].y;

  blit_position_piece.x = piece_j * image->w / n;
  blit_position_piece.y = piece_i * image->h / n;

  blit_position_hole.x = blit_position_piece.x;
  blit_position_hole.y = blit_position_piece.y + image->h / n;

  for(i = 0; i < image->h / n; i += 2){
    (blit_position_piece.y) -= 2;
    (blit_position_hole.y) -= 2;
    SDL_BlitSurface(image, &clip[table[piece_i][piece_j]], window, &blit_position_piece);
    SDL_BlitSurface(image, &position_hole, window, &blit_position_hole);
    SDL_Flip(window);
  }
}

void display_movedown(SDL_Surface* window, SDL_Surface* image, int** table, int n, SDL_Rect* clip){
  SDL_Rect position_hole;
  SDL_Rect blit_position_piece;
  SDL_Rect blit_position_hole;
  int i, j;
  int hole_i, hole_j, piece_i, piece_j;

  for(i = 0; i < n; i++){
    for(j = 0; j < n; j++){
      if(table[i][j] == (n * n - 1)){
	hole_i = i;
	hole_j = j;
	piece_i = i - 1;
	piece_j = j;
      }
    }
  }

  position_hole.w = image->w / n;
  position_hole.h = 2;
  position_hole.x = clip[table[hole_i][hole_j]].x;
  position_hole.y = clip[table[hole_i][hole_j]].y;

  blit_position_piece.x = piece_j * image->w / n;
  blit_position_piece.y = piece_i * image->h / n;

  blit_position_hole.x = blit_position_piece.x;
  blit_position_hole.y = blit_position_piece.y - 2;

  for(i = 0; i < image->h / n; i += 2){
    (blit_position_piece.y) += 2;
    (blit_position_hole.y) += 2;
    SDL_BlitSurface(image, &clip[table[piece_i][piece_j]], window, &blit_position_piece);
    SDL_BlitSurface(image, &position_hole, window, &blit_position_hole);
    SDL_Flip(window);
  }
}

void display_moveright(SDL_Surface* window, SDL_Surface* image, int** table, int n, SDL_Rect* clip){
  SDL_Rect position_hole;
  SDL_Rect blit_position_piece;
  SDL_Rect blit_position_hole;
  int i, j;
  int hole_i, hole_j, piece_i, piece_j;

  for(i = 0; i < n; i++){
    for(j = 0; j < n; j++){
      if(table[i][j] == (n * n -1)){
	hole_i = i;
	hole_j = j;
	piece_i = i;
	piece_j = j - 1;
      }
    }
  }

  position_hole.h = image->w / n;
  position_hole.w = 2;
  position_hole.x = clip[table[hole_i][hole_j]].x;
  position_hole.y = clip[table[hole_i][hole_j]].y;

  blit_position_piece.x = piece_j * image->w / n;
  blit_position_piece.y = piece_i * image->h / n;

  blit_position_hole.x = blit_position_piece.x - 2;
  blit_position_hole.y = blit_position_piece.y;

  for(i = 0; i < image->w / n; i += 2){
    (blit_position_piece.x) += 2;
    (blit_position_hole.x) += 2;
    SDL_BlitSurface(image, &clip[table[piece_i][piece_j]], window, &blit_position_piece);
    SDL_BlitSurface(image, &position_hole, window, &blit_position_hole);
    SDL_Flip(window);
  }
}

void display_moveleft(SDL_Surface* window, SDL_Surface* image, int** table, int n, SDL_Rect* clip){
  SDL_Rect position_hole;
  SDL_Rect blit_position_piece;
  SDL_Rect blit_position_hole;
  int i, j;
  int hole_i, hole_j, piece_i, piece_j;

  for(i = 0; i < n; i++){
    for(j = 0; j < n; j++){
      if(table[i][j] == (n * n - 1)){
	hole_i = i;
	hole_j = j;
	piece_i = i;
	piece_j = j + 1;
      }
    }
  }

  position_hole.h = image->w / n;
  position_hole.w = 2;
  position_hole.x = clip[table[hole_i][hole_j]].x;
  position_hole.y = clip[table[hole_i][hole_j]].y;

  blit_position_piece.x = piece_j * image->w / n;
  blit_position_piece.y = piece_i * image->h / n;

  blit_position_hole.x = blit_position_piece.x + image->w / n;
  blit_position_hole.y = blit_position_piece.y;

  for(i = 0; i < image->w / n; i += 2){
    (blit_position_piece.x) -= 2;
    (blit_position_hole.x) -= 2;
    SDL_BlitSurface(image, &clip[table[piece_i][piece_j]], window, &blit_position_piece);
    SDL_BlitSurface(image, &position_hole, window, &blit_position_hole);
    SDL_Flip(window);
  }
}

void display_which_place (SDL_Surface* window, SDL_Surface* image, int** table, SDL_Rect* clip, int n, int x, int y){
  SDL_Surface* width = NULL;
  SDL_Surface* heigth = NULL;
  SDL_Rect position;

  width = SDL_CreateRGBSurface(SDL_HWSURFACE, image->w / n, 2, 32, 0, 0, 0, 0);
  heigth = SDL_CreateRGBSurface(SDL_HWSURFACE, 2, image->h / n, 32, 0, 0, 0, 0);
  SDL_FillRect(width, NULL, (SDL_MapRGB(window->format, 240, 10, 30)));
  SDL_FillRect(heigth, NULL, (SDL_MapRGB(window->format, 240, 10, 30)));

  position.x = clip[table[y][x]].x;
  position.y = clip[table[y][x]].y;
  SDL_BlitSurface(width, NULL, window, &position);
  SDL_BlitSurface(heigth, NULL, window, &position);

  position.x += image->w / n - 2;
  SDL_BlitSurface(heigth, NULL, window, &position);

  position.x = clip[table[y][x]].x;
  position.y += image->w / n - 2;
  SDL_BlitSurface(width, NULL, window, &position);

  SDL_Flip(window);

  SDL_FreeSurface(width);
  SDL_FreeSurface(heigth);
}

void display_which_clip (SDL_Surface* window, SDL_Surface* image, int** table, SDL_Rect* clip, int n, int x, int y){
  SDL_Surface* width = NULL;
  SDL_Surface* heigth = NULL;
  SDL_Rect position;
  int i, j, piece, piece_i, piece_j;

  width = SDL_CreateRGBSurface(SDL_HWSURFACE, image->w / n, 2, 32, 0, 0, 0, 0);
  heigth = SDL_CreateRGBSurface(SDL_HWSURFACE, 2, image->h / n, 32, 0, 0, 0, 0);
  SDL_FillRect(width, NULL, (SDL_MapRGB(window->format, 90, 240, 70)));
  SDL_FillRect(heigth, NULL, (SDL_MapRGB(window->format, 90, 240, 70)));

  for(i = 0; i < n * n; i++){
    if(clip[i].x / (image->w / n) == x && clip[i].y / (image->h / n) == y)
      piece = i;
  }

  for(i = 0; i < n; i++){
    for(j = 0; j < n; j++){
      if(table[i][j] == piece){
	piece_i = i;
	piece_j = j;
      }
    }
  }
    
  position.x = piece_j * (image->w / n);
  position.y = piece_i * (image->h / n);
  SDL_BlitSurface(width, NULL, window, &position);
  SDL_BlitSurface(heigth, NULL, window, &position);

  position.x += image->w / n - 2;
  SDL_BlitSurface(heigth, NULL, window, &position);

  position.x = piece_j * (image->w / n);
  position.y += image->w / n - 2;
  SDL_BlitSurface(width, NULL, window, &position);

  SDL_Flip(window);

  SDL_Delay(1200);

  SDL_FreeSurface(width);
  SDL_FreeSurface(heigth);
}

void get_player (SDL_Surface* window, char* name, int nb_moves){
  SDL_Surface* background = NULL;
  SDL_Surface* text = NULL;
  SDL_Rect position;
  TTF_Font* font = NULL;
  SDL_Color color1 = {220, 220, 220};
  SDL_Color color2 = {40, 40, 40};
  SDL_Color color3 = {220, 200, 0};
  SDL_Color color4 = {220, 0, 0};
  SDL_Event event;
  char moves_string[6] = {0};
  int wait = 1, i = 0;

  font = TTF_OpenFont("resources_puzzle/font.ttf", (window->h / 10));

  background = SDL_CreateRGBSurface(SDL_HWSURFACE, window->w, window->h, 32, 0, 0, 0, 0);
  SDL_FillRect(background, NULL, (SDL_MapRGB(window->format, 40, 40, 40)));
  position.x = 0;
  position.y = 0;
  SDL_BlitSurface(background, NULL, window, &position);

  sprintf(moves_string, "%d", nb_moves);
  text = TTF_RenderText_Shaded(font, moves_string, color4, color2);
  position.x = window->w / 2 - text->w / 2;
  position.y = window->h / 16;
  SDL_BlitSurface(text, NULL, window, &position);
  
  position.y += text->h + window->h / 16;
  SDL_FreeSurface(text);
  text = TTF_RenderText_Shaded(font, "Player name ?", color1, color2);
  position.x = window->w / 2 - text->w / 2;
  
  SDL_BlitSurface(text, NULL, window, &position);

  position.x = window->w / 16;
  position.y = window->h / 2;

  while(wait){
    SDL_Flip(window);

    SDL_WaitEvent(&event);
    switch(event.type){
    case SDL_QUIT:
      exit(EXIT_SUCCESS);
    case SDL_KEYDOWN:
      switch(event.key.keysym.sym){
      case SDLK_ESCAPE:
	exit(EXIT_SUCCESS);
      case SDLK_RETURN:
	if(i > 0)
	  wait = 0;
	break;
      case SDLK_KP_ENTER:
	wait = 0;
	break;
      case SDLK_a:
	if(i < 11){
	  name[i] = 'a';
	  SDL_FreeSurface(text);
	  text = TTF_RenderText_Shaded(font, "a", color3, color2);
	  SDL_BlitSurface(text, NULL, window, &position);
	  position.x += text->w;
	  i++;
	}
	break;
      case SDLK_z:
	if(i < 11){
	  name[i] = 'z';
	  SDL_FreeSurface(text);
	  text = TTF_RenderText_Shaded(font, "z", color3, color2);
	  SDL_BlitSurface(text, NULL, window, &position);
	  position.x += text->w;
	  i++;
	}
	break;
      case SDLK_e:
	if(i < 11){
	  name[i] = 'e';
	  SDL_FreeSurface(text);
	  text = TTF_RenderText_Shaded(font, "e", color3, color2);
	  SDL_BlitSurface(text, NULL, window, &position);
	  position.x += text->w;
	  i++;
	}
	break;
      case SDLK_r:
	if(i < 11){
	  name[i] = 'r';
	  SDL_FreeSurface(text);
	  text = TTF_RenderText_Shaded(font, "r", color3, color2);
	  SDL_BlitSurface(text, NULL, window, &position);
	  position.x += text->w;
	  i++;
	}
	break;
      case SDLK_t:
	if(i < 11){
	  name[i] = 't';
	  SDL_FreeSurface(text);
	  text = TTF_RenderText_Shaded(font, "t", color3, color2);
	  SDL_BlitSurface(text, NULL, window, &position);
	  position.x += text->w;
	  i++;
	}
	break;
      case SDLK_y:
	if(i < 11){
	  name[i] = 'y';
	  SDL_FreeSurface(text);
	  text = TTF_RenderText_Shaded(font, "y", color3, color2);
	  SDL_BlitSurface(text, NULL, window, &position);
	  position.x += text->w;
	  i++;
	}
	break;
      case SDLK_u:
	if(i < 11){
	  name[i] = 'u';
	  SDL_FreeSurface(text);
	  text = TTF_RenderText_Shaded(font, "u", color3, color2);
	  SDL_BlitSurface(text, NULL, window, &position);
	  position.x += text->w;
	  i++;
	}
	break;
      case SDLK_i:
	if(i < 11){
	  name[i] = 'i';
	  SDL_FreeSurface(text);
	  text = TTF_RenderText_Shaded(font, "i", color3, color2);
	  SDL_BlitSurface(text, NULL, window, &position);
	  position.x += text->w;
	  i++;
	}
	break;
      case SDLK_o:
	if(i < 11){
	  name[i] = 'o';
	  SDL_FreeSurface(text);
	  text = TTF_RenderText_Shaded(font, "o", color3, color2);
	  SDL_BlitSurface(text, NULL, window, &position);
	  position.x += text->w;
	  i++;
	}
	break;
      case SDLK_p:
	if(i < 11){
	  name[i] = 'p';
	  SDL_FreeSurface(text);
	  text = TTF_RenderText_Shaded(font, "p", color3, color2);
	  SDL_BlitSurface(text, NULL, window, &position);
	  position.x += text->w;
	  i++;
	}
	break;
      case SDLK_q:
	if(i < 11){
	  name[i] = 'q';
	  SDL_FreeSurface(text);
	  text = TTF_RenderText_Shaded(font, "q", color3, color2);
	  SDL_BlitSurface(text, NULL, window, &position);
	  position.x += text->w;
	  i++;
	}
	break;
      case SDLK_s:
	if(i < 11){
	  name[i] = 's';
	  SDL_FreeSurface(text);
	  text = TTF_RenderText_Shaded(font, "s", color3, color2);
	  SDL_BlitSurface(text, NULL, window, &position);
	  position.x += text->w;
	  i++;
	}
	break;
      case SDLK_d:
	if(i < 11){
	  name[i] = 'd';
	  SDL_FreeSurface(text);
	  text = TTF_RenderText_Shaded(font, "d", color3, color2);
	  SDL_BlitSurface(text, NULL, window, &position);
	  position.x += text->w;
	  i++;
	}
	break;
      case SDLK_f:
	if(i < 11){
	  name[i] = 'f';
	  SDL_FreeSurface(text);
	  text = TTF_RenderText_Shaded(font, "f", color3, color2);
	  SDL_BlitSurface(text, NULL, window, &position);
	  position.x += text->w;
	  i++;
	}
	break;
      case SDLK_g:
	if(i < 11){
	  name[i] = 'g';
	  SDL_FreeSurface(text);
	  text = TTF_RenderText_Shaded(font, "g", color3, color2);
	  SDL_BlitSurface(text, NULL, window, &position);
	  position.x += text->w;
	  i++;
	}
	break;
      case SDLK_h:
	if(i < 11){
	  name[i] = 'h';
	  SDL_FreeSurface(text);
	  text = TTF_RenderText_Shaded(font, "h", color3, color2);
	  SDL_BlitSurface(text, NULL, window, &position);
	  position.x += text->w;
	  i++;
	}
	break;
      case SDLK_j:
	if(i < 11){
	  name[i] = 'j';
	  SDL_FreeSurface(text);
	  text = TTF_RenderText_Shaded(font, "j", color3, color2);
	  SDL_BlitSurface(text, NULL, window, &position);
	  position.x += text->w;
	  i++;
	}
	break;
      case SDLK_k:
	if(i < 11){
	  name[i] = 'k';
	  SDL_FreeSurface(text);
	  text = TTF_RenderText_Shaded(font, "k", color3, color2);
	  SDL_BlitSurface(text, NULL, window, &position);
	  position.x += text->w;
	  i++;
	}
	break;
      case SDLK_l:
	if(i < 11){
	  name[i] = 'l';
	  SDL_FreeSurface(text);
	  text = TTF_RenderText_Shaded(font, "l", color3, color2);
	  SDL_BlitSurface(text, NULL, window, &position);
	  position.x += text->w;
	  i++;
	}
	break;
      case SDLK_m:
	if(i < 11){
	  name[i] = 'm';
	  SDL_FreeSurface(text);
	  text = TTF_RenderText_Shaded(font, "m", color3, color2);
	  SDL_BlitSurface(text, NULL, window, &position);
	  position.x += text->w;
	  i++;
	}
	break;
      case SDLK_w:
	if(i < 11){
	  name[i] = 'w';
	  SDL_FreeSurface(text);
	  text = TTF_RenderText_Shaded(font, "w", color3, color2);
	  SDL_BlitSurface(text, NULL, window, &position);
	  position.x += text->w;
	  i++;
	}
	break;
      case SDLK_x:
	if(i < 11){
	  name[i] = 'x';
	  SDL_FreeSurface(text);
	  text = TTF_RenderText_Shaded(font, "x", color3, color2);
	  SDL_BlitSurface(text, NULL, window, &position);
	  position.x += text->w;
	  i++;
	}
	break;
      case SDLK_c:
	if(i < 11){
	  name[i] = 'c';
	  SDL_FreeSurface(text);
	  text = TTF_RenderText_Shaded(font, "c", color3, color2);
	  SDL_BlitSurface(text, NULL, window, &position);
	  position.x += text->w;
	  i++;
	}
	break;
      case SDLK_v:
	if(i < 11){
	  name[i] = 'v';
	  SDL_FreeSurface(text);
	  text = TTF_RenderText_Shaded(font, "v", color3, color2);
	  SDL_BlitSurface(text, NULL, window, &position);
	  position.x += text->w;
	  i++;
	}
	break;
      case SDLK_b:
	if(i < 11){
	  name[i] = 'b';
	  SDL_FreeSurface(text);
	  text = TTF_RenderText_Shaded(font, "b", color3, color2);
	  SDL_BlitSurface(text, NULL, window, &position);
	  position.x += text->w;
	  i++;
	}
	break;
      case SDLK_n:
	if(i < 11){
	  name[i] = 'n';
	  SDL_FreeSurface(text);
	  text = TTF_RenderText_Shaded(font, "n", color3, color2);
	  SDL_BlitSurface(text, NULL, window, &position);
	  position.x += text->w;
	  i++;
	}
	break;
      case SDLK_KP1:
	if(i < 11){
	  name[i] = '1';
	  SDL_FreeSurface(text);
	  text = TTF_RenderText_Shaded(font, "1", color3, color2);
	  SDL_BlitSurface(text, NULL, window, &position);
	  position.x += text->w;
	  i++;
	}
	break;
      case SDLK_KP2:
	if(i < 11){
	  name[i] = '2';
	  SDL_FreeSurface(text);
	  text = TTF_RenderText_Shaded(font, "2", color3, color2);
	  SDL_BlitSurface(text, NULL, window, &position);
	  position.x += text->w;
	  i++;
	}
	break;
      case SDLK_KP3:
	if(i < 11){
	  name[i] = '3';
	  SDL_FreeSurface(text);
	  text = TTF_RenderText_Shaded(font, "3", color3, color2);
	  SDL_BlitSurface(text, NULL, window, &position);
	  position.x += text->w;
	  i++;
	}
	break;
      case SDLK_KP4:
	if(i < 11){
	  name[i] = '4';
	  SDL_FreeSurface(text);
	  text = TTF_RenderText_Shaded(font, "4", color3, color2);
	  SDL_BlitSurface(text, NULL, window, &position);
	  position.x += text->w;
	  i++;
	}
	break;
      case SDLK_KP5:
	if(i < 11){
	  name[i] = '5';
	  SDL_FreeSurface(text);
	  text = TTF_RenderText_Shaded(font, "5", color3, color2);
	  SDL_BlitSurface(text, NULL, window, &position);
	  position.x += text->w;
	  i++;
	}
	break;
      case SDLK_KP6:
	if(i < 11){
	  name[i] = '6';
	  SDL_FreeSurface(text);
	  text = TTF_RenderText_Shaded(font, "6", color3, color2);
	  SDL_BlitSurface(text, NULL, window, &position);
	  position.x += text->w;
	  i++;
	}
	break;
      case SDLK_KP7:
	if(i < 11){
	  name[i] = '7';
	  SDL_FreeSurface(text);
	  text = TTF_RenderText_Shaded(font, "7", color3, color2);
	  SDL_BlitSurface(text, NULL, window, &position);
	  position.x += text->w;
	  i++;
	}
	break;
      case SDLK_KP8:
	if(i < 11){
	  name[i] = '8';
	  SDL_FreeSurface(text);
	  text = TTF_RenderText_Shaded(font, "8", color3, color2);
	  SDL_BlitSurface(text, NULL, window, &position);
	  position.x += text->w;
	  i++;
	}
	break;
      case SDLK_KP9:
	if(i < 11){
	  name[i] = '9';
	  SDL_FreeSurface(text);
	  text = TTF_RenderText_Shaded(font, "9", color3, color2);
	  SDL_BlitSurface(text, NULL, window, &position);
	  position.x += text->w;
	  i++;
	}
	break;
      case SDLK_KP0:
	if(i < 11){
	  name[i] = '0';
	  SDL_FreeSurface(text);
	  text = TTF_RenderText_Shaded(font, "0", color3, color2);
	  SDL_BlitSurface(text, NULL, window, &position);
	  position.x += text->w;
	  i++;
	}
	break;
	/*case SDLK_BACKSPACE:
	i--;
	name[i] = '\0';
	if(position.x > window->w / 16)
	  position.x -= text->w;
	SDL_FreeSurface(text);
	text = TTF_RenderText_Shaded(font, "  ", color3, color2);
	SDL_BlitSurface(text, NULL, window, &position);
	break;*/
      default:
	break;
      }
      break;
    default:
      break;
    }
  }
  name[i] = '\0';

  SDL_FreeSurface(background);
  SDL_FreeSurface(text);
  TTF_CloseFont(font);
}
