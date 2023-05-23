#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include "main.h"

void Init_Xo(Xo *xo)
{
    xo->xoS=IMG_Load("graphics/ltrs.png");

    xo->xoR[1][1].x=19;
    xo->xoR[1][1].y=20;
    xo->xoR[1][2].x=116;
    xo->xoR[1][2].y=20;
    xo->xoR[1][3].x=214;
    xo->xoR[1][3].y=20;

    xo->xoR[2][1].x=19;
    xo->xoR[2][1].y=117;
    xo->xoR[2][2].x=116;
    xo->xoR[2][2].y=117;
    xo->xoR[2][3].x=214;
    xo->xoR[2][3].y=117;

    xo->xoR[3][1].x=19;
    xo->xoR[3][1].y=213;
    xo->xoR[3][2].x=116;
    xo->xoR[3][2].y=213;
    xo->xoR[3][3].x=214;
    xo->xoR[3][3].y=213;

    xo->posxo[1].x=0;
    xo->posxo[1].y=0;
    xo->posxo[1].w=64;
    xo->posxo[1].h=67;

    xo->posxo[2].x=67;
    xo->posxo[2].y=0;
    xo->posxo[2].w=64;
    xo->posxo[2].h=67;

    for(int i=1;i<4;i++)
    {
        for(int j=1;j<4;j++)
        {
            xo->tab[i][j]=0;
        }
    }
    
    xo->tour=1;
    xo->winner=0;   
}

void Random_Xo(Xo *xo)
{
    int x,y;
 //   srand(time(NULL));
    do{
        do{
            x=rand()%4;
        }while(x==0);

        do{
            y=rand()%4;
        }while(y==0);

        Put_Xo(xo,x,y);
        printf("%d,%d\n",x,y);
    }while(xo->tab[x][y]==0);

}

void Put_Xo(Xo* xo,int x,int y)
{
    if(xo->tour==1)
    {
        if(xo->tab[x][y]==0)
        {
           xo->tab[x][y]=1;
           xo->tour=2;
        }
    }
    else
    {
        if(xo->tab[x][y]==0)
        {
           xo->tab[x][y]=2; 
           xo->tour=1;
        }
    }
}


void Diplay_Xo(Xo* xo,SDL_Surface* screen )
{
    for(int i=1;i<4;i++)
    {
        for(int j=1;j<4;j++)
        {
            if(xo->tab[i][j]==1){
               SDL_BlitSurface(xo->xoS,&xo->posxo[1],screen,&xo->xoR[i][j]); 
            }
            else if (xo->tab[i][j]==2){
                SDL_BlitSurface(xo->xoS,&xo->posxo[2],screen,&xo->xoR[i][j]);
            }   
        }
    }
    SDL_Flip(screen);
}



int Checkwin_Xo(Xo *xo)
{
    int j=1;
    int total=0;
    int verif=0;
    while(j<4){
    for(int i=1;i<4;i++)
    {
        if(xo->tab[i][j]==1)
        {
            total--;
        }
        else if(xo->tab[i][j]==2)
        {
            total++;
        }
        if(i==3){
            if(total==-3){
                xo->winner=1;
                return 1;
            }
            else if(total==3){
                xo->winner=2;
                return 1;
            }
        }
        
    }
    total=0;
    j++;
    }

    j=1;
    while(j<4){
    for(int i=1;i<4;i++)
    {
        if(xo->tab[j][i]==1)
        {
            total--;
        }
        else if(xo->tab[j][i]==2)
        {
            total++;
        }
        if(i==3){
            if(total==-3){
                xo->winner=1;
                return 1;
            }
            else if(total==3){
                xo->winner=2;
                return 1;
            }
        }
        
    }
    total=0;
    j++;
    }
    
    for(int i=1;i<4;i++)
    {
        if(xo->tab[i][i]==1)
        {
            total--;
        }
        else if(xo->tab[i][i]==2)
        {
            total++;
        }
    }

    if(total==-3){
        xo->winner=1;
        return 1;
    }
    else if(total==3){
        xo->winner=2;
        return 1;
    }

    total=0;
    for(int i=1;i<4;i++)
    {
        if(xo->tab[i][4-i]==1)
        {
            total--;
        }
        else if(xo->tab[i][4-i]==2)
        {
            total++;
        }
    }

    if(total==-3){
        xo->winner=1;
        return 1;
    }
    else if(total==3){
        xo->winner=2;
        return 1;
    }
    

    for(int i=1;i<4;i++)
    {
        for(int j=1;j<4;j++)
        {
            if(xo->tab[i][j]!=0)
            {
                verif++;
            }
        }
    }
    if(verif==9){
        return 1;
    }
    else{
        return 0;
    }

}

