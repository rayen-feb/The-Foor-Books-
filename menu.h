#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>

/**
* @struct buttons
* @brief struct for buttons 
*/

typedef struct
{
    SDL_Surface *play[3]; /*!< Surface. */
    SDL_Surface *instructions[3]; /*!< Surface. */
    SDL_Surface *setting[3]; /*!< Surface. */
    SDL_Surface *exit[3];
    SDL_Surface *highscore[3]; /*!< Surface. */
}buttons;
void animation_logo();
void menu (int *menuout);
void cleanmenu(SDL_Surface *background);

#endif // MAIN_H_INCLUDED
