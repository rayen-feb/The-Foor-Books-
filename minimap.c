#include "minimap.h"

void Init_MiniMap(Minimap*m,Gestion *jeu)
{
	m->back=IMG_Load("graphics/background.png");
	m->Dot=IMG_Load("graphics/Dot.png");
	m->posBlit.x=160;
	m->posBlit.y=400;
	m->posDot.x=jeu->camera.x/10;
	m->posDot.y=jeu->camera.y/10+420;

}

void Update_MiniMap(Minimap *m,Gestion *jeu)
{
	m->posDot.x=jeu->camera.x/10+180;
	m->posDot.y=jeu->camera.y/10+420;
}

void Display_MiniMap(Minimap*m,SDL_Surface*screen)
{
	SDL_BlitSurface(m->back,NULL,screen,&(m->posBlit));
	SDL_BlitSurface(m->Dot,NULL,screen,&(m->posDot));
        SDL_Flip(screen);
}