void Free_Xo(Xo *xo)
{
    SDL_FreeSurface(xo->xoS);
}

void Play_Xo(SDL_Surface *screen)
{
    Xo xo;
    Init_Xo(&xo);
    SDL_Surface *back=IMG_Load("graphics/table.png");
    SDL_Event event;
    int gameover=0;
    while(gameover==0)
    {
        SDL_BlitSurface(back,NULL,screen,NULL);
        Diplay_Xo(&xo,screen);
        SDL_Flip(screen);
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            { 
                case SDL_MOUSEMOTION:
                {
                    printf("Souris en position %d %d\n",event.motion.x, event.motion.y);
                }
                case SDL_MOUSEBUTTONUP:
                {

                    if((event.motion.x>19 && event.motion.x<106)&&(event.motion.y>20 && event.motion.y<115))
                    {
                        if(event.button.button == SDL_BUTTON_LEFT)
                        {
                            printf("%d,%d\n",1,1);
                            Put_Xo(&xo,1,1);
                        }
                    }
                    else if((event.motion.x>116 && event.motion.x<202)&&(event.motion.y>20 && event.motion.y<115))
                    {
                        if(event.button.button == SDL_BUTTON_LEFT)
                        {
                            printf("%d\n",2);
                            Put_Xo(&xo,1,2);
                        }
                    }
                    else if((event.motion.x>214 && event.motion.x<297)&&(event.motion.y>20 && event.motion.y<115))
                    {
                        if(event.button.button == SDL_BUTTON_LEFT)
                        {
                            printf("%d\n",3);
                            Put_Xo(&xo,1,3);
                        }
                    }/****/
                    else if((event.motion.x>19 && event.motion.x<106)&&(event.motion.y>117 && event.motion.y<210))
                    {
                        if(event.button.button == SDL_BUTTON_LEFT)
                        {
                            printf("%d\n",4);
                            Put_Xo(&xo,2,1);
                        }
                    }
                    else if((event.motion.x>116 && event.motion.x<202)&&(event.motion.y>117 && event.motion.y<210))
                    {
                        if(event.button.button == SDL_BUTTON_LEFT)
                        {
                            printf("%d\n",5);
                            Put_Xo(&xo,2,2);
                        }
                    }
                    else if((event.motion.x>214 && event.motion.x<297)&&(event.motion.y>117 && event.motion.y<210))
                    {
                        if(event.button.button == SDL_BUTTON_LEFT)
                        {
                            printf("%d\n",6);
                            Put_Xo(&xo,2,3);
                        }
                    }/****/
                    else if((event.motion.x>19 && event.motion.x<106)&&(event.motion.y>213 && event.motion.y<302))
                    {
                        if(event.button.button == SDL_BUTTON_LEFT)
                        {
                            printf("%d\n",7);
                            Put_Xo(&xo,3,1);
                        }
                    }
                    else if((event.motion.x>116 && event.motion.x<202)&&(event.motion.y>213 && event.motion.y<302))
                    {
                        if(event.button.button == SDL_BUTTON_LEFT)
                        {
                            printf("%d\n",8);
                            Put_Xo(&xo,3,2);
                        }
                    }
                    else if((event.motion.x>214 && event.motion.x<297)&&(event.motion.y>213 && event.motion.y<302))
                    {
                        if(event.button.button == SDL_BUTTON_LEFT)
                        {
                            printf("%d\n",9);
                            Put_Xo(&xo,3,3);
                        }
                    }
                    break;
                }
                case SDL_QUIT:
                {
                    gameover=1;
                    break;
                }

            }
        }
        if(xo.tour==2){
            Random_Xo(&xo);
        }
        gameover=Checkwin_Xo(&xo);
    }
    Diplay_Xo(&xo,screen);
    SDL_Delay(2000);
    SDL_Flip(screen);
    if((xo.winner==1)|| (xo.winner==2)) {  SDL_FreeSurface(back);
          Free_Xo(&xo);}

      
       /* printf("player 1 win\n");

    	SDL_FreeSurface(back);
          Free_Xo(&xo);
	return true;
    }
    else if(xo.winner==2){
        printf("player 2 win\n");
	Free_Xo(&xo);
    	SDL_FreeSurface(back);
	return false;
    }
    else{
	Free_Xo(&xo);
    	SDL_FreeSurface(back);
	return false;
        printf("draw\n");
    }*/
    
}




