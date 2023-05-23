#ifndef QUIT_H_INCLUDED
#define QUIT_H_INCLUDED

#include "menu.h"

/**
* @struct quitter
* @brief struct for quitter
*/

typedef struct
{
    SDL_Surface *exit[7]; /*!< Surface. */
}quitter;

int quit(SDL_Surface *screen);
#endif // QUIT_H_INCLUDED
