
#include "defs.h"
typedef struct
{
    SDL_Surface* xoS;
    SDL_Rect xoR[4][4];
    SDL_Rect posxo[3];
    int tab[4][4];

    int tour;
    int winner;

}Xo;
typedef struct score
{
        Uint32 currentTime;
        Uint32 lastTime;
        int counter;
        bool pause;
    SDL_Surface *texte;
    SDL_Rect position;
    TTF_Font *police;
    SDL_Color couleur;
}score;


typedef struct Chrono
{
        Uint32 currentTime;
        Uint32 lastTime;
        int counter;
        bool pause;
    SDL_Surface *texte;
    SDL_Rect position;
    TTF_Font *police;
    SDL_Color couleur;
}Chrono;



typedef struct{
    char *dev_name;
    char *ard_return;
}ArduinoMaster;
typedef struct
{
    SDL_Rect pos;
    SDL_Surface *spritesheet;
    SDL_Rect clips[6];
    int cliploaded;
} animation;


typedef struct Minimap
{
        SDL_Surface *back;
        SDL_Surface*Dot;
        SDL_Rect posBlit;
        SDL_Rect posDot;
}Minimap;


typedef struct Input
{

    int left, right, up, down, jump, attack, enter, erase, pause;

} Input;
typedef struct Input2
{

    int left, right, up, down, jump, attack, enter, erase, pause;

} Input2;


typedef struct Monstre
   {
       
       SDL_Surface *sprite;
       int x, y;
       int frameNumber, frameTimer;
       int direction ;

   } Monstre;
typedef struct Gestion
{

    SDL_Surface *screen;
    SDL_Surface *screen2;
    SDL_Surface *background;
    SDL_Surface *background2;
   SDL_Surface *background1;
    SDL_Rect camera ; 
    SDL_Rect camera2;

    SDL_Rect pos_background ;
    SDL_Rect pos_background2; 
    int menuout;
    int on ;
    int on2;

} Gestion;


typedef struct vie
{
      SDL_Surface *img ;
      int x,y;

}vie;

typedef struct hero
{

    SDL_Surface *sprite;
    int frameNumber, frameTimer;
    int d,x,y;
   
    int hvie;
    
   
} hero;
typedef struct hero2
{

    SDL_Surface *sprite;
    int frameNumber, frameTimer;
    int d,x,y;
   
    int hvie;
    
   
} hero2;


typedef struct object
{
      SDL_Surface *imo;
      int x,y;
}object;
typedef struct object1
{
      SDL_Surface *imo;
      int x,y;
}object1;





