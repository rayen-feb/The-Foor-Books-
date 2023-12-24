
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <string.h>
#include <string.h>

void Enigme()


{

int nb_enigme=4;
SDL_Surface *win,*lost;
win=IMG_Load("resource_enigme/youWin1.png");
lost=IMG_Load("resource_enigme/gameOver.png");
SDL_Rect pos ;
pos.x=400;
pos.y=400;
    int hauteur_fenetre = 700;
    int     largeur_fenetre = 1300;

        //choisir type entite
        int t;
    //    printf("choisir type entite :\n0-> bad\t1-> good\n");
      //  scanf("%d",&t);
     
    SDL_Init(SDL_INIT_VIDEO);

    //FENETRE PRINCIPALE
    SDL_Surface *screen = NULL;
  screen = SDL_SetVideoMode(largeur_fenetre, hauteur_fenetre, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    SDL_WM_SetCaption("	THE FOOR BOOKS", NULL); // titre de la fenetre
  int enigme_right=0,e1=0,e2=0,e3=0,e4=0,e5=0,e6=0,e7=0,e8=0,rep=0 ;

    int c,w,b=0 ;
   // if (c==1)


for (int i=0;i<nb_enigme;i++)
{rep++;
enigme_right+=enigme(screen,&e1,&e2,&e3,&e4,&e5,&e6,&e7,&e8,rep,&b);
if(b)  break;}
if (enigme_right>=(nb_enigme/2))

{  
   SDL_BlitSurface(win,NULL,screen,&pos);
     SDL_Delay(2000);}
else{ 
 SDL_BlitSurface(lost,NULL,screen,&pos);
   SDL_Delay(2000);}
 //  SDL_free(screen);
}

