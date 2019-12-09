CC=g++ -std=c++11
CFLAGS=-g -lntl -lgmp -lm -lpthread
C=-c

all: main.o
	$(CC) main.o -o converter $(CFLAGS)
	./converter
	
main.o: main.cpp
	$(CC) $(C) main.cpp

clean:
	rm *.o
	rm converter