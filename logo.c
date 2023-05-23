#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h> /* Inclusion du header de SDL_image (adapter le dossier au besoin) */
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "logo.h"
void animation_logo()

{
int done=1;
while  (done!=0)    {



 SDL_Event event;
 
	if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1) //Initialisation de l'API Mixer

   {

      printf("%s", Mix_GetError());

   }

 Mix_VolumeMusic(MIX_MAX_VOLUME); //Mettre le volume à la moitié

   Mix_Music *musique; //Création d'un pointeur de type Mix_Music

  musique = Mix_LoadMUS("graphics/music.mp3"); //Chargement de la musique
  Mix_PlayMusic(musique, -1); //Jouer infiniment la musique
   
    Mix_AllocateChannels(32);
  // Mix_Chunk *son,*son1;
  // son = Mix_LoadWAV("son.wav");
  // son1=Mix_LoadWAV("son1.wav");
  // Mix_VolumeChunk(son, MIX_MAX_VOLUME);
  // Mix_VolumeChunk(son1, MIX_MAX_VOLUME);






	SDL_Surface *imageHP[1900];
	SDL_Surface *screen ;
 SDL_Init(SDL_INIT_EVERYTHING);
 screen = SDL_SetVideoMode(1200, 800, 32, SDL_HWSURFACE|SDL_DOUBLEBUF);

    int fr; 
    char imgname[1900];
  for (fr=0; fr<1900; fr++) 
    { 
        sprintf(imgname,"Logo/%d.png",fr+1); 
        imageHP[fr]=IMG_Load(imgname);
        SDL_BlitSurface(imageHP[fr],NULL,screen,NULL);
              SDL_Flip(screen); 
               SDL_FreeSurface(imageHP[fr]);

		  if (SDL_PollEvent(&event))
        {
            switch(event.type)
            {

            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {
                case SDLK_ESCAPE:
                    done=0;
                  fr=1900;
                    break;
 }              
 }
 }


    }
 
 
}
  }
