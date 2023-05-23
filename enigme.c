#include"resource_enigme/enigme.h"



int  enigme(SDL_Surface *screen,int* e1,int* e2,int* e3,int* e4,int* e5,int* e6,int* e7,int* e8,int rep, int *b)
{
    int r=0,A=0;
    FILE* fichier=NULL;
    FILE* fichierr=NULL;
  do {
    srand(time(NULL));
   r=rand()%12+1;
     //printf("%d ",r);
  } while(r==(*e1)||r==(*e2)||r==(*e3)||r==(*e4)||r==(*e5)||r==(*e6)||r==(*e7)||r==(*e8));
  if (rep==1) (*e1)=r;
   if (rep==2) (*e2)=r;
    if (rep==3) (*e3)=r;
    if (rep==4) (*e4)=r;
    if (rep==5) (*e5)=r;
    if (rep==6) (*e6)=r;
    if (rep==7) (*e7)=r;
    if (rep==8) (*e8)=r;
    char chaine[256]="";
    char chainer[256]="";
    fichier=fopen("resource_enigme/question.txt", "r");
    fichierr=fopen("resource_enigme/reponse.txt", "r");
int i =0;
while (fgets (chaine, 600, fichier ) != NULL && fgets (chainer, 256, fichierr ) !=NULL)
{
  i++;
  if (i==r) {
break;
  }
}

    SDL_Surface  *texte = NULL, *fond = NULL, *rp =NULL;
    SDL_Rect position;
    SDL_Event event;
    TTF_Font *police = NULL, *police1 = NULL;
    SDL_Color couleurNoire = {0,0,0};
    int continuer = 1;
  //  SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();

    fond = IMG_Load("graphics/back.png");
    police = TTF_OpenFont("resource_enigme/graphic/font.ttf", 25);
    police1 = TTF_OpenFont("resource_enigme/graphic/font.ttf", 30);
    texte = TTF_RenderText_Blended(police,chaine, couleurNoire);
    rp = TTF_RenderText_Blended(police1,chainer, couleurNoire);


    while (continuer)
    {
        position.x = 0;
        position.y = 0;
          SDL_BlitSurface(fond, NULL, screen, &position);

        position.x = 10;
        position.y = 200;
        SDL_BlitSurface(texte, NULL, screen, &position);

        position.x = 10;
        position.y = 370;
        SDL_BlitSurface(rp, NULL, screen, &position);

        SDL_Flip(screen);
      SDL_WaitEvent(&event);

        switch(event.type)
        {
            case SDL_QUIT:
            *b=0;
                continuer = 0;
                break;
                case SDL_KEYDOWN:
            			switch (event.key.keysym.sym)
        {

            				case SDLK_KP1:
                  if (r==1||r==4||r==7||r==10)  A=1 ; continuer=0;
break;

  case SDLK_KP2:
               if (r==2||r==5||r==8||r==11) A=1; continuer=0;
break;

	case SDLK_KP3:
               if (r==3||r==6||r==9||r==12) A=1; continuer=0;
break;
}
       }

   }

    TTF_CloseFont(police);
    TTF_Quit();
    SDL_FreeSurface(texte);
return A;
}




