#include "dominion.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "rngs.h"

#define TEST_REASON "Testing playCard(): This test trys to play a card out of phase, without sufficient actions "\
                    "and as both an action card and a non-action card and checks that the results are as expected."
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

void resetHandCount(struct gameState *state) {
	state->handCount[TEST_PLAYER] = 0;
}

void addCardToHand(struct gameState *state, int card) {
	int last = state->handCount[TEST_PLAYER];
	state->handCount[TEST_PLAYER]++;
	state->hand[TEST_PLAYER][last] = card;
}

int checkPlayCard(int handPos, int choice1, int choice2, int choice3, struct gameState *state, int expectedReturn) {
  int r;
  int returnValue = 0;
  int startNumActions = state->numActions;
    
  r = playCard(handPos, choice1, choice2, choice3, state);
  if(r == 0) startNumActions = startNumActions - 1;

  returnValue += assertTrue(r, expectedReturn);
  returnValue += assertTrue(state->numActions, startNumActions);

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
  resetHandCount(&G);
  G.coins = 0;
  G.whoseTurn = 1;

	printf("PHASE != 0\n");
	G.phase = 1;
	G.numActions = 1;
	failures += checkPlayCard(2, adventurer, council_room, feast, &G, FAILURE);
	resetHandCount(&G);

	printf("NUM_ACTIONS < 1\n");
	G.phase = 0;
	G.numActions = 0;
	failures += checkPlayCard(2, adventurer, council_room, feast, &G, FAILURE);
	resetHandCount(&G);

	printf("REJECT NON-ACTION CARD\n");
	G.phase = 0;
	G.numActions = 1;
	G.handCount[TEST_PLAYER]++;
	G.hand[TEST_PLAYER][0] = silver;
	failures += checkPlayCard(0, adventurer, council_room, feast, &G, FAILURE);
	resetHandCount(&G);

	printf("PLAY ACTION CARD\n");
	G.phase = 0;
	G.numActions = 1;
	G.handCount[TEST_PLAYER]++;
	G.hand[TEST_PLAYER][0] = smithy;
	failures += checkPlayCard(0, adventurer, council_room, feast, &G, SUCCESS);
	resetHandCount(&G);
  
  if (failures > 0) printf("PLAY_CARD TESTS FAILED TO PASS\n\n");
	else printf ("ALL PLAY_CARD TESTS OK\n\n");

	exit(0);
}