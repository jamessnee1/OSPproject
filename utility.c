/*utility.c*/

#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "SDL/SDL.h"
#include "SDL/SDL_mixer.h"

/*Function to clear the screen*/
void clearScreen(void){

	int i;
	for (i = 0; i < SCREENSIZE; i++){
		putchar('\n');
	}

}

BOOLEAN initMusic(void){
  
  /*Initialise SDL*/
  if (SDL_Init(SDL_INIT_EVERYTHING) == -1){
    perror("Error: Failed initialisation!\n");
    return FALSE;
    
  }
  
  /*Initialise music*/
  if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1){
    perror("Error: Could not load audio driver!\n");
    return FALSE;
    
  }

  
  /*If everything's good*/
  return TRUE;
}