/*int enigme (SDL_Surface *screen)
{
int A, B, C;
  double D,x,x1,r1,r2;
      char chaine[256]="";
      char chainer[256]="";
      char chainerr[256]="";
      char chainerrr[256]="";
      char chainerrrr[256]="";
      SDL_Surface  *texte = NULL, *fond = NULL, *rp =NULL ,*rp1 =NULL,*rp2 =NULL,*rp3 =NULL;
      SDL_Rect position;
      SDL_Event event;
      TTF_Font *police = NULL, *police1 = NULL;
      SDL_Color couleurNoire = {0,0,0};
      srand(time(NULL));
      int continuer = 1;
      TTF_Init();
      fond = IMG_Load("graphic/back.jpg");

      police = TTF_OpenFont("graphic/font.ttf", 20);
      police1 = TTF_OpenFont("graphic/font.ttf", 25);
      A=rand()%90+1;
      B=rand()%100+1;
      C=rand()%30+1;
      r1=rand()%30+1;
      r2=rand()%30+1;
      sprintf(chaine,"%d x² + %d x +%d",A,B,C);
      sprintf(chainerrr,"%.4f",r1);
      sprintf(chainerrrr,"%.4f",r2);
  // Calcul des solutions réelles d'une équation du second degré
  // Calcul du discriminant b²-4ac
  D = pow(B,2) - 4.0*A*C;
  // Distinction des différents cas
  if (A==0 && B==0 && C==0) {
  // 0x = 0
  		printf("Tout réel est une solution de cette équation.\n");
      sprintf(chainer,"%s","pas de solutions");
    }
  else if (A==0 && B==0) {
   // Contradiction: c # 0 et c = 0
  		printf("Cette équation ne possède pas de solutions.\n");
      sprintf(chainer,"%s","pas de solutions");
}
  else if (A==0) // bx + c = 0
     {
      printf("La solution de cette équation du premier degré est :\n");
      printf(" x = %.4f\n", (double)C/B);
      x=(double)C/B;
      sprintf(chainer,"%.4f",x);
     }
  else if (D<0)  // b^2-4ac < 0
      printf("Cette équation n'a pas de solutions réelles.\n");
  else if (D==0) // b^2-4ac = 0
     {
      printf("Cette équation a une seule solution réelle :\n");
      printf(" x =  %.4f\n", (double)-B/(2*A));
      x=(double)-B/(2*A);
      sprintf(chainer,"%.4f",x);
     }
  else // b^2-4ac > 0
     {
      printf("Les solutions réelles de cette équation sont :\n");
      printf(" x1 = %.4f\n", (-B+sqrt(D))/(2*A));
      printf(" x2 = %.4f\n", (-B-sqrt(D))/(2*A));
      x=(-B+sqrt(D))/(2*A);
      x1= (-B-sqrt(D))/(2*A);
      sprintf(chainer,"%.4f",x);
      sprintf(chainerr,"%.4f",x1);

    //  strcat sprintf
     }

      texte = TTF_RenderText_Blended(police,chaine, couleurNoire);
      rp = TTF_RenderText_Blended(police1,chainer, couleurNoire);
      rp1 = TTF_RenderText_Blended(police1,chainerr, couleurNoire);
      rp2 = TTF_RenderText_Blended(police1,chainerrr, couleurNoire);
      rp3 = TTF_RenderText_Blended(police1,chainerrrr, couleurNoire);

      while (continuer)
      {
          position.x = 0;
          position.y = 0;
          SDL_BlitSurface(fond, NULL, screen, &position);
          position.x = 190;
          position.y = 252;
          SDL_BlitSurface(texte, NULL, screen, &position);
          position.x = 217;
          position.y = 370;
          SDL_BlitSurface(rp, NULL, screen, &position);
          position.x = 217;
          position.y = 385;
          SDL_BlitSurface(rp1, NULL, screen, &position);
          position.x = 321;
          position.y = 370;
          SDL_BlitSurface(rp2, NULL, screen, &position);
          position.x = 448;
          position.y = 370;
          SDL_BlitSurface(rp3, NULL, screen, &position);
          SDL_Flip(screen);
          SDL_WaitEvent(&event);
          switch(event.type)
          {
              case SDL_QUIT:
                  continuer = 0;
                  break;
                  case SDL_MOUSEBUTTONDOWN :
                  if( (event.button.x>216 && event.button.x<288 && event.button.y>374 && event.button.y<391) )
               {A= 1 ; continuer = 0;return A; break;}
               else if ( (event.button.x>321 && event.button.x<394 && event.button.y>374 && event.button.y<391) )
               {A = 0 ; continuer = 0; return A;break;}
               else if ( (event.button.x>448 && event.button.x<533 && event.button.y>374 && event.button.y<393) )
               {A = 0 ; continuer = 0 ;return A;break;}
          }
          SDL_Flip(screen);
      }
      TTF_CloseFont(police);
      TTF_Quit();
      SDL_FreeSurface(texte);
}

*/
