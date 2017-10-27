
OBJS = main.o
CC = g++
DEBUG = -g
#CFLAGS =  -c 
#LFLAGS = -Wall 
CFLAGS = -Wall -c $(DEBUG) --pedantic
LFLAGS = -Wall $(DEBUG) --pedantic
TARGET = main

$(TARGET) : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $(TARGET)
	
main.o : AVLTree.h main.cpp
	$(CC) $(CFLAGS) main.cpp
	
clean:
	\rm *.o $(TARGET)