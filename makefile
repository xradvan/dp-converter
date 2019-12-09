CC=g++ -std=c++11
CFLAGS=-g -lntl -lgmp -lm -lcryptopp -lpthread
C=-c

all: main.o
	$(CC) main.o -o converter $(CFLAGS)
	
main.o: main.cpp
	$(CC) $(C) main.cpp

clean:
	rm *.o
	rm converter