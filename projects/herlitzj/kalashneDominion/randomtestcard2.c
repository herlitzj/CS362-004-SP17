#include "dominion.h"
#include "dominion_help.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "rngs.h"
#include <time.h>

int main()
{
	srand(time(NULL));

	struct gameState state;
	int rand_p=rand()%6+2,
		random=rand(),
		i=0;

	for(i=0;i<100;i++)
	{
		Smithy(&state, rand_p,random);
	}	

	return 0;
}
