#include "dominion.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "rngs.h"

#define TEST_REASON "Testing _village(): Test that _village() properly returns success when called"
#define TEST_PLAYER 0
#define SUCCESS 0
#define FAILURE -1

int assertTrue(int A, int B) {
	if (A == B) return 0;
	else {
		printf("ASSERT FAILURE: %d != %d\n", A, B);
		return 1;
	};
}

int check_village(struct gameState *state, int expectedNumAction, int expectedHandCount, int expectedReturn) {
  int r, failures=0;
  int currentPlayer = whoseTurn(state);
    
  r = _village(&currentPlayer, state, 1);

  failures += assertTrue(state->numActions, expectedNumAction);
  failures += assertTrue(state->handCount[TEST_PLAYER], expectedHandCount);
  failures += assertTrue(r, expectedReturn);

  return failures;
}

int main() {

	int r, expectedNumAction, failures = 0;

	int k[10] = {adventurer, council_room, feast, gardens, mine,
	       remodel, smithy, village, baron, great_hall};

	struct gameState G;

	printf("%s\n", TEST_REASON);

	SelectStream(2);
	PutSeed(3);

	memset(&G, 23, sizeof(struct gameState)); 
  r = initializeGame(2, k, 1, &G);
  expectedNumAction = G.numActions + 2;

	printf("CHECK FOR NUM ACTIONS INCREASED BY 2 AND HAND COUNT REMAINS SAME AND RETURNS SUCCESS\n");
	failures += check_village(&G, expectedNumAction, G.handCount[TEST_PLAYER], SUCCESS);
  
  if (failures > 0) printf("_VILLAGE TESTS FAILED TO PASS\n\n");
	else printf ("ALL _VILLAGE TESTS OK\n\n");

	exit(0);
}