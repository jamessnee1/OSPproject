/*main.c*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include "main.h"
#include "SDL/SDL.h"
#include "SDL/SDL_mixer.h"


int main(int argc, char *argv[]){

  int lines;
  int c;
  
  /*Create music variables*/
  Mix_Chunk *intro = NULL;
  Mix_Chunk *music = NULL;
  Mix_Chunk *music2 = NULL;
  Mix_Chunk *music3 = NULL;
  Mix_Chunk *music4 = NULL;
  Mix_Chunk *music5 = NULL;

  
  /*Call init function*/
  initMusic();
  
  /*Load wavs into variables*/
  intro = Mix_LoadWAV("intro.wav");
  music = Mix_LoadWAV("music1.wav");
  music2 = Mix_LoadWAV("music2.wav");
  music3 = Mix_LoadWAV("music3.wav");
  music4 = Mix_LoadWAV("music4.wav");
  music5 = Mix_LoadWAV("music5.wav");
  
  if (music == NULL && music2 == NULL && music3 == NULL && music4 == NULL && music5 == NULL){
    perror("Error loading music files! Exiting...\n");
    return EXIT_FAILURE;
    
  }

  if (intro == NULL){
    perror("Error loading sound effect! Exiting...\n");
    return EXIT_FAILURE;
  }
  
  
  /*Play sound effect*/
  Mix_PlayChannel(-1, intro, 0);
  
  clearScreen();
  
  for (lines = 0; lines < 10; lines++){
    
    printf("\n");
    
  }

  printf("                   	  Raspberry Pi Dup-Box v1.0\n");
  printf("                -------------------------------------------\n\n");
  printf("                By James Snee, Arabella Pollock and Ryan Larke\n");
  printf("		    Uses the SDL and SDL Mixer Libraries\n");
  printf("		     The process ID of this run is: %d\n", getpid());
  
  for (lines = 0; lines < 10; lines++){
    
    printf("\n");
    
  }
  
  printf("Press enter to continue...\n");
  c = getchar();
  /*Stop sound effect if still playing*/
  Mix_HaltChannel(-1);
  
  /*if user doesn't press enter the screen will not advance*/
  while (c != '\n' && c != EOF){ 
    c=getchar(); 
  }
  
  clearScreen();
  
  drawMenu(music, music2, music3, music4, music5);
  
  /*Free music*/
  Mix_FreeChunk(music);
  Mix_FreeChunk(music2);
  Mix_FreeChunk(music3);
  Mix_FreeChunk(music4);
  Mix_FreeChunk(music5);
  Mix_FreeChunk(intro);
 
 
  clearScreen();
  printf("Thank you for using Pi Dup-Box!\n");
  
  /*Close the audio and Quit SDL, frees graphics*/
  Mix_CloseAudio();
  SDL_Quit();
  
  /*Kills the process, this is so no stray threads are still running*/
  kill(getpid(), 0);
  
return EXIT_SUCCESS;
}
