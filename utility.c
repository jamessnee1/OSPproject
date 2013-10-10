/*utility.c*/

#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "SDL/SDL.h"
#include "SDL/SDL_mixer.h"


/*create mutex as a global variable*/
int counter;
pthread_mutex_t lock;

/*Unix function call to clear the screen*/
void clearScreen(void){
	
	system("clear");

}

BOOLEAN initMusic(void){
  
  /*Initialise SDL*/
  if (SDL_Init(SDL_INIT_AUDIO) == -1){
    perror("Error: Failed initialisation!\n");
    return FALSE;
    
  }
  
  
  /*Initialise music*/
  if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1){
    perror("Error: Could not load audio driver!\n");
    return FALSE;
    
  }
  
  /*create 6 channels for mixing*/
  if (Mix_AllocateChannels(6) == -1){
    perror("Error: Could not create audio channels!\n");
    return FALSE;
  }

  
  /*If everything's good*/
  return TRUE;
}

void *play_music_in_thread(void *music_params){
  
  /*lock thread*/
  pthread_mutex_lock(&lock);
  printf("Thread locked!\n");
  
  counter += 1;

  int i;
  int count = 0;
  /*create a new pointer to struct passed in*/
  struct music_params *param_ptr;
  
  /*assign struct passed in to ptr*/
  param_ptr = music_params;


 
  /*add thread ID to the array*/
  for (i = 0; i < THREAD_COUNT; i++){
      if (param_ptr->thread_identifier == 1){
	thread_ids[0] = (long int)syscall(224);
    
      }else if (param_ptr->thread_identifier == 2){
    
	thread_ids[1] = (long int)syscall(224);
    
      }else if (param_ptr->thread_identifier == 3){
    
	thread_ids[2] = (long int)syscall(224);
    
      }else if (param_ptr->thread_identifier == 4){
    
	thread_ids[3] = (long int)syscall(224);
    
      }else if (param_ptr->thread_identifier == 5){
    
	thread_ids[4] = (long int)syscall(224);
    
      }
  }
  
  printf("Thread created! Thread ID: %ld. %s\n",(long int)syscall(224),  param_ptr->musstring);
  /*Play music from music variable and identifier passed in, this will play the music on a certain track*/
  /*For example, int Mix_PlayChannel (int channel, Mix_Chunk *chunk, int loops); loops is 0 which means it will play 1 time*/
  Mix_PlayChannel(param_ptr->thread_identifier, param_ptr->music, 0);
  
  /*The following is test timing code, please comment out if not using*/
  while(Mix_Playing(-1) == 1){
    
    printf("%i\n", count);
 
    /**********************************************************************
      usleep is like sleep,except we can specify time in microseconds
      Music is 138 BPM, in 4/4 time, 1739 milliseconds 
      1739000 microseconds per bar / 4 = 434750 gives us the beats per bar
      *********************************************************************/
    usleep(434750);
    count++;
  }
  
  /*unlock thread*/
  pthread_mutex_unlock(&lock);
  printf("Thread unlocked!\n");
 return;
}

void list_active_threads(void){

  int i, count = 1;
  printf("List of active threads\n");
  printf("----------------------\n\n");
  printf("The Process ID of this run is: %i\n", getpid());
  printf("%d channels are playing.\n", Mix_Playing(-1));
  printf("Current thread ID's playing: \n");
  
  for (i = 0; i < THREAD_COUNT; i++, count++){
    if (thread_ids[i] == 0){
      printf("Thread %i: There is nothing playing.\n", count);
    }else{
      printf("Thread %i: %ld\n",count, thread_ids[i]);
      
    }
    
    
  }
  
}

/*selectOutput function by Ryan Larke*/
int selectOutput(void){
   char charInput[MAX_OPTION_INPUT + EXTRA_SPACES];
   int input;

   printf("Select audio output\n");
   printf("---------\n\n");
   printf("0) HDMI\n");
   printf("1) 3.5mm socket\n");
   printf("2) Return to main menu\n");
   fgets(charInput, MAX_OPTION_INPUT + EXTRA_SPACES, stdin);
   input = atoi(charInput);
   if(input==0){
      system("sudo amixer cset numid=3 2 > /dev/null");
      printf("Audio output changed to HDMI\n");
      return EXIT_SUCCESS;
   }else if(input==1){
      system("sudo amixer cset numid=3 1 > /dev/null");
      printf("Audio output changed to 3.5mm\n");
      return EXIT_SUCCESS;
   }
   else if(input==2){
      return EXIT_SUCCESS;
   }
   else{
      printf("Invalid option. Please try again.\n\n");
      return EXIT_FAILURE;
   }
}




