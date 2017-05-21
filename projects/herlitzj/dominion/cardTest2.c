#include "dominion.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "rngs.h"

#define TEST_REASON "Testing _smithy(): Test that _smithy() properly returns success when called"
#define TEST_PLAYER 1
#define SUCCESS 0
#define FAILURE -1

int assertTrue(int A, int B) {
	if (A == B) return 0;
	else {
		printf("ASSERT FAILURE: %d != %d\n", A, B);
		return 1;
	};
}

int check_smithy(struct gameState *state, int handPos, int expectedReturn) {
  int r;
  int currentPlayer = whoseTurn(state);
    
  r = _smithy(&currentPlayer, state, handPos);

  return assertTrue(r, expectedReturn);
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

	printf("CHECK FOR SUCCESS\n");
	failures += check_smithy(&G, 0, SUCCESS);
  
  if (failures > 0) printf("_SMITHY TESTS FAILED TO PASS\n\n");
	else printf ("ALL _SMITHY TESTS OK\n\n");

	exit(0);
}