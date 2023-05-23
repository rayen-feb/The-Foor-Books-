#ifndef INSTRUCTION_H_INCLUDED
#define INSTRUCTION_H_INCLUDED

#include "menu.h"

/**
* @struct commands
* @brief struct for commands
*/


typedef struct
{ 
    SDL_Surface *instruction; /*!< Surface. */
    SDL_Surface *backbutton[3]; /*!< Surface. */
    SDL_Rect pos;/*!< Rectangle*/
}commands;

void instructions (SDL_Surface *screen);
#endif // INSTRUCTION_H_INCLUDED
