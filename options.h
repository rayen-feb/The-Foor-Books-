#ifndef OPTIONS_H_INCLUDED
#define OPTIONS_H_INCLUDED

#include "menu.h"

/**
* @struct opt
* @brief struct for opt
*/ 

typedef struct
{
    SDL_Surface *op[3]; /*!< Surface. */
    SDL_Surface *backbutton[3]; /*!< Surface. */
    SDL_Rect pos; /*!< Rectangle*/
}opt;

void option(SDL_Surface *screen);

#endif // OPTIONS_H_INCLUDED

