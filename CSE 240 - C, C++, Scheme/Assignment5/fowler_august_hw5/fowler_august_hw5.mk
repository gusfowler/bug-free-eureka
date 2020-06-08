OBJS = fowler_august_hw5.o 
CODE = fowler_august_hw5.cpp fowler_august_hw5.h bst.h
CC = g++ 
DEBUG = -g
COMPFLAGS := -std=c++11
CFLAGS = $(COMPFLAGS) -Wall -c $(DEBUG)
LFLAGS = $(COMPFLAGS) -Wall $(DEBUG)

all : fowler_august_hw5

fowler_august_hw5 : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o fowler_august_hw5

fowler_august_hw5.o : $(CODE)
	$(CC) $(CFLAGS) fowler_august_hw5.cpp
	
clean :
	\rm $(OBJS) fowler_august_hw5 

tar :
	tar cfv fowler_august_hw5.tar *.cpp *.h *.mk
	
zip :
	zip fowler_august_hw5.zip *.cpp *.h *.mk *.txt
