CFLAGS = -Wall -fpic-fprofile-arcs -ftest-coverage  -coverage -lm -std=c99

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g $(CFLAGS)

tests: unittest1.c unittest2.c unittest3.c unittest4.c testcard1.c testcard2.c testcard3.c testcard4.c dominion.c rngs.c

unittest1: unittest1.c dominion.o rngs.o
	gcc -o unittest1 -g dominion.o  rngs.o unittest1.c $(CFLAGS)
	./unittest1 &> unittestresults.out
	gcov dominion.c >> unittestresults.out
	cat dominion.c.gcov >> unittestresults.out

unittest2: unittest2.c dominion.o rngs.o
	gcc -o unittest2 -g dominion.o  rngs.o unittest2.c $(CFLAGS)
	./unittest2 &> unittestresults.out
	gcov dominion.c >> unittestresults.out
	cat dominion.c.gcov >> unittestresults.out
	
unittest3: unittest3.c dominion.o rngs.o
	gcc -o unittest3 -g dominion.o rngs.o unittest3.c $(CFLAGS)
	./unittest3 &> unittestresults.out
	gcov dominion.c >> unittestresults.out
	cat dominion.c.gcov >> unittestresults.out		


unittest4: unittest4.c dominion.o rngs.o 
	gcc -o unittest4 -g dominion.o rngs.o unittest4.c $(CFLAGS)
	./unittest4 &> unittestresults.out
	gcov dominion.c >> unittestresults.out
	cat dominion.c.gcov >> unittestresults.out
	
cardtest1: cardtest1.c dominion.o rngs.o
	gcc -o cardtest1 -g dominion.o rngs.o cardtest1.c $(CFLAGS)
	./cardtest1 &> unittestresults.out
	gcov dominion.c >> unittestresults.out
	cat dominion.c.gcov >> unittestresults.out

cardtest2: cardtest2.c dominion.o rngs.o
	gcc -o cardtest2 -g dominion.o rngs.o cardtest2.c $(CFLAGS)
	./cardtest2 &> unittestresults.out
	gcov dominion.c >> unittestresults.out
	cat dominion.c.gcov >> unittestresults.out
	
cardtest3: cardtest3.c dominion.o rngs.o
	gcc -o cardtest3 -g dominion.o rngs.o cardtest3.c $(CFLAGS)
	./cardtest3 &> unittestresults.out
	gcov dominion.c >> unittestresults.out
	cat dominion.c.gcov >> unittestresults.out

cardtest4: cardtest4.c dominion.o rngs.o	
	gcc -o cardtest4 -g dominion.o rngs.o cardtest4.c $(CFLAGS)
	./cardtest4 &> unittestresults.out
	gcov dominion.c >> unittestresults.out
	cat dominion.c.gcov >> unittestresults.out

randomtestcard1: randomtestcard1.c dominion.o rngs.o
	gcc -o randomtestcard1 -g dominion.o rngs.o randomtestcard1.c $(CFLAGS)
	./randomtestcard1 &> randomtestresults.out
	gcov dominion.c >> randomtestresults.out
	cat dominion.c.gcov >> randomtestresults.out

randomtestcard2: randomtestcard2.c dominion.o rngs.o
	gcc -o randomtestcard2 -g dominion.o rngs.o randomtestcard2.c $(CFLAGS)
	./randomtestcard2 &> randomtestresults.out
	gcov dominion.c >> randomtestresults.out
	cat dominion.c.gcov >> randomtestresults.out 

randomtestadventurer: randomtestadventurer.c dominion.o rngs.o
	gcc -o randomtestadventurer -g dominion.o rngs.o randomtestadventurer.c $(CFLAGS) 
	./randomtestadventurer &> randomtestresults.out
	gcov dominion.c >> randomtestresults.out
	cat dominion.c.gcov > randomtestresults.out


all: unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 dominion rngs

clean:
	rm tests.out

cleanall: 
	rm tests.out unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 *.gcda *.gcno *.gcov
