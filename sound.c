#include "sound.h"
  
  void initialiser_audio(Mix_Music *music)
    {
        if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
        {
            printf("%s",SDL_GetError());}
music=Mix_LoadMUS("resources_menu/music.mp3");
Mix_PlayMusic(music,-1);
Mix_VolumeMusic(MIX_MAX_VOLUME/3.5);}
void initialiser_audiobref(Mix_Chunk *music)
{
    Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT , 2 , 2048);
    music=Mix_LoadWAV("resources_menu/click.wav");
    Mix_PlayChannel(-1,music,0);
    if(music==NULL)printf("%s",SDL_GetError());}



