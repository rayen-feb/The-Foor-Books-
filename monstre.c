#include "monstre.h"


  void initializeEnnemy(Monstre *monstre)
   {

       /* Charge le sprite de notre héros */
       monstre->sprite = loadImageN("graphics/runright.png");

      /* Coordonnées de démarrage de notre héros */
       monstre->x = 200;
       monstre->y = 280;
       monstre->direction=1;

   }

 void drawEnnemy(Monstre * monstre , Gestion *jeu)
{
    /* Rectangle de destination à blitter */
    SDL_Rect dest;

    dest.x = monstre->x;
    dest.y = monstre->y;
    dest.w = ENNEMY_WIDTH;
    dest.h = ENNEMY_HEIGHT;

    /* Rectangle source à blitter */
    SDL_Rect src;


    //Pour connaître le X de la bonne frame à blitter, il suffit de multiplier
    //la largeur du sprite par le numéro de la frame à afficher -> 0 = 0; 1 = 40; 2 = 80...
    src.x = monstre->frameNumber * ENNEMY_WIDTH;
    src.y = 0;
    src.w = ENNEMY_WIDTH;
    src.h = ENNEMY_HEIGHT;

    /* Blitte notre héros sur l'écran aux coordonnées x et y */

    SDL_BlitSurface(monstre->sprite, &src, jeu->screen, &dest);

}
