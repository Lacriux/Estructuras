CC=g++
OBJECTS=main.o
TARGET=main
CFLAGS=`pkg-config --cflags opencv` `pkg-config --libs opencv`
SOURCE=main.cpp solid.h

$(TARGET):$(OBJECTS)
	$(CC) -o $(TARGET) $(OBJECTS) $(CFLAGS)

$(OBJECTS):$(SOURCE)
	$(CC) -c $(SOURCE) $(CFLAGS)



clean:
	rm -f *.o *~ main *.gch
