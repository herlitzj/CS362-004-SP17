#include "dominion.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "rngs.h"

#define TEST_REASON "Testing updateCoins(): REASON "
#define TEST_PLAYER 1

int assertTrue(int A, int B) {
	if (A == B) return 0;
	else {
		printf("ASSERT FAILURE: %d != %d\n", A, B);
		return 1;
	};
}

int checkUpdateCoins(int player, struct gameState *state, int bonus, int expectedCoins) {
  int r;
  int returnValue = 0;
    
  r = updateCoins(player, state, bonus);

  returnValue += assertTrue(r, 0);
  returnValue += assertTrue(state->coins, 2);

  return returnValue;
}

int main() {

	int p, r, failures = 0;

	int k[10] = {adventurer, council_room, feast, gardens, mine,
	       remodel, smithy, village, baron, great_hall};

	struct gameState G;

	printf("%s\n", TEST_REASON);

	SelectStream(2);
	PutSeed(3);

	printf ("SIMPLE FIXED TESTS.\n");

	memset(&G, 23, sizeof(struct gameState)); 
  r = initializeGame(2, k, 1, &G);
  G.handCount[TEST_PLAYER] = 0;
  G.coins = 0;

	printf("TEST ONE COPPER\n");
  G.handCount[TEST_PLAYER]++;
  G.hand[TEST_PLAYER][0] = copper;
  failures += checkUpdateCoins(TEST_PLAYER, &G, 0, 1);
  
  if (failures > 0) printf("UPDATE_COINS TESTS FAILED TO PASS\n");
	else printf ("ALL UPDATE_COINS TESTS OK\n\n");

	exit(0);
}