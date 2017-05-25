#include "dominion.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "rngs.h"

#define TEST_REASON "Testing _adventurer(): Tests whether or not hand count and discard count are properly updated."
#define TEST_PLAYER 0
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

int check_adventurer(struct gameState *state, int expectedHandCount, int expectedDiscardCount, int expectedReturn) {
  int r, failures=0;
  int temphand[MAX_HAND];
  int drawntreasure=0;
  int cardDrawn = 0;
  int z = 0;// this is the counter for the temp hand
  int currentPlayer = TEST_PLAYER;
    
  r = Adventurer(state, currentPlayer, drawntreasure, cardDrawn, temphand, z);

  failures += assertTrue(state->handCount[TEST_PLAYER], expectedHandCount);
  failures += assertTrue(state->discardCount[TEST_PLAYER], expectedDiscardCount);
  failures += assertTrue(r, expectedReturn);
  return failures;
}

int main() {

	int r, expectedDiscardCount, expectedHandCount, failures = 0;

	int k[10] = {adventurer, council_room, feast, gardens, mine,
	       remodel, smithy, village, baron, great_hall};

	struct gameState G;

	printf("%s\n", TEST_REASON);

	SelectStream(2);
	PutSeed(3);

	memset(&G, 23, sizeof(struct gameState)); 
  r = initializeGame(2, k, 1, &G);
  G.handCount[TEST_PLAYER] = 3;
  G.discardCount[TEST_PLAYER] = 0;

	printf("NEXT TWO CARDS ARE COPPER\n");
	G.deck[TEST_PLAYER][0] = copper;
	G.deck[TEST_PLAYER][1] = copper;
	expectedHandCount = G.handCount[TEST_PLAYER] + 2;
	expectedDiscardCount = G.discardCount[TEST_PLAYER];
	failures += check_adventurer(&G, expectedHandCount, expectedDiscardCount, SUCCESS);

	printf("NEXT THREE CARDS ARE ONE SMITHY AND 2 COPPER\n");
	G.deck[TEST_PLAYER][0] = copper;
	G.deck[TEST_PLAYER][1] = smithy;
	G.deck[TEST_PLAYER][2] = copper;
	expectedHandCount = G.handCount[TEST_PLAYER] + 2;
	expectedDiscardCount = G.discardCount[TEST_PLAYER] + 1;
	failures += check_adventurer(&G, expectedHandCount, expectedDiscardCount, SUCCESS);

	printf("DECK IS EMPTY AND NEEDS TO BE SHUFFLED\n");
	G.deckCount[TEST_PLAYER] = 0;
	int currentPlayer = TEST_PLAYER;
	int drawntreasure = 0;
	int z = 0;
	int temphand[MAX_HAND];
	int cardDrawn = 0;
	failures += assertTrue(Adventurer(&G, currentPlayer, drawntreasure, cardDrawn, temphand, z), SUCCESS);
  
  if (failures > 0) printf("%d _ADVENTURER TEST(S) FAILED TO PASS\n\n", failures);
	else printf ("ALL _ADVENTURER TESTS OK\n\n");

	exit(0);
}