/*main.c*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
#include "SDL/SDL.h"
#include "SDL/SDL_mixer.h"


int main(){

  int lines;

  Mix_Music *music = NULL;
  Mix_Music *music2 = NULL;
  
  /*Call init function*/
  initMusic();
  
  music = Mix_LoadMUS("radagio.mp3");
  music2 = Mix_LoadMUS("holiday.mp3");
  
  if (music == NULL){
    perror("Error loading music file! Exiting...\n");
    return EXIT_FAILURE;
    
  }
  
  if (music2 == NULL){
    perror("Error: Missing file holiday.mp3! Exiting...\n");
    return EXIT_FAILURE;
    
  }
  
  /*If no music is playing, play music*/
  if (Mix_PlayingMusic() == 0){
    
    if(Mix_PlayMusic(music, -1) == -1){
      return 1;
      
    }
    
  }
  


  
  clearScreen();

  printf("                   Linux Bash Configuration Utility v1.0\n");
  printf("                -------------------------------------------\n\n");
  printf("                By Ryan Larke, James Snee and Bella Pollock\n");
  printf("		     Uses the SDL and SDL Mixer Libraries\n");
  
  for (lines = 0; lines < 10; lines++){
    
    printf("\n");
    
  }
  
  printf("Press enter to continue...\n");
  getchar();
  clearScreen();
  drawMenu(music, music2);
  
  /*Free music*/
  Mix_FreeMusic(music);
  Mix_FreeMusic(music2);

  printf("If any changes were made to .bash_profile, they will be visible when restarting your system.\n");

return EXIT_SUCCESS;
}