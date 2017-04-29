#include "dominion.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "rngs.h"

#define TEST_REASON "Testing updateCoins(): This test adds different amounts of treasure coins to the test players "\
										"hand and checks to see if the coins are properly updated in the game state."
#define TEST_PLAYER 1

int assertTrue(int A, int B) {
	if (A == B) return 0;
	else {
		printf("ASSERT FAILURE: %d != %d\n", A, B);
		return 1;
	};
}

void resetHandCount(struct gameState *state) {
	state->handCount[TEST_PLAYER] = 0;
}

void addCardToHand(struct gameState *state, int card) {
	int last = state->handCount[TEST_PLAYER];
	state->handCount[TEST_PLAYER]++;
	state->hand[TEST_PLAYER][last] = card;
}

int checkUpdateCoins(int player, struct gameState *state, int bonus, int expectedCoins) {
  int r;
  int returnValue = 0;
    
  r = updateCoins(player, state, bonus);

  returnValue += assertTrue(r, 0);
  returnValue += assertTrue(state->coins, expectedCoins);

  return returnValue;
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
  G.handCount[TEST_PLAYER] = 0;
  G.coins = 0;

	printf("TEST ONE COPPER\n");
  addCardToHand(&G, copper);
  failures += checkUpdateCoins(TEST_PLAYER, &G, 0, 1);
  resetHandCount(&G);

  printf("TEST TWO SILVER\n");
  addCardToHand(&G, silver);
  addCardToHand(&G, silver);
  failures += checkUpdateCoins(TEST_PLAYER, &G, 0, 4);
  resetHandCount(&G);

  printf("TEST ONE GOLD\n");
  addCardToHand(&G, gold);
  failures += checkUpdateCoins(TEST_PLAYER, &G, 0, 3);
  resetHandCount(&G);

  printf("TEST ONE SILVER AND 3 BONUS\n");
  addCardToHand(&G, silver);
  failures += checkUpdateCoins(TEST_PLAYER, &G, 3, 5);
  resetHandCount(&G);

  printf("TEST ONE COPPER, ONE ADVENTURER, ONE FEAST\n");
  addCardToHand(&G, feast);
  addCardToHand(&G, copper);
  addCardToHand(&G, adventurer);
  failures += checkUpdateCoins(TEST_PLAYER, &G, 0, 1);
  resetHandCount(&G);
  
  if (failures > 0) printf("UPDATE_COINS TESTS FAILED TO PASS\n\n");
	else printf ("ALL UPDATE_COINS TESTS OK\n\n");

	exit(0);
}