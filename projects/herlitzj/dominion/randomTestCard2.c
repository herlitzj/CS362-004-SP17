#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <time.h>

#define DEBUG 0
#define NOISY_TEST 1

int assertTrue(int A, int B) {
  if (A == B) return 0;
  else {
    return 1;
  };
}

int checkSmithy(int currentPlayer, struct gameState *post, int handPos) {
  struct gameState pre;
  memcpy (&pre, post, sizeof(struct gameState));

  int i, r, failures=0;
    
  r = _smithy(&currentPlayer, post, handPos);
  failures += assertTrue(r, 0);
  failures += assertTrue(pre.deckCount[currentPlayer] - 3, post->deckCount[currentPlayer]);
  failures += assertTrue(pre.handCount[currentPlayer] + 3 - 1, post->handCount[currentPlayer]);

  return failures;

}


int main () {

  int i, n, j, r, p, currentPlayer, failures=0;

  int k[10] = {adventurer, council_room, feast, gardens, mine,
	       remodel, smithy, village, baron, great_hall};

  struct gameState G;

  for (n = 0; n < 2000; n++) {
    for (i = 0; i < sizeof(struct gameState); i++) {
      ((char*)&G)[i] = floor(Random() * 256);
    }

    srand(time(NULL));
    SelectStream(2);
    PutSeed(rand() % 3 + 1);
    
    p = floor(Random() * 3) + 2;
    r = initializeGame(p, k, 1, &G);
    currentPlayer = floor(Random() * p) + 1;
    
    for(j = 1; j <= p; j++) {
      G.deckCount[j] = floor(Random() * MAX_DECK);
      G.discardCount[j] = floor(Random() * MAX_DECK);
      G.handCount[j] = floor(Random() * MAX_HAND);
      G.numBuys = 1;
    }
    failures += checkSmithy(currentPlayer, &G, 0);
  }
  
  if (failures > 0) printf("_SMITHY TESTS FAILED TO PASS WITH %d FAILURES\n\n", failures);
  else printf ("ALL _SMITHY TESTS OK\n\n");

  exit(0);

  return 0;
}
