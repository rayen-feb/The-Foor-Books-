#include "audio.h"
Mix_Chunk *loadSound(char *name)
{
	/* Load the sound specified by the filename */
	
	Mix_Chunk *sfx = Mix_LoadWAV(name);

	if (sfx == NULL)
	{
		printf("Failed to load sound %s\n", name);
	}
	
	return sfx;
}

void playSound(Mix_Chunk *sfx)
{
	/* Play the sound on the first free channel and only play it once */
	
	Mix_PlayChannel(1, sfx, 0);
}
Mix_Music *loadSound_infini(char *name)
{
	/* Load the sound specified by the filename */
	
	Mix_Music *sfx = Mix_LoadMUS(name);

	if (sfx == NULL)
	{
		printf("Failed to load sound %s\n", name);
	}
	
	return sfx;
}


void playSound_infini(Mix_Music *sfx)
{
	/* Play the sound on the first free channel and only play it once */
	
	Mix_PlayMusic(sfx, -1);
}


