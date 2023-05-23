  #include "input.h"


Input getInput( Input input)
 { 
    SDL_Event event;

    /* Keymapping : gère les appuis sur les touches et les enregistre
    dans la structure input */
   
    while (SDL_PollEvent(&event))
    {    
        switch (event.type)
        {

            case SDL_QUIT:
                exit(0);
            break;

            case SDL_KEYDOWN:
            
                switch (event.key.keysym.sym)
                {
                    case SDLK_ESCAPE:
                        exit(0);
                    break;
                     case SDLK_DELETE:
                        input.erase = 1;
                    break;
                    case SDLK_SPACE:
                        input.jump = 1;
                    break;

                      case SDLK_0:
                        input.attack = 1;
                    break;



                    case SDLK_LEFT:
                        input.left = 1;
                    break;

                    case SDLK_RIGHT:
                        input.right = 1;
                    break;

                    case SDLK_DOWN:
                        input.down = 1;
                       
                    break;

                    case SDLK_UP:
                        input.up = 1;
                        
                    break;

                    case SDLK_RETURN:
                        input.enter = 1;
                    break;
                    default:
                    break;
                    
                }

            break;

            case SDL_KEYUP:
                switch (event.key.keysym.sym)
                {
                    case SDLK_DELETE:
                        input.erase = 0;
                    break;
                               break; 
                 case SDLK_SPACE:
                        input.jump = 0;
                    break;

                      case SDLK_0:
                        input.attack = 0;
                    break;


                    case SDLK_LEFT:
                        input.left = 0;
                    break;

                    case SDLK_RIGHT:
                        input.right = 0;
                    break;

                    case SDLK_DOWN:
                        input.down = 0;
                    break;

                    case SDLK_UP:
                        input.up = 0;
                    break;

                    case SDLK_RETURN:
                        input.enter = 0;
                    break;

                    default:
                    break;
                }
            break;

        }
          
    } return input;
}



Input2 getInput2( Input2 input2)
 { 
    SDL_Event event1;

    /* Keymapping : gère les appuis sur les touches et les enregistre
    dans la structure input */
   
    while (SDL_PollEvent(&event1))
    {    
        switch (event1.type)
        {

            case SDL_QUIT:
                exit(0);
            break;

            case SDL_KEYDOWN:

                switch (event1.key.keysym.sym)
                {
                    case SDLK_ESCAPE:
                        exit(0);
                    break;
                   case SDLK_z:
                       input2.up=1;
                    break;
                   case SDLK_s:
                        input2.down =1;
                    break;
                    case SDLK_d:
                         input2.right=1;
                    break;
                    case SDLK_q:
                          input2.left=1;
                    break;

                    case SDLK_c:
                        input2.jump = 1;
                    break;

                      case SDLK_v:
                        input2.attack = 1;
                    break;

                    default:
                    break;

                }

            break;

            case SDL_KEYUP:
                switch (event1.key.keysym.sym)
                {
                   case SDLK_z:
                       input2.up=0;
                    break;
                   case SDLK_s:
                        input2.down =0;
                    break;
                    case SDLK_d:
                         input2.right=0;
                    break;
                    case SDLK_q:
                          input2.left=0;
                    break;


                    case SDLK_c:
                        input2.jump = 0;
                    break;
                   default:
                    break;
                }
            break;

        }

    } return input2;
}




