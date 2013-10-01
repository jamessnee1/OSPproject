/*menu.c*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include "main.h"
#include "SDL/SDL.h"
#include "SDL/SDL_mixer.h"



int drawMenu(Mix_Chunk *music, Mix_Chunk *music2, Mix_Chunk *music3, Mix_Chunk *music4, Mix_Chunk *music5){

  /*Create variables for each music thread*/
  pthread_t musthread1, musthread2, musthread3, musthread4, musthread5;
  int i, input, returnthread1, returnthread2, returnthread3, returnthread4, returnthread5;
  char charInput[MAX_OPTION_INPUT + EXTRA_SPACES];
  

  /*create structs of params to pass to each thread*/
  struct music_params thread1_args, thread2_args, thread3_args, thread4_args, thread5_args;
  
  /*fill structs with data*/
  thread1_args.musstring = "Currently playing music track 1 (Bass)";
  thread1_args.thread_identifier = 1;
  thread2_args.musstring = "Playing music track 2 (Strings and Melody)";
  thread2_args.thread_identifier = 2;
  thread3_args.musstring = "Currently playing music track 3 (Piano)";
  thread3_args.thread_identifier = 3;
  thread4_args.musstring = "Currently playing music track 4 (Percussion)";
  thread4_args.thread_identifier = 4;
  thread5_args.musstring = "Currently playing music track 5 (All tracks)";
  thread5_args.thread_identifier = 5;
  thread1_args.music = music;
  thread2_args.music = music2;
  thread3_args.music = music3;
  thread4_args.music = music4;
  thread5_args.music = music5;

  
  do{
    
   
    
    printf("Main Menu\n");
    printf("---------\n\n");
    
    /*If the specific channel is playing, print the appropriate prompt*/
    printf("0) Select Audio Output\n");
    
      if (Mix_Playing(1) == 0){
	printf("1) Play Music Track 1 (Bass)\n");
      }else {
	printf("1) Stop Music Track 1 (Bass)\n"); 
      }
      
      if (Mix_Playing(2) == 0){
	printf("2) Play Music Track 2 (Strings and Melody)\n");
      }else {
	printf("2) Stop Music Track 2 (Strings and Melody)\n");
      }
      
      if (Mix_Playing(3) == 0){
	printf("3) Play Music Track 3 (Piano)\n");
      }else {
	printf("3) Stop Music Track 3 (Piano)\n");
      }
      
       if (Mix_Playing(4) == 0){
	printf("4) Play Music Track 4 (Percussion)\n");
      }else {
	printf("4) Stop Music Track 4 (Percussion)\n");
      }
      
       if (Mix_Playing(5) == 0){
	printf("5) Play Music Track 5 (All tracks)\n");
      }else {
	printf("5) Stop Music Track 5 (All tracks)\n");
      }
      
    
    printf("6) Play All Music Tracks (Separate Threads)\n");
    printf("7) List active threads\n");
    printf("8) Stop all tracks\n");
    printf("9) Exit Program\n\n");
    
    for (i = 0; i < 2; i++){
	printf("\n");
    }
    
    printf("Select your option: ");

    
    
    
    fgets(charInput, MAX_OPTION_INPUT + EXTRA_SPACES, stdin);
    
    input = atoi(charInput);
    
    /*Switch statement for menu*/
    switch(input){
		
	case 0:				
	  
	  /* Repeatedly calls the selectOutput function until the user enters a
     valid option */
     while(selectOutput()==EXIT_FAILURE){}
	  break;
     
     
	case 1:
	  
	  /*checks to see if music is playing, else run the code to stop*/
	  if (Mix_Playing(1) == 0){
	     
	     /*Error checking*/
	    if (returnthread1 = pthread_create(&musthread1, NULL, play_music_in_thread, (void *) &thread1_args) != 0){
	      perror("Error: Could not create Thread 1!\n");
	      return 1;
	    }
	      pthread_join(musthread1, NULL);
	     
	     
	  }else{
	    
	    /*Stop channel*/
	    Mix_HaltChannel(1);
	    /*clear the TID out of the array*/
	    thread_ids[0] = 0;
	    printf("Track 1 stopped.\n");
	    
	  }
	   
	  break;
	case 2:
	  
	  if (Mix_Playing(2) == 0){
	    
	     if (returnthread2 = pthread_create(&musthread2, NULL, play_music_in_thread, (void *) &thread2_args) != 0){
	      perror("Error: Could not create Thread 2!\n");
	      return 1;
	    }
	      pthread_join(musthread2, NULL);
	      
	      
	  }else{
	    /*Stop channel*/
	    Mix_HaltChannel(2);
	    /*clear the TID out of the array*/
	    thread_ids[1] = 0;
	    printf("Track 2 stopped.\n");
	    
	  }
	  break;
	case 3:
	  
	  if (Mix_Playing(3) == 0){
	    
	     if (returnthread3 = pthread_create(&musthread3, NULL, play_music_in_thread, (void *) &thread3_args) != 0){
	      perror("Error: Could not create Thread 3!\n");
	      return 1;
	    } 
	      pthread_join(musthread3, NULL);
	      
	      
	  }else{
	    /*Stop channel*/
	    Mix_HaltChannel(3);
	    /*clear the TID out of the array*/
	    thread_ids[2] = 0;
	    printf("Track 3 stopped.\n");
	    
	  }
	  break;
	case 4:
	  
	   if (Mix_Playing(4) == 0){
	    
	     if (returnthread4 = pthread_create(&musthread4, NULL, play_music_in_thread, (void *) &thread4_args) != 0){
	      perror("Error: Could not create Thread 4!\n");
	      return 1;
	    }
	      pthread_join(musthread4, NULL);
	      
	   }else{
	    /*Stop channel*/
	    Mix_HaltChannel(4);
	    /*clear the TID out of the array*/
	    thread_ids[3] = 0;
	    printf("Track 4 stopped.\n");
	    
	  }
	  break;
	case 5:
	  
	  if (Mix_Playing(5) == 0){
	    
	     if (returnthread5 = pthread_create(&musthread5, NULL, play_music_in_thread, (void *) &thread5_args) != 0){
	      perror("Error: Could not create Thread 5!\n");
	      return 1;
	    }
	      pthread_join(musthread5, NULL);
	      
	  }else{
	    /*Stop channel*/
	    Mix_HaltChannel(5);
	    /*clear the TID out of the array*/
	    thread_ids[4] = 0;
	    printf("Track 5 stopped.\n");
	    
	  }
	  break;
	case 6:
	     if (returnthread1 = pthread_create(&musthread5, NULL, play_music_in_thread, (void *) &thread1_args) != 0){
	      perror("Error: Could not create Thread 1!\n");
	      return 1;
	    }
	     if (returnthread2 = pthread_create(&musthread5, NULL, play_music_in_thread, (void *) &thread2_args) != 0){
	      perror("Error: Could not create Thread 2!\n");
	      return 1;
	    }
	     if (returnthread3 = pthread_create(&musthread3, NULL, play_music_in_thread, (void *) &thread3_args) != 0){
	      perror("Error: Could not create Thread 3!\n");
	      return 1;
	    }
	     if (returnthread4 = pthread_create(&musthread4, NULL, play_music_in_thread, (void *) &thread4_args) != 0){
	      perror("Error: Could not create Thread 4!\n");
	      return 1;
	    }
 	  
	  pthread_join(musthread1, NULL);
	  pthread_join(musthread2, NULL);
	  pthread_join(musthread3, NULL);
	  pthread_join(musthread4, NULL);
	  break;
	case 7:
	  list_active_threads();
	  break;
	case 8:
	  
	  if(Mix_Playing(-1) !=0){
	      /*stop all channels from playing*/
	      Mix_HaltChannel(-1);
	      /*clear the array of Thread IDs*/
	      memset(thread_ids, 0, sizeof(int)*THREAD_COUNT);
	      clearScreen();
	      printf("All tracks stopped.\n");
	    }
	    else {
	      printf("Error: There is nothing playing!\n");
	    }
	  break;	
	case 9:
	  return EXIT_SUCCESS;
	  break;
	default:
	  printf("Error: Not a valid option! Please try again.\n\n");	
	  break;
		
	}
	

    
  }
  while (input != 9);
  
  

  return;

}

