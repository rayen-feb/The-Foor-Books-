
#include "vie_score.h"
void Init_score(score *s,SDL_Rect pos,int temps)
{
        s->lastTime=0;
        s->currentTime=0;
        s->pause=false;
        s->counter=temps;
        s->position.x=pos.x+600;
        s->position.y=pos.y;

        s->police = TTF_OpenFont("graphics/names.ttf", 50);
        s->couleur.r=255;
        s->couleur.b=255;
        s->couleur.g=255;

        char time[20];
        sprintf(time, "score : %d", s->counter);
        s->texte = TTF_RenderText_Blended(s->police,time,s->couleur);
}

void Display_score(score *s,SDL_Surface *ecran)
{
    SDL_BlitSurface(s->texte,NULL,ecran,&s->position);
    SDL_Flip(ecran);
}




void initialiservie(vie v[4])
{

    v[0].img = loadImageN("graphics/barre_coeur.png");

    v[0].x = 5;
    v[0].y = 5;
    v[1].img = loadImageN("graphics/coeur1.png");

    v[1].x = 3;
    v[1].y = 3;
    v[2].img = loadImageN("graphics/coeur2.png");

    v[2].x = 48;
    v[2].y = 3;
    v[3].img = loadImageN("graphics/coeur3.png");

    v[3].x = 93;
    v[3].y = 3;
}





void initialiserobject(object o[5] )
{
 
    o[0].imo = loadImageN("graphics/coeur.png");
    o[0].x = 800;
    o[0].y = 270;
    o[1].imo = loadImageN("graphics/coeur.png");
    o[1].x = 1600;
    o[1].y = 270;
    o[2].imo = loadImageN("graphics/coeur.png");
    o[2].x = 2000;
    o[2].y = 270;
    o[3].imo = loadImageN("graphics/coeur.png");
    o[3].x = 1800;
    o[3].y = 270;
    o[4].imo = loadImageN("graphics/coeur.png");
    o[4].x = 1400;
    o[4].y = 270;
    
}

SDL_Surface*  draw_vie (SDL_Surface* screen,  vie v[4] , int hvie )
{
   int i =0 ;
   screen=drawImage(v[0].img,screen,v[0].x, v[0].y ) ;
   for(i=1;i<4;i++)
{ 
     if(i<=hvie) { screen=drawImage(v[i].img,screen,v[i].x, v[i].y ) ;}
}
    return screen;
}
void  draw_object (Gestion * jeu,  object o[5] )
{
   int i =0 ;
   for(i=0;i<5;i++)
{ 
      jeu->screen=drawImage(o[i].imo,jeu->screen,o[i].x - jeu->camera.x, o[i].y - jeu->camera.y) ;
}
   
}








int Collision_bounding_box(hero *o1, object o2[5],int i,SDL_Rect camera) 
{
int l1 = o1->x+camera.x; //left
int r1 = o1->x+55+camera.x; //right
int t1 = o1->y; //top
int b1 = o1->y+96; //bottom
int l2 = o2[i].x;
int r2 = o2[i].x + o2[i].imo->w;
int t2 = o2[i].y;
int b2 = o2[i].y + o2[i].imo->h;
if (l1 > r2 || l2 > r1 || t1 > b2 || t2 > b1) {
     return 0;	//no intersectoin
 }
 else {
     return 1;	//intersection
 }
}
int Collision_bounding_box2(hero *o1, Monstre monstre ,SDL_Rect camera)
{

int l1 = o1->x ; //left
int r1 = o1->x+60 ; //right
int t1 = o1->y; //top
int b1 = o1->y+60; //bottom
int l2 = monstre.x;
int r2 = monstre.x + 60;
int t2 = monstre.y;
int b2 = monstre.y +60;
if (l1 > r2 || l2 > r1 || t1 > b2 || t2 > b1) {
     return 0;	//no intersectoin
 }
 else {
     return 1;	//intersection
 }
}

/*
int collision_trigometrie(hero *o1,object *o2)
{
int h=0;

  int dx=o1->x - o2->x;
  int dy=o2->y - o2->y;

float distance = sqrt(dx * dx + dy * dy);  // ma7abich y'accepti sqrt 

if (distance < o1->sprite->w + o2->imo->ww) {
   h=1;} // collision detected!
return h;
}
*/


void dovie(hero *he, object o[5],vie v[4],SDL_Rect camera,Monstre monstre)
{
int j;
int h=0;
int x=0;
for(j=0;j<5;j++)
{

 h=Collision_bounding_box(he,o,j,camera);
 if(h==1)
         {
              if(he->hvie < 3)
               { o[j].x = -20;
                 o[j].y = -20;  
                     
                     // appel fonction pour supprimer objet (coeur) 
              he->hvie++;

                }

           }
x=Collision_bounding_box2(he,monstre,camera);
if(x==1) if(he->hvie > 0) he->hvie--;
}
}


/*void doscore(hero *he,coin *cn)
{
int p=Collision_bounding_box(&he,&cn);
if(p==1)
        {
           coin=NULL;
           he->hscore++;
           //affichager du score ttf
        }
}

/*void dotime(hero *he)
{
   if((he->y==5000)&&(time<2minutes)) //5000 pos du  fin du map
//il passe stage suivant
   else
//rejoue le stage 
} 
*/

