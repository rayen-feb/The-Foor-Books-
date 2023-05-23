/* Author : YANN DROY */
/******** 2015 ********/

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <string.h>
#include "resources_puzzle/file_rw.h"
#include "defs.h"

void load_leaderboards (SDL_Surface* window, int n){
  SDL_Surface* background = NULL;
  SDL_Surface* text = NULL;
  TTF_Font* font = NULL;
  TTF_Font* bigfont = NULL;
  SDL_Color color1 = {220, 220, 220};
  SDL_Color color2 = {40, 40, 40};
  SDL_Color color3 = {220, 200, 0};
  SDL_Color color4 = {150, 150, 150};
  SDL_Rect position;
  FILE* file = NULL;
  char string[17] = {0};
  char name[12] = {0};
  char** players = NULL;
  char c;
  int* scores = NULL;
  int i, number, number_tmp, current_score;

  font = TTF_OpenFont("font.ttf", (window->h / 30));
  bigfont = TTF_OpenFont("resources_puzzle/font.ttf", (window->h / 10));

  background = SDL_CreateRGBSurface(SDL_HWSURFACE, window->w, window->h, 32, 0, 0, 0, 0);
  SDL_FillRect(background, NULL, (SDL_MapRGB(window->format, 40, 40, 40)));
  position.x = 0;
  position.y = 0;
  SDL_BlitSurface(background, NULL, window, &position);

  text = TTF_RenderText_Shaded(font, "Ctrl + D : delete all leaderboards", color4, color2);
  position.x = window->w - text->w - window->w / 100;
  position.y = window->h - 2 * text->h - window->h / 100;
  SDL_BlitSurface(text, NULL, window, &position);

  SDL_FreeSurface(text);
  text = TTF_RenderText_Shaded(font, "Ctrl + # : delete leaderboard of #", color4, color2);
  position.x = window->w - text->w - window->w / 100;
  position.y += text->h;
  SDL_BlitSurface(text, NULL, window, &position);

  sprintf(string, "%d x %d", n, n);

  SDL_FreeSurface(text);
  text = TTF_RenderText_Shaded(bigfont, string, color3, color2);
  position.x = window->w / 2 - text->w / 2;
  position.y = window->h / 16;
  SDL_BlitSurface(text, NULL, window, &position);

  sprintf(string, "leaderboard%d.txt", n);
  file = fopen(string, "r");

  if(file == NULL){
    fprintf(stderr, "File opening failure.\n");
    exit(EXIT_FAILURE);
  }else{
    number = 0;

    while((c = fgetc(file)) != EOF){
      if(c == '\n')
	number++;
    }
    rewind(file);

    SDL_Flip(window);

    if(number > 0){
      scores = malloc(number * sizeof(int));
      players = malloc(number * sizeof(char**));
      for(i = 0; i < number; i++){
	players[i] = malloc(12 * sizeof(char*));
      }

      fseek(file, 19, SEEK_SET);
      for(i = 0; i < number; i++){
	fscanf(file, "%d %s", &current_score, name);
	scores[i] = current_score;
	strcpy(players[i], name);
      }
      sort(scores, players, number);

      if(number > 10){
	number_tmp = number;
	number = 10;
      }

      position.y = window->h / 4;

      for(i = 0; i < number; i++){
	position.x = window->w / 4;
	sprintf(string, "%d.", (i + 1));
	
	SDL_FreeSurface(text);
	text = TTF_RenderText_Shaded(font, string, color1, color2);
	SDL_BlitSurface(text, NULL, window, &position);

	SDL_FreeSurface(text);
	text = TTF_RenderText_Shaded(font, players[i], color1, color2);
	position.x = window->w / 2 - text->w / 2;
	SDL_BlitSurface(text, NULL, window, &position);

	sprintf(string, "%d", scores[i]);
	SDL_FreeSurface(text);
	text = TTF_RenderText_Shaded(font, string, color1, color2);
	position.x = 3 * window->w / 4 - text->w;
	SDL_BlitSurface(text, NULL, window, &position);

	position.y += 1.5 * text->h;
      }

      free(scores);
      number = number_tmp;
      for(i = 0; i < number; i++)
	free(players[i]);
    }
    fclose(file);
  }

  SDL_Flip(window);
  
  SDL_FreeSurface(background);
  SDL_FreeSurface(text);
  TTF_CloseFont(font);
  TTF_CloseFont(bigfont);
}

void delete_leaderboard (char* filename){
  FILE* file = NULL;

  file = fopen(filename, "w+");

  if(file == NULL){
    fprintf(stderr, "File opening failure.\n");
    exit(EXIT_FAILURE);
  }else{
    fprintf(file, "%s :", filename);
    fclose(file);
  }
}

void test_file (char* filename){
  FILE* file = NULL;

  file = fopen(filename, "r");

  if(file == NULL)
    delete_leaderboard(filename);
  else
    fclose(file);
}

void save_score (int n, int nfile, char* name){
  FILE* file = NULL;

  switch(nfile){
  case 3:
    file = fopen("resources_puzzle/leaderboard3.txt", "a");
    break;
  case 4:
    file = fopen("resources_puzzle/leaderboard4.txt", "a");
    break;
  case 5:
    file = fopen("resources_puzzle/leaderboard5.txt", "a");
    break;
  case 6:
    file = fopen("resources_puzzle/leaderboard6.txt", "a");
    break;
  }

  if(file == NULL){
    fprintf(stderr, "File opening failure.\n");
    exit(EXIT_FAILURE);
  }else{
    putc('\n', file);
    fprintf(file, "%d %s", n, name);
    fclose(file);
  }
}

void sort (int* scores, char* players[], int n){
  int i, j, tmp;
  char name_tmp[12] = {0};

  for(i = 1; i < n; i++){
    for(j = i; j > 0; j--){
      if(scores[j] < scores[j - 1]){
	tmp = scores[j];
	scores[j] = scores[j - 1];
        scores[j - 1] = tmp;

	strcpy(name_tmp, players[j]);
	strcpy(players[j], players[j - 1]);
	strcpy(players[j - 1], name_tmp);
      }
    }
  }
}
