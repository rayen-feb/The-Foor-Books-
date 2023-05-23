#include <SDL/SDL_ttf.h>
#include "menu.h"
#include "instruction.h"
#include "options.h"
#include "quit.h"
#include "sound.h"
#include "logo.h"

void menu (int *menuout   )
{  
 animation_logo(); //animation_du_logo_au_debut(fait appel a la fonction logo)// 
    int i,frame=0 ; 
   SDL_WM_SetIcon(IMG_Load("graphics/icon.png"), NULL);

  SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO|SDL_INIT_TIMER);
    SDL_Surface *screen=NULL;
   TTF_Init();
    TTF_Font*  font = NULL;
   font = TTF_OpenFont("times.ttf", 12);
    SDL_Surface *background1=NULL,*light,*background,*image;

   Mix_Music *music ; 
   Mix_Chunk *mus;
    buttons b;
    screen=SDL_SetVideoMode (1200,800,32,SDL_HWSURFACE|SDL_DOUBLEBUF|SDL_RESIZABLE);
    SDL_WM_SetCaption("THE FOUR BOOKS ",NULL);//titre de la fenetre
    SDL_WarpMouse(screen->w / 2, screen->h / 2);
    SDL_EnableKeyRepeat(100,100);
    SDL_Rect background_pos;

    SDL_Rect  pxhigh, pxy,pxin,pxset,pxexit;
    SDL_Event event;
    background_pos.x=0;
    background_pos.y=0;
    SDL_Rect  rect,ligh ;
   ligh.x=550;
   ligh.y=100;
    rect.x=100;
    rect.y=1090;
    pxy.x=20;
    pxy.y=200;
    pxin.x=20;
    pxin.y=320;
    pxset.x=20;
    pxset.y=440;
    pxexit.x=20;
    pxexit.y=680;
    pxhigh.x=20;
    pxhigh.y=560;
   const int FPS=1;
    int pp=2,op=0,ex=0,ins=0,t,hg=0;
    int done=1;
    int motion=330;
    b.play[0]=IMG_Load("resources_menu/start.png");
    b.play[1]=IMG_Load("resources_menu/start1.png");
    b.play[2]=IMG_Load("resources_menu/start2.png");
    b.highscore[0]=IMG_Load("resources_menu/hight1.png");
    b.highscore[1]=IMG_Load("resources_menu/hight2.png");
    b.highscore[2]=IMG_Load("resources_menu/hight3.png");

    b.instructions[0]=IMG_Load("resources_menu/credits.png");
    b.instructions[1]=IMG_Load("resources_menu/credits1.png");
    b.instructions[2]=IMG_Load("resources_menu/credits2.png");
    b.setting[0]=IMG_Load("resources_menu/settings.png");
    b.setting[1]=IMG_Load("resources_menu/settings1.png");
    b.setting[2]=IMG_Load("resources_menu/settings2.png");
    b.exit[0]=IMG_Load("resources_menu/exit.png");
    b.exit[1]=IMG_Load("resources_menu/exit1.png");
    b.exit[2]=IMG_Load("resources_menu/exit2.png");
    light= IMG_Load("resources_menu/light.png");
    initialiser_audio(music);
    initialiser_audiobref(mus);


