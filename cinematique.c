#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h> /* Inclusion du header de SDL_image (adapter le dossier au besoin) */
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "animation_logo.h"

void  cinematique()
{ 
	SDL_Surface *imageHP[1728];
	SDL_Surface *ecran = NULL ;
        SDL_Init(SDL_INIT_EVERYTHING);
        ecran = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE|SDL_DOUBLEBUF);
        if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1) //Initialisation de l'API Mixer
        {
            printf("%s", Mix_GetError());
        }
        Mix_VolumeMusic(MIX_MAX_VOLUME); //Mettre le volume à la moitié
        Mix_Music *musique; //Création d'un pointeur de type Mix_Music
        musique = Mix_LoadMUS("cine.mp3"); //Chargement de la musique
        Mix_PlayMusic(musique, -1); //Jouer infiniment la musique
        int fr; 
        char imgname[1728]; 
        for (fr=0; fr<1728; fr++) 
        { 
           sprintf(imgname,"cinematique/(%d).png",fr+1); 
           imageHP[fr]=IMG_Load(imgname);
           SDL_BlitSurface(imageHP[fr],NULL,ecran,NULL);
           SDL_Flip(ecran); 
           SDL_Delay(30);
           SDL_FreeSurface(imageHP[fr]);
          } }
