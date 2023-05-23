#include"chrono.h"

void Init_Chrono(Chrono *c,SDL_Rect pos,int temps)
{
	c->lastTime=0;
	c->currentTime=0;
	c->pause=false;
	c->counter=temps;
	c->position.x=pos.x+300;
	c->position.y=pos.y;

	c->police = TTF_OpenFont("graphics/names.ttf", 50);
	c->couleur.r=255;
	c->couleur.b=255;
	c->couleur.g=255;

	char time[20];
	sprintf(time, "Time : %d", c->counter);
	c->texte = TTF_RenderText_Blended(c->police,time,c->couleur);
}

void Display_Chrono(Chrono *c,SDL_Surface *ecran)
{
    SDL_BlitSurface(c->texte,NULL,ecran,&c->position);
    SDL_Flip(ecran);
}

bool Calcul_Chrono(Chrono *c)
{
	c->currentTime = SDL_GetTicks();
    if (c->currentTime - c->lastTime >= 1000) /* Si 100ms au moins se sont écoulées */
   	{
        c->counter -= 1; /* On rajoute 100ms au compteur */
     	char time[20];
		sprintf(time, "	Time  : %d", c->counter);
		SDL_FreeSurface(c->texte); /* On supprime la surface précédente de la mémoire avant d'en charger une nouvelle (IMPORTANT) */
    	c->texte = TTF_RenderText_Blended(c->police,time,c->couleur);

        c->lastTime = c->currentTime; /* On met à jour le tempsPrecedent */
		if(c->counter == 0)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	return true;
}

bool Calcul_ChronoE(Chrono *c,SDL_Surface *screen)
{
	c->currentTime = SDL_GetTicks();
    if (c->currentTime - c->lastTime >= 1000) /* Si 100ms au moins se sont écoulées */
   	{
        c->counter -= 1; /* On rajoute 100ms au compteur */
     	char time[20];
		sprintf(time, "Time : %d", c->counter);
		SDL_FreeSurface(c->texte); /* On supprime la surface précédente de la mémoire avant d'en charger une nouvelle (IMPORTANT) */
    	c->texte = TTF_RenderText_Blended(c->police,time,c->couleur);

        c->lastTime = c->currentTime; /* On met à jour le tempsPrecedent */
		if(c->counter == 0)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	return true;
}



void Pause_Chrono(Chrono *c)
{
	if(!c->pause)
	{
		c->pause=true;
	}
	else
	{
		c->pause=false;
	}
}
