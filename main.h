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

/*provides us with a BOOLEAN type for using TRUE and FALSE*/
typedef enum true_false
{
    FALSE=0,TRUE
} BOOLEAN;

/*function prototypes*/

void clearScreen(void);
int drawMenu(Mix_Music *music, Mix_Music *music2);
BOOLEAN initMusic(void);
int drawMusicMenu(Mix_Music *music, Mix_Music *music2);