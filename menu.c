/*menu.c*/

#include <stdio.h>
#include <stdlib.h>
#include "main.h"


int drawMenu(Mix_Music *music, Mix_Music *music2){

  int i, input;
  char charInput[MAX_OPTION_INPUT + EXTRA_SPACES];
  
  clearScreen();
  
  do{
    
   
    
    printf("Main Menu\n");
    printf("---------\n\n");
    printf("1) Change terminal prompt colour\n");
    printf("2) \n");
    printf("3) \n");
    printf("4) Change music\n");
    printf("5) Exit Program\n\n");
    
    for (i = 0; i < 10; i++){
	printf("\n");
    }
    
    printf("Select your option: ");
    
    fgets(charInput, MAX_OPTION_INPUT + EXTRA_SPACES, stdin);
    
    input = atoi(charInput);
    
    /*Switch statement for menu*/
    switch(input){
		
	case 0:				
	  clearScreen();
	  printf("Error: Not a valid option! Please try again.\n\n");
	  break;
	case 1:
	  clearScreen();
	  printf("Option 1 doesn't work right now.\n\n");
	  break;
	case 2:
	  clearScreen();
	  printf("Option 2 doesn't work right now.\n\n");
	  break;
	case 3:
	  clearScreen();
	  printf("Option 3 doesn't work right now.\n\n");
	  break;
	case 4:
	  clearScreen();
	  drawMusicMenu(music,music2);
	  break;
	case 5:
	  return EXIT_SUCCESS;
	  break;
	case 6:
	  clearScreen();
	  printf("Error: Not a valid option! Please try again.\n\n");
	  break;
	case 7:
	  clearScreen();
	  printf("Error: Not a valid option! Please try again.\n\n");
	  break;
	case 8:
	  clearScreen();
	  printf("Error: Not a valid option! Please try again.\n\n");
	  break;	
	case 9:
	  clearScreen();
	  printf("Error: Not a valid option! Please try again.\n\n");
	  break;	

		
	}
    
  }
  while (input != 5);
  
  clearScreen();

  return;

}

int drawMusicMenu(Mix_Music *music, Mix_Music *music2){
  
  int i, input;
  char charInput[MAX_OPTION_INPUT + EXTRA_SPACES];
  
  clearScreen();
  
  do{
    printf("Music Menu\n");
    printf("----------\n\n");
    printf("1) Play/stop current song\n");
    printf("2) Holiday - Green Day\n");
    printf("3) Return to main menu\n\n");
    
    for (i = 0; i < 10; i++){
	printf("\n");
    }
    
    printf("Select your option: ");
    
    fgets(charInput, MAX_OPTION_INPUT + EXTRA_SPACES, stdin);
    
    input = atoi(charInput);
    
    switch(input){
      
      case 0:
	clearScreen();
	printf("Error: Not a valid option! Please try again.\n\n");
	break;
      case 1:
	    clearScreen();
	    if(Mix_PlayingMusic() == 1){
	      Mix_PauseMusic();
	    }
	    else {
	      Mix_PlayMusic(music, -1);
	    }
	break;
      case 2:
	    clearScreen();
	    if(Mix_PlayingMusic() == 1){
	      Mix_PauseMusic();
	      Mix_PlayMusic(music2, -1);
	    }
	    else {
	      Mix_PlayMusic(music2, -1);
	      
	    }
	break;
      case 3:
	  clearScreen();
	  return;
	break;
      default:
	clearScreen();
	printf("Error: Not a valid option! Please try again.\n\n");
	break;
      
      
    }
    
  }
  while(input !=3);
  
  
  
  return;
}


