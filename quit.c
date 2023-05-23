#include "quit.h"



int quit(SDL_Surface *screen)
{
    SDL_Surface *background=NULL;
    quitter q;
    int done=1;
    int n=2,t=0;
    SDL_Rect pos,posyes,posno;
    SDL_Event event;
    pos.x=130;
    pos.y=200;

    posyes.x=140;
    posyes.y=450;

    posno.x=630;
    posno.y=450;
    background=IMG_Load("resources_menu/menu1.png");
    q.exit[6]=IMG_Load("resources_menu/exit4.png");
    q.exit[0]=IMG_Load("resources_menu/yes.png");
    q.exit[1]=IMG_Load("resources_menu/no.png");
    q.exit[2]=IMG_Load("resources_menu/yes1.png");
    q.exit[3]=IMG_Load("resources_menu/no1.png");
    q.exit[4]=IMG_Load("resources_menu/yes2.png");
    q.exit[5]=IMG_Load("resources_menu/no2.png");
    while(done!=0)
    {
        SDL_BlitSurface(background,NULL,screen,NULL);
        if (n==2)
        {
            SDL_BlitSurface(q.exit[6],NULL,screen,&pos);
            SDL_BlitSurface(q.exit[n],NULL,screen,&posyes);
            SDL_BlitSurface(q.exit[1],NULL,screen,&posno);
            SDL_Flip(screen);
        }
        else if (n==3)
        {
            SDL_BlitSurface(q.exit[6],NULL,screen,&pos);
            SDL_BlitSurface(q.exit[n],NULL,screen,&posno);
            SDL_BlitSurface(q.exit[0],NULL,screen,&posyes);
            SDL_Flip(screen);
        }
        else
        {
            SDL_BlitSurface(q.exit[6],NULL,screen,&pos);
            SDL_BlitSurface(q.exit[0],NULL,screen,&posyes);
            SDL_BlitSurface(q.exit[1],NULL,screen,&posno);
            SDL_Flip(screen);
        }
        SDL_WaitEvent(&event);
        t=0;
        switch(event.type)
        {
        case SDL_KEYDOWN:
            switch(event.key.keysym.sym)
            {
            case SDLK_ESCAPE:
                done=0;
                break;
            case SDLK_LEFT:

                if (n==2 && t==0)
                {
                    n++;
                    t=1;
                }
                else if (n==3 && t==0)
                {
                    n--;
                    t=1;
                }
                break;
            case SDLK_RIGHT:
                if (n==2 && t==0)
                {
                    n++;
                    t=1;
                }
                else if (n==3 && t==0)
                {
                    n--;
                    t=1;
                }
                break;
            case SDLK_RETURN:
                if (n==2)
                {
                    SDL_BlitSurface(q.exit[4],NULL,screen,&posyes);
                    SDL_Flip(screen);
                    SDL_Delay (200);
                    SDL_FreeSurface(background);
                    SDL_FreeSurface(q.exit[n]);
                    return 1;
                }
                else if (n==3)
                {
                    SDL_BlitSurface(q.exit[5],NULL,screen,&posno);
                    SDL_Flip(screen);
                    SDL_Delay (200);
                    SDL_FreeSurface(background);
                    SDL_FreeSurface(q.exit[n]);
                    return 0;
                }
                break;
            }
            break;
        case SDL_MOUSEMOTION:
            n=6;
            //printf("%d,%d\n",event.motion.x,event.motion.y);
            if  ((event.motion.x>140) && (event.motion.y>450) && (event.motion.x<427) && (event.motion.y<530))

            {
                n=2;
            }
            else if ((event.motion.x>630) && (event.motion.y>450) && (event.motion.x<917) && (event.motion.y<530) )

            {
                n=3;
            }
            break;
        case SDL_MOUSEBUTTONDOWN:
            if ((event.motion.x>140) && (event.motion.y>450) && (event.motion.x<427) && (event.motion.y<530))
            {
                SDL_BlitSurface(q.exit[4],NULL,screen,&posyes);
                SDL_Flip(screen);
                SDL_Delay (300);
                return 1;
            }
            else if ((event.motion.x>630) && (event.motion.y>450) && (event.motion.x<917) && (event.motion.y<530) )
            {
                SDL_BlitSurface(q.exit[5],NULL,screen,&posno);
                SDL_Flip(screen);
                SDL_Delay (300);
                return 0;
            }
            break;
        }
    }

}

