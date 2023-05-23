#include "background.h"
//#include "background.h"

/**
 *@file background.c
 */

/*void initBack (background *b)
{
//background
b->imgback=IMG_Load("map.bmp");
b->posback.x=0;
b->posback.y=0;
//camera
b->camera.x=0;
b->camera.y=0;
b->camera.w=SCREEN_W;
b->camera.h=SCREEN_H;
//musique
b->son=Mix_LoadMUS("musique.mp3"); //Chargement de la musique

}
*/

/**
 *@brief initialisation du masque du background.
 *@param b the background
 *@return nothing
 */

void initBackMasque(background *b)
{
	// background
	b->imgback = SDL_LoadBMP("mapMasque.bmp");
	b->posback.x = 0;
	b->posback.y = 0;
	b->posback.w = SCREEN_W / 2;
	b->posback.h = SCREEN_H;

	// camera
	b->camera.x = 0;
	b->camera.y = 0;
	b->camera.w = SCREEN_W / 2;
	b->camera.h = SCREEN_H;
}

void initBack2(background *b)
{
	// background2
	b->imgback = IMG_Load("map.bmp");
	b->posback2.x = SCREEN_W / 2;
	b->posback2.y = 0;
	b->posback2.w = SCREEN_W / 2;
	b->posback2.h = SCREEN_H;
	// camera2
	b->camera2.x = 0;
	b->camera2.y = 0;
	b->camera2.w = SCREEN_W / 2;
	b->camera2.h = SCREEN_H2;
	// musique
	b->son = Mix_LoadMUS("musique.mp3"); // Chargement de la musique
	b->image_flower = IMG_Load("flower.png");
	b->pos_image_flower.x = 500;
	b->pos_image_flower.y = 100;

	b->single_flower.w = 56;
	b->single_flower.h = 107;
	b->single_flower.x = 0;
	b->single_flower.y = 0;

	b->flower_num = 0;
}

/**
 *@brief initialisation du background.
 *@param b the background
 *@return nothing
 */
void initialisation_back(background *b)
{
	// initBack(b);
	initBack2(b);
}

/**
 *@brief affichage du background.
 *@param b the background
 *@param ecran the screen
 *@return nothing
 */
void afficheBack(background b, SDL_Surface *ecran)
{
	/* On blitte par-dessus l'écran */
	Mix_PlayMusic(b.son, -1);
	SDL_BlitSurface(b.imgback, &b.camera, ecran, &b.posback);
}

void afficheBack2(background b, SDL_Surface *ecran)
{
	/* On blitte par-dessus l'écran */
	Mix_PlayMusic(b.son, -1); // Jouer infiniment la musique
	SDL_BlitSurface(b.imgback, &b.camera2, ecran, &b.posback2);
	displayFlower(b, ecran);
}
/*void afficher_back(background b, SDL_Surface *ecran)
{
	afficheBack(b,ecran);
	afficheBack2(b,ecran);

}*/

/**
 *@brief to scroll the background to all direction.
 *@param b the background
 *@param direction the direction
 *@return nothing
 */

void scrolling(background *b, int direction)
{
	const int speed = 1;
	if (direction == 0) // rightbac1
		b->camera.x += 1;
	else if (direction == 1) // leftbac1
		b->camera.x -= 1;
	else if (direction == 2) // rightbac2
		b->camera2.x += 1;
	else if (direction == 3) // leftback2
		b->camera2.x -= 1;
	else if (direction == 4) // upback1
		b->camera.y -= 1;
	else if (direction == 5) // downback1
		b->camera.y += 1;
	else if (direction == 6) // upback2
		b->camera2.y -= 1;
	else if (direction == 7) // downback2
		b->camera2.y += 1;
}

/**
 *@brief to blit the flower on the screen.
 *@param b the background
 *@param ecran the screen
 *@return nothing
 */

void displayFlower(background b, SDL_Surface *ecran)
{

	SDL_BlitSurface(b.image_flower, &(b.single_flower), ecran, &b.pos_image_flower);
}

/**
 *@brief to animate the flower.
 *@param b the background
 *@return nothing
 */

void animerBackground(background *b)
{

	if (b->flower_num >= 0 && b->flower_num < 8)
	{
		b->single_flower.x = b->flower_num * b->single_flower.w;
		b->flower_num++;
	}

	if (b->flower_num == 8)
	{
		b->single_flower.x = b->flower_num * b->single_flower.w;
		b->flower_num = 0;
	}
}
