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


randomTestCard1.out: randomTestCard1.c rngs.o dominion.o
	gcc -o randomTestCard1.o -g randomTestCard1.c rngs.o dominion.o $(CFLAGS)
	./randomTestCard1.o &> randomtestcard1.out
	echo TESTING COVERAGE SUMMARY >> randomtestcard1.out
	gcov -f dominion.c >> randomtestcard1.out

randomTestCard2.out: randomTestCard2.c rngs.o dominion.o
	gcc -o randomTestCard2.o -g randomTestCard2.c rngs.o dominion.o $(CFLAGS)
	./randomTestCard2.o &> randomtestcard2.out
	echo TESTING COVERAGE SUMMARY >> randomtestcard2.out
	gcov -f dominion.c >> randomtestcard2.out

randomTestAdventurer.out: randomTestAdventurer.c rngs.o dominion.o
	gcc -o randomTestAdventurer.o -g randomTestAdventurer.c dominion.o rngs.o $(CFLAGS)
	./randomTestAdventurer.o &> randomtestadventurer.out
	echo TESTING COVERAGE SUMMARY >> randomtestadventurer.out
	gcov -f dominion.c >> randomtestadventurer.out

randomtestresults: randomTestCard1.o randomTestCard2.o randomTestAdventurer.o

unitTest1.o: rngs.o dominion.o
	gcc -o unitTest1.o -g unitTest1.c rngs.o dominion.o $(CFLAGS)

unitTest2.o: rngs.o dominion.o
	gcc -o unitTest2.o -g unitTest2.c rngs.o dominion.o $(CFLAGS)

unitTest3.o: rngs.o dominion.o
	gcc -o unitTest3.o -g unitTest3.c rngs.o dominion.o $(CFLAGS)

unitTest4.o: rngs.o dominion.o
	gcc -o unitTest4.o -g unitTest4.c rngs.o dominion.o $(CFLAGS)

cardTest1.o: rngs.o dominion.o
	gcc -o cardTest1.o -g cardTest1.c rngs.o dominion.o $(CFLAGS)

cardTest2.o: rngs.o dominion.o
	gcc -o cardTest2.o -g cardTest2.c rngs.o dominion.o $(CFLAGS)

cardTest3.o: rngs.o dominion.o
	gcc -o cardTest3.o -g cardTest3.c rngs.o dominion.o $(CFLAGS)

cardTest4.o: rngs.o dominion.o
	gcc -o cardTest4.o -g cardTest4.c rngs.o dominion.o $(CFLAGS)

unittestresults.out: unitTest1.o unitTest2.o unitTest3.o unitTest4.o cardTest1.o cardTest2.o cardTest3.o cardTest4.o
	./unitTest1.o &> unittestresult.out
	./unitTest2.o >> unittestresult.out
	./unitTest3.o >> unittestresult.out
	./unitTest4.o >> unittestresult.out
	./cardTest1.o >> unittestresult.out
	./cardTest2.o >> unittestresult.out
	./cardTest3.o >> unittestresult.out
	./cardTest4.o >> unittestresult.out
	echo TESTING COVERAGE SUMMARY >> unittestresult.out
	gcov -f dominion.c >> unittestresult.out

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player testDrawCard testBuyCard badTestDrawCard

clean:
	rm -rf *.dSYM
	rm -f *.o playdom.exe playdom test.exe test player player.exe testInit testInit.exe *.gcov *.gcda *.gcno *.so *.out
