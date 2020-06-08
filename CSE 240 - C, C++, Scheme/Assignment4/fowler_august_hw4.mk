OBJS = fowler_august_hw4.o grabbag.o
CODE = fowler_august_hw4.cpp fowler_august_hw4.h grabbag.cpp grabbag.h
CC = g++ 
DEBUG = -g
COMPFLAGS := -std=c++11
CFLAGS = $(COMPFLAGS) -Wall -c $(DEBUG)
LFLAGS = $(COMPFLAGS) -Wall $(DEBUG)

all : fowler_august_hw4 

fowler_august_hw4 : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o fowler_august_hw4

fowler_august_hw4.o : fowler_august_hw4.h fowler_august_hw4.cpp grabbag.h
	$(CC) $(CFLAGS) fowler_august_hw4.cpp

grabbag.o : grabbag.h grabbag.cpp
	$(CC) $(CFLAGS) grabbag.cpp
	
clean :
	\rm $(OBJS) fowler_august_hw4

tar :
	tar cfv fowler_august_hw4.tar fowler_august_hw4.cpp fowler_august_hw4.h grabbag.cpp grabbag.h
	
zip :
	zip fowler_august_hw4.zip *.cpp *.h *.mk