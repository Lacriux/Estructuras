OBJS = principal3.cpp base.o cola2.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG) --pedantic
LFLAGS = -Wall $(DEBUG) --pedantic
TARGET = principal3

$(TARGET) : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $(TARGET)
	
cola2.o : base.h cola2.h cola2.cpp
	$(CC) $(CFLAGS) cola2.cpp	

base.o : base.h base.cpp
	$(CC) $(CFLAGS) base.cpp
	
clean:
	\rm *.o $(TARGET)