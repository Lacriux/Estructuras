CC=g++
OBJECTS=djp.o
TARGET=main
SOURCE=djp.cpp djp.h

$(TARGET):$(OBJECTS)
	$(CC) -o $(TARGET) $(OBJECTS)

$(OBJECTS):$(SOURCE)
	$(CC) -c $(SOURCE)



clean:
	rm -f *.o *~ main *.gch
