#include "instruction.h"

/**
* @file instruction.c
* @brief Testing instruction.
* @author Rayenbouazizi 
* @version 0.1
*
* Testing program for instruction of the menu 
*
*/


void instructions(SDL_Surface *screen)
{
  SDL_Surface *background=NULL;
  commands c;
  SDL_Rect posback;
  SDL_Event event;
  int n=0;
  int done=1;

  c.pos.x=200;
  c.pos.y=200;

  posback.x=650;
  posback.y=700;

  background=IMG_Load("resources_menu/menu1.png");
  c.instruction=IMG_Load("resources_menu/ins.png");
  c.backbutton[0]=IMG_Load("resources_menu/back0.png");
  c.backbutton[1]=IMG_Load("resources_menu/back1.png");
  c.backbutton[2]=IMG_Load("resources_menu/back2.png");
  while (done!=0)
  {
      SDL_BlitSurface(background,NULL,screen,NULL);
      SDL_BlitSurface(c.instruction,NULL,screen,&c.pos);
      SDL_BlitSurface(c.backbutton[n],NULL,screen,&posback);
      SDL_Flip(screen);
      SDL_WaitEvent(&event);
          switch(event.type)
          {
          case SDL_QUIT:
                done=0;
                break;
          case SDL_KEYDOWN:
            switch(event.key.keysym.sym)
            {
            case SDLK_ESCAPE:
                done=0;
                break;
            }
            case SDL_MOUSEMOTION:
                if ((event.motion.x>650) && (event.motion.y>700) && (event.motion.x<937) && (event.motion.y<780))
                {
                    n=1;
                }else
                {
                    n=0;
                }
                break;
            case SDL_MOUSEBUTTONDOWN:
                if ((event.motion.x>650) && (event.motion.y>700) && (event.motion.x<937) && (event.motion.y<780))
                {
                    SDL_BlitSurface(c.backbutton[2],NULL,screen,&posback);
                    SDL_Flip(screen);
                    SDL_Delay(50);
                    done=0;
                    //return 1;
                    //SDL_FreeSurface(backbutton[1]);
                   // SDL_FreeSurface(backbutton[2]);
                }
                break;
          }
  }
}
