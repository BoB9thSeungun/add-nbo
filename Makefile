CC = g++
TARGET = add-nbo

$(TARGET): main.o addnbo.o
	$(CC) -s -o $(TARGET) main.o addnbo.o

main.o: main.cpp addnbo.hpp
	$(CC) -c -o main.o main.cpp

addnbo.o: addnbo.cpp addnbo.hpp
	$(CC) -c -o addnbo.o addnbo.cpp

clean:
	rm *.o add-nbo
