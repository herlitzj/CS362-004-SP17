#include "dominion.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "rngs.h"

#define TEST_REASON "Testing supplyCount(): This test simply adds a card to the game state "\
									  "with a given count and then tests to see if the correct count is returned when called"

int assertTrue(int A, int B) {
	if (A == B) return 0;
	else {
		printf("ASSERT FAILURE: %d != %d\n", A, B);
		return 1;
	};
}

int checkSupplyCount(int card, int count, struct gameState *state) {
  int r;
    
  r = supplyCount(card, state);

  return assertTrue(r, count);
}

int main() {

	int p, r, failures=0;

	int k[10] = {adventurer, council_room, feast, gardens, mine,
	       remodel, smithy, village, baron, great_hall};

	struct gameState G;

	printf("%s\n", TEST_REASON);

	SelectStream(2);
	PutSeed(3);

  for (p = 0; p < 10; p++) {
	  memset(&G, 23, sizeof(struct gameState)); 
	  r = initializeGame(2, k, 1, &G);
	  G.supplyCount[k[p]] = p;
	  failures += checkSupplyCount(k[p], p, &G);
  }

	if (failures > 0) printf("SUPPLY_COUNT TESTS FAILED TO PASS\n\n");
	else printf ("ALL SUPPLY_COUNT TESTS OK\n\n");

	exit(0);
}