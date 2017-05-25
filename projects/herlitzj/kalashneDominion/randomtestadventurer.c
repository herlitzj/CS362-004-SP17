#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
// #include <stdlib.h>
#include <assert.h>
// #include <math.h>
#include "rngs.h"
// #include <time.h>

#define DEBUG 0
#define NOISY_TEST 1

int assertTrue(int A, int B) {
  if (A == B) return 0;
  else {
    return 1;
  };
}

int checkAdventurer(int currentPlayer, struct gameState *post) {

  int i, r, z=0, cardDrawn=0, failures=0, drawntreasure=0;
  int temphand[MAX_HAND];
  
  r = Adventurer(post, currentPlayer, drawntreasure, cardDrawn, temphand, z);
  failures += assertTrue(r, 0);
  failures += assertTrue(drawntreasure, 2);

  return failures;

}

void setRandomDeck(int player, struct gameState *game) {
  int i, card;
  game->deck[player][0] = copper;
  game->deck[player][1] = silver;
  game->deck[player][2] = gold;

  for (i = 3; i <= game->deckCount[player]; i++) {
    card = floor(Random() * baron) + curse;
    game->deck[player][i] = card;
  }

  shuffle(player, game);
}


int main () {

  int i, n, j, r, totalPlayers, currentPlayer, failures=0;


  SelectStream(2);
  PutSeed(3);

  for (n = 0; n < 2000; n++) {
    struct gameState G;
    for (i = 0; i < sizeof(struct gameState); i++) {
      ((char*)&G)[i] = floor(Random() * 256);
    }
    
    totalPlayers = floor(Random() * 2) + 2;
    currentPlayer = floor(Random() * totalPlayers) + 1;
    G.deckCount[currentPlayer] = floor(Random() * (MAX_DECK - 50)) + 50;
    G.discardCount[currentPlayer] = floor(Random() * MAX_DECK);
    G.handCount[currentPlayer] = floor(Random() * MAX_HAND);
    setRandomDeck(currentPlayer, &G);

    failures += checkAdventurer(currentPlayer, &G);
  }

  
  if (failures > 0) printf("_ADVENTURER TESTS FAILED TO PASS WITH %d FAILURES\n\n", failures);
  else printf ("ALL _ADVENTURER TESTS OK\n\n");

  exit(0);

  return 0;
}
