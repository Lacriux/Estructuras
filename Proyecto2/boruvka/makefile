CC=g++
OBJECTS=boruvka.o
TARGET=main
SOURCE=boruvka.cpp boruvka.h

$(TARGET):$(OBJECTS)
	$(CC) -o $(TARGET) $(OBJECTS)

$(OBJECTS):$(SOURCE)
	$(CC) -c $(SOURCE)

clean:
	rm -f *.o *~ main *.gch
