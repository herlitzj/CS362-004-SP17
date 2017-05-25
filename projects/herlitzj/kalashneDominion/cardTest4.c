#include "dominion.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "rngs.h"

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define TEST_REASON "Testing _gardens(): Test that _gardens() properly returns failure when called"
#define TEST_PLAYER 1
#define SUCCESS 0
#define FAILURE -1

int assertTrue(int A, int B) {
	if (A == B) return 0;
	else {
		printf(KRED);
		printf("ASSERT FAILURE: %d != %d\n", A, B);
		printf(KNRM);
		return 1;
	};
}

int check_gardens(int expectedReturn) {
  int r;
    
  r = _gardens();

  return assertTrue(r, expectedReturn);
}

int main() {

	int failures = 0;

	printf("%s\n", TEST_REASON);
	printf("CHECK FOR FAILURE\n");
	failures += check_gardens(FAILURE);
  
  if (failures > 0) printf("_GARDENS TESTS FAILED TO PASS\n\n");
	else printf ("ALL _GARDENS TESTS OK\n\n");

	exit(0);
}