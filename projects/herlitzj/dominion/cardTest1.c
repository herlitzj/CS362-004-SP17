#include "dominion.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "rngs.h"

#define TEST_REASON "Testing _adventurer(): "
#define TEST_PLAYER 1
#define TEST_COUNT 10
#define SUCCESS 0
#define FAILURE -1

int assertTrue(int A, int B) {
	if (A == B) return 0;
	else {
		printf("ASSERT FAILURE: %d != %d\n", A, B);
		return 1;
	};
}

int check_adventurer(struct gameState *state) {
  int r;
  int temphand[MAX_HAND];
  int drawntreasure=0;
  int cardDrawn;
  int z = 0;// this is the counter for the temp hand
  int currentPlayer = whoseTurn(state);
    
  r = _adventurer(&currentPlayer, *drawntreasure, state, *z, temphand, *cardDrawn);

  return assertTrue(r, expectedCount);
}

int main() {

	int r, failures = 0;

	int k[10] = {adventurer, council_room, feast, gardens, mine,
	       remodel, smithy, village, baron, great_hall};

	struct gameState G;

	printf("%s\n", TEST_REASON);

	SelectStream(2);
	PutSeed(3);

	memset(&G, 23, sizeof(struct gameState)); 
  r = initializeGame(2, k, 1, &G);
  G.coins = 0;
  G.whoseTurn = TEST_PLAYER;

	printf("HAND COUNT SET TO 10\n");
	G.handCount[TEST_PLAYER] = TEST_COUNT;
	failures += checkNumHandCards(&G, TEST_COUNT);
  
  if (failures > 0) printf("NUM_HAND_CARDS TESTS FAILED TO PASS\n\n");
	else printf ("ALL NUM_HAND_CARDS TESTS OK\n\n");

	exit(0);
}