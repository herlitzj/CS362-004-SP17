CFLAGS = -Wall -fpic -coverage -lm

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)

testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: testDrawCard 
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out

unitTest1.o: rngs.o dominion.o
	gcc -o unitTest1.o -g unitTest1.c rngs.o dominion.o $(CFLAGS)

unitTest2.o: rngs.o dominion.o
	gcc -o unitTest2.o -g unitTest2.c rngs.o dominion.o $(CFLAGS)

unitTest3.o: rngs.o dominion.o
	gcc -o unitTest3.o -g unitTest3.c rngs.o dominion.o $(CFLAGS)

unitTest4.o: rngs.o dominion.o
	gcc -o unitTest4.o -g unitTest4.c rngs.o dominion.o $(CFLAGS)

unittestresults.out: unitTest1.o unitTest2.o unitTest3.o unitTest4.o
	./unitTest1.o &> unittestresult.out
	./unitTest2.o >> unittestresult.out
	./unitTest3.o >> unittestresult.out
	./unitTest4.o >> unittestresult.out

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player testDrawCard testBuyCard badTestDrawCard

clean:
	rm -rf *.dSYM
	rm -f *.o playdom.exe playdom test.exe test player player.exe testInit testInit.exe *.gcov *.gcda *.gcno *.so *.out
