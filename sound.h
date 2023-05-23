#ifndef SOUND_H_INCLUDED
#define SOUND_H_INCLUDED

#include<SDL/SDL_mixer.h>
#include "menu.h"
void initialiser_audio(Mix_Music *music);
void initialiser_audiobref(Mix_Chunk *music);

#endif 
