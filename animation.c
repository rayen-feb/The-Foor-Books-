
#include "animation.h"


void drawanimatedEnnemy(Monstre *monstre , hero he , Gestion * jeu)
{
    
    /* Gestion du timer */

    // Si notre timer (un compte à rebours en fait) arrive à zéro

    if (monstre->frameTimer <= 0)
    {
        //On le réinitialise

        monstre->frameTimer = TIME_BETWEEN_2_FRAMES;

        //Et on incrémente notre variable qui compte les frames de 1 pour passer à la suivante

        monstre->frameNumber++;
         if( jeu->on == 0 ) { 
            monstre->x +=  ( (monstre->direction) * 4 )  ;
                              }

          else if ( jeu->on == 1 ) {  monstre->x -=  ( (monstre->direction) * 1 )  ; }
            else if ( jeu->on == -1 ) {  monstre->x +=  ( (monstre->direction) * 4 )  ; }
		if ((monstre->x < he.x)&&(abs(monstre->x-he.x)<50))
		{
			monstre->direction = 0 ;
                        monstre->sprite = loadImageN("graphics/attackright.png");
		}

		if ((monstre->x > he.x)&&(abs(monstre->x-he.x)<50))
		{
			monstre->direction = 0 ;
                        monstre->sprite = loadImageN("graphics/attackleft.png");
		}
	
		
		if ((monstre->x < he.x)&&(abs(monstre->x-he.x)>100))
		{
			monstre->direction = 2 ;
                        monstre->sprite = loadImageN("graphics/runright.png");
		}
                if ((monstre->x > he.x)&&(abs(monstre->x-he.x)>100))
		{
			monstre->direction = -2 ;
                        monstre->sprite = loadImageN("graphics/runleft.png");
		}
                if ((monstre->x < he.x)&&(abs(monstre->x-he.x)<100)&&(abs(monstre->x-he.x)>50))
		{
			monstre->direction = 1 ;
                        monstre->sprite = loadImageN("graphics/walkright.png");
		}
                if ((monstre->x > he.x)&&(abs(monstre->x-he.x)<100)&&(abs(monstre->x-he.x)>50))
		{
			monstre->direction = -1 ;
                        monstre->sprite = loadImageN("graphics/walkleft.png");
		}
		
		

        //Mais si on dépasse la frame max, il faut revenir à la première
        //Pour connaître la frame max, il suffit de diviser la longueur du spritesheet
        //par la longueur de notre héros : 480 / 40 = 12 frames
        //Puisque la première frame est la numéro 0, la dernière est donc la numéro 11

        if(monstre->frameNumber >= monstre->sprite->w / ENNEMY_WIDTH)
            monstre->frameNumber = 0;

    }
    //Sinon, on décrémente notre timer
    else
        monstre->frameTimer--;

         
    //Ensuite, on peut passer la main à notre fonction
    drawEnnemy(monstre,jeu);


} 

void drawanimatedplayer(hero* he , Gestion * jeu)
{
    /* Gestion du timer */
    // Si notre timer (un compte à rebours en fait) arrive à zéro
if (he->d!=0) {
    if (he->frameTimer <= 0)
    {
        //On le réinitialise
       if ( he->d==-1) he->sprite = loadImageN("graphics/wrr.png");
       else if (he->d==1 ) he->sprite = loadImageN("graphics/wll.png");
       he->frameTimer = 10;
       
        //Et on incrémente notre variable qui compte les frames de 1 pour passer à la suivante

        he->frameNumber++;

        //Mais si on dépasse la frame max, il faut revenir à la première
        //Pour connaître la frame max, il suffit de diviser la longueur du spritesheet
        //par la longueur de notre héros : 480 / 40 = 12 frames
        //Puisque la première frame est la numéro 0, la dernière est donc la numéro 11

        if(he->frameNumber >= he->sprite->w / 55)
           he->frameNumber = 0;

    }
    //Sinon, on décrémente notre timer
    else
       he->frameTimer--;

}
    //Ensuite, on peut passer la main à notre fonction
    drawhero(he,jeu);
}  


void drawanimatedplayer2(hero2* he2 , Gestion * jeu)
{



   /* Gestion du timer */
    // Si notre timer (un compte à rebours en fait) arrive à zéro
if (he2->d!=0) {
    if (he2->frameTimer <= 0)
    {
        //On le réinitialise
       if ( he2->d==-1) he2->sprite = loadImageN1("graphics/wrr2.png");
       else if (he2->d==1 ) he2->sprite = loadImageN1("graphics/wll2.png");
       he2->frameTimer = 10;

        //Et on incrémente notre variable qui compte les frames de 1 pour passer à la suivante

        he2->frameNumber++;

        //Mais si on dépasse la frame max, il faut revenir à la première
        //Pour connaître la frame max, il suffit de diviser la longueur du spritesheet
        //par la longueur de notre héros : 480 / 40 = 12 frames
        //Puisque la première frame est la numéro 0, la dernière est donc la numéro 11

        if(he2->frameNumber >= he2->sprite->w / 55)
           he2->frameNumber = 0;

    }
    //Sinon, on décrémente notre timer
    else
       he2->frameTimer--;

}
    //Ensuite, on peut passer la main à notre fonction
    drawhero2(he2,jeu);
}  




