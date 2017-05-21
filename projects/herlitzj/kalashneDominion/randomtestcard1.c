#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>

int main()
{
	srand(time(NULL));

	struct gameState state;
	int rand_p=rand()%6+2,
		rand_h=rand()
		i=0;

	for(i=0;i<100;i++)
		Council_Room(&state,rand_p,rand_h);

	return 0;
}	