while (done!=0)    {
       // animation_logo();
	//affichage de background
        background=IMG_Load("resources_menu/background.png");
        SDL_BlitSurface(background,NULL,screen,NULL);                
        SDL_BlitSurface(b.play[pp],NULL,screen,&pxy);
        SDL_BlitSurface(b.highscore[hg],NULL,screen,&pxhigh);
        SDL_BlitSurface(b.instructions[ins],NULL,screen,&pxin);
        SDL_BlitSurface(b.setting[op],NULL,screen,&pxset);
        SDL_BlitSurface(b.exit[ex],NULL,screen,&pxexit);
        SDL_Flip(screen);

        t=0;
        if (SDL_PollEvent(&event))
        {
            switch(event.type)
            {
            case SDL_QUIT :
                    cleanmenu(background);                 
                    done=0;
                break;
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {
                case SDLK_ESCAPE:
                   if (quit(screen)==1)
                        done=0;
                      
                    break;
                case SDLK_UP:
                    if (pp==1 && t==0)
                    {  initialiser_audiobref(mus);
                        ex=1;
                        pp=0;
                        op=0;
                        ins=0;
                        t=1;
                       hg=0;
                    }
                    else if(ins==1 && t==0)
                    {initialiser_audiobref(mus);
                        pp=1;
                        op=0;
                        ex=0;
                        ins=0;
                        t=1;
                    }
                    else if (op==1 && t==0)
                    {initialiser_audiobref(mus);
                        ins=1;
                        ex=0;
                        pp=0;
                        op=0;
                        t=1;
                    }
                    else if (ex==1 && t==0)
                    {initialiser_audiobref(mus);
                       hg=1;
                        op=0;
                        ex=0;
                        pp=0;
                        ins=0;
                        t=1;
                    }
                      else if (hg==1 && t==0)
                    {initialiser_audiobref(mus);
                       hg=0;
                        op=1;
                        ex=0;
                        pp=0;
                        ins=0;
                        t=1;
                    }

                    break;
                case SDLK_DOWN:
                    if (pp==1 && t==0)
                    {initialiser_audiobref(mus);
                        ins=1;
                        ex=0;
                        op=0;
                        pp=0;
                        t=1;
                        hg=0;
                    }
                    else if(ins==1 && t==0)
                    {initialiser_audiobref(mus);
                        pp=0;
                        op=1;
                        ex=0;
                        ins=0;
                        t=1;
                       hg=0;
                    }
                    else if (op==1 && t==0)
                    {initialiser_audiobref(mus);
                        ex=0;
                       hg=1;
                        pp=0;
                        ins=0;
                        op=0;
                        t=1;
                    }
                  else if (hg==1 && t==0)
                    {initialiser_audiobref(mus);
                        ex=1;
                       hg=0;
                        pp=0;
                        ins=0;
                        op=0;
                        t=1;
                    }

                    else if (ex==1 && t==0)
                    {initialiser_audiobref(mus);
                        pp=1;
                        hg=0;
                        op=0;
                        ins=0;
                        ex=0;
                        t=1;
                    }
                     else if (op==1 && t==0)
                    {initialiser_audiobref(mus);
                        pp=0;
                        hg=0;
                        op=0;
                        ins=0;
                        ex=1;
                        t=1;
                    }

                    break;
                case SDLK_RETURN:
                    if (pp==1)
                    {
                        SDL_BlitSurface(b.play[2],NULL,screen,&pxy);
                        initialiser_audiobref(mus);
                        SDL_Flip(screen);
                        SDL_Delay(400);
                        done=0;
                       
                        menuout=0;
                        //return NEW_GAME;
                    }
                    else if (ins==1)
                    {   
			initialiser_audiobref(mus);
                        SDL_BlitSurface(b.instructions[2],NULL,screen,&pxin);
                        SDL_Flip(screen);
                        instructions(screen);
                        ins=0;
                        SDL_Delay(400);

                        //return OPTION;
                    }
                    else if (hg==1)
                    {
			initialiser_audiobref(mus);
                        SDL_BlitSurface(b.highscore[2],NULL,screen,&pxhigh);
                        SDL_Flip(screen);
                        SDL_Delay(400);
                       // hg(screen);
                    }
                    else if (op==1)
                    {
                        initialiser_audiobref(mus);
                        SDL_BlitSurface(b.setting[2],NULL,screen,&pxset);
                        SDL_Flip(screen);
                        SDL_Delay(400);
                        option(screen);
                    }

                    else if (ex==1)
                    {

                        initialiser_audiobref(mus);
                        SDL_BlitSurface(b.exit[2],NULL,screen,&pxexit);
                        SDL_Flip(screen);
                         quit(screen);
                       // Display_Save(&s,screen);
                      cleanmenu(background);
                            done=0;
                        SDL_Delay(500);
                    }
                    break;
                }
                break;
            case SDL_MOUSEMOTION:
                ex=0;
                pp=0;
                op=0;
                t=0;
                hg=0;
		 if ((event.motion.x>20)&&(event.motion.y>240)&&(event.motion.x<420)&&(event.motion.y<340) && (t==0) && (hg==0))
              {      pp=0;
                    ex=0;
                    ins=0;
                    op=0;
                    t=1;
                    hg=1;

                      
                }
	
                if ((event.motion.x>20)&&(event.motion.y>200)&&(event.motion.x<420)&&(event.motion.y<300) && (t==0) && (pp==0))
                {  
                    pp=1;
                    ex=0;
                    ins=0;
                    op=0;
                    t=1;
                    hg=0;
                }
                else if ((event.motion.x>20)&&(event.motion.y>320)&&(event.motion.x<420)&&(event.motion.y<420) &&(t==0)&& (ins==0))
                {
                    hg=0;
                    ex=0;
                    pp=0;
                    ins=1;
                    op=0;
                    t=1;
                }
                else if ((event.motion.x>20)&&(event.motion.y>440)&&(event.motion.x<420)&&(event.motion.y<540)&&(t==0)&& (op==0))
                {   hg=0;
                    ex=0;
                    pp=0;
                    ins=0;
                    op=1;
                    t=1;
                }
                 else if ((event.motion.x>20)&&(event.motion.y>560)&&(event.motion.x<420)&&(event.motion.y<660)&&(t==0)&& (hg==0))
                {   hg=1;
                    ex=0;
                    pp=0;
                    ins=0;
                    op=0;
                    t=1;
                }

                else if ((event.motion.x>20)&&(event.motion.y>680)&&(event.motion.x<420)&&(event.motion.y<780)&&(t==0)&& (ex==0))
                {   hg=0;
                    ex=1;
                    pp=0;
                    ins=0;
                    op=0;
                    t=1;
                }
                break;
            case SDL_MOUSEBUTTONDOWN:
                if (event.button.button==SDL_BUTTON_LEFT)
                {
                    if ((event.motion.x>20)&&(event.motion.y>200)&&(event.motion.x<420)&&(event.motion.y<300) &&(pp==1))
                    {   initialiser_audiobref(mus);
                        pp=1;
                        SDL_Delay (200);
                        //play(screen);
                        //return NEW_GAME;
                    }
                    else if ((event.motion.x>20)&&(event.motion.y>320)&&(event.motion.x<420)&&(event.motion.y<420) &&(ins==1))
                    {	  initialiser_audiobref(mus);

                        SDL_BlitSurface(b.instructions[2],NULL,screen,&pxin);
                        SDL_Flip(screen);
                        instructions(screen);
                        ins=1;
                        SDL_Delay (200);
                       // return OPTION;
                    }
			 else if ((event.motion.x>20)&&(event.motion.y>440)&&(event.motion.x<420)&&(event.motion.y<540)&&(op==1))
                    { 

                        SDL_BlitSurface(b.setting[3],NULL,screen,&pxset);
                         initialiser_audiobref(mus);
                        op=2;
                        option(screen);
                        SDL_Delay (200);
                       // return OPTION;
                    }

                    else if ((event.motion.x>20)&&(event.motion.y>560)&&(event.motion.x<420)&&(event.motion.y<660)&&(hg==1))
                    {   initialiser_audiobref(mus);
			   SDL_BlitSurface(b.highscore[3],NULL,screen,&pxhigh);
                        hg=2;

                        SDL_Delay (200);
                       // return OPTION;
                    }
                    else if (ex==1)
                    {	

                           initialiser_audiobref(mus);
                        SDL_BlitSurface(b.exit[2],NULL,screen,&pxexit);
                        SDL_Flip(screen);
                        SDL_Delay (200);
                        quit(screen);
                        if (quit(screen)==1)
                            done=0;
                    }
                }
                break;
            }
        }
    }
/*cleanmenu(background);*/    }
/**
* @brief To clean the background b .
* @param b the buttons 
* @param url the url of the image
* @return Nothing
*/
void cleanmenu(SDL_Surface *background)
{    buttons b;
    SDL_FreeSurface(b.play[0]);
    SDL_FreeSurface(b.setting[0]);
    SDL_FreeSurface(b.exit[0]);
    SDL_FreeSurface(b.highscore[0]);
    SDL_FreeSurface(b.instructions[0]);
   SDL_FreeSurface(b.play[1]);
    SDL_FreeSurface(b.setting[1]);
    SDL_FreeSurface(b.exit[1]);
    SDL_FreeSurface(b.highscore[1]);
    SDL_FreeSurface(b.instructions[1]);
 SDL_FreeSurface(b.play[2]);
    SDL_FreeSurface(b.setting[2]);
    SDL_FreeSurface(b.exit[2]);
    SDL_FreeSurface(b.highscore[2]);
    SDL_FreeSurface(b.instructions[2]);

}


