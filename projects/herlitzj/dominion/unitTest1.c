#include "dominion.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "rngs.h"

#define TEST_REASON "Testing supplyCount(): "

void checkSupplyCount(int p, struct gameState *post) {
  int r;
    
  r = supplyCount(p, post);

  printf("REASON: %s\n", TEST_REASON);

  assert (r == 0);
}

int main() {

	int i, p, r, deckCount, discardCount, supplyCount;

	int k[10] = {adventurer, council_room, feast, gardens, mine,
	       remodel, smithy, village, baron, great_hall};

	struct gameState G;

	printf ("Testing supplyCount.\n");

	SelectStream(2);
	PutSeed(3);

	printf ("SIMPLE FIXED TESTS.\n");
  for (p = 0; p < 2; p++) {
    for (deckCount = 0; deckCount < 5; deckCount++) {
      for (discardCount = 0; discardCount < 5; discardCount++) {
				for (supplyCount = 0; supplyCount < 5; supplyCount++) {
				  memset(&G, 23, sizeof(struct gameState)); 
				  r = initializeGame(2, k, 1, &G);
				  G.deckCount[p] = deckCount;
				  memset(G.deck[p], 0, sizeof(int) * deckCount);
				  G.discardCount[p] = discardCount;
				  memset(G.discard[p], 0, sizeof(int) * discardCount);
				  G.supplyCount[p] = supplyCount;
				  memset(G.hand[p], 0, sizeof(int) * supplyCount);
				  checkSupplyCount(p, &G);
				}
      }
    }
  }

	printf ("ALL TESTS OK\n");

	exit(0);
}