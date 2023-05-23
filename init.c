#include "init.h"

/* Fonction qui initialise le jeu */

void init(char *title,  Gestion * jeu )
{


    if (SDL_Init(SDL_INIT_VIDEO  ) < 0)
    {
        printf("Could not initialize SDL: %s\n", SDL_GetError());
        exit(1);
    }


    jeu->screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32, SDL_HWSURFACE|SDL_DOUBLEBUF);
    jeu->screen = SDL_SetVideoMode(SCREEN_WIDTH/2, SCREEN_HEIGHT, 32, SDL_HWSURFACE|SDL_DOUBLEBUF);

    /* Si on y arrive pas, on quitte */

    if (jeu->screen == NULL)
    {
        printf("Couldn't set screen mode to %d x %d: %s\n", SCREEN_WIDTH, SCREEN_HEIGHT, SDL_GetError());
        exit(1);
    }


    /* On entre le titre de la fenêtre */

    SDL_WM_SetCaption(title, NULL);

    /* initialiser ttf */

    if (TTF_Init() == -1)
    {
        printf("Could not initialize SDL ttf : %s\n", SDL_GetError());
        exit(1);
    }
    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1) //Initialisation de l'API Mixer
{
   printf("%s", Mix_GetError());
}

    /* On cache le curseur de la souris */

    //  SDL_ShowCursor(SDL_DISABLE);
     

}





void loadGame(Gestion* jeu )
{

    /* Charge l'image du fond */
    jeu->background = loadImageN("graphics/background+.png");
    jeu->screen=0;
    jeu->camera.x=0;
    jeu->camera.y=0;
    jeu->camera.w=780;
    jeu->camera.h=480;
    jeu->pos_background.x=0;
    jeu->pos_background.y=0;
    jeu->pos_background.w=jeu->background->w;
    jeu->pos_background.h=jeu->background->h;
    jeu->on=0;

}

void loadGame1(Gestion* jeu )
{

    /* Charge l'image du fond */
    jeu->background1 = loadImageN("graphics/background.bmp");
    jeu->screen=0;
    jeu->camera.x=0;
    jeu->camera.y=0;
    jeu->camera.w=780;
    jeu->camera.h=480;
    jeu->pos_background.x=0;
    jeu->pos_background.y=0;
    jeu->pos_background.w=jeu->background->w;
    jeu->pos_background.h=jeu->background->h;
    jeu->on=0;

}

void loadGame2(Gestion* jeu )
{

    /* Charge l'image du fond */
    jeu->background2 = loadImageN("graphics/background++.png");
    jeu->screen=0;
    jeu->camera2.x=0;
    jeu->camera2.y=0;
    jeu->camera2.w=780;
    jeu->camera2.h=480;
    jeu->pos_background2.x=780;
    jeu->pos_background2.y=0;
    jeu->pos_background2.w=780;
    jeu->pos_background2.h=480;
    jeu->on2=0;

}

/* Fonction qui quitte le jeu proprement */
void cleanup()
{

    /* Quitte la SDL */
    TTF_Quit();
    SDL_Quit();
    Mix_CloseAudio();

}
void reset(hero * he,hero2 * he2 ,Monstre *monstre , vie v[4] , object o[5]) 
{int i = 0 ;
SDL_FreeSurface(monstre->sprite);
SDL_FreeSurface(he->sprite);
SDL_FreeSurface(he2->sprite);

for(i=1;i<4;i++)
{      SDL_FreeSurface(v[i].img);
       SDL_FreeSurface(o[i].imo);
}
SDL_FreeSurface(o[4].imo);
}

