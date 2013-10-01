/*main.h*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SDL/SDL.h"
#include "SDL/SDL_mixer.h"





/*constants go here*/
#define EXTRA_SPACES 2
#define MAX_OPTION_INPUT 1
#define SCREENSIZE 200
#define THREAD_COUNT 5

/*provides us with a BOOLEAN type for using TRUE and FALSE*/
typedef enum true_false
{
    FALSE=0,TRUE
} BOOLEAN;

/*struct for the data passed to each thread, contains music, thread identifier and a string*/

struct music_params 
{
  Mix_Chunk *music;
  char *musstring; 
  int thread_identifier;
  
};

/*create global array variable of ints. This will be used for the thread IDs for printing*/
long int thread_ids[THREAD_COUNT];


/*function prototypes*/

void clearScreen(void);
int drawMenu(Mix_Chunk *music, Mix_Chunk *music2, Mix_Chunk *music3, Mix_Chunk *music4, Mix_Chunk *music5);
BOOLEAN initMusic(void);
void *play_music_in_thread(void *music_params);
void list_active_threads(void);

/* Function prototype for selectOutput(). Prompts user to select an audio 
output. Returns EXIT_SUCCCESS on success, or EXIT_FAILURE on failure. */
int selectOutput(void);