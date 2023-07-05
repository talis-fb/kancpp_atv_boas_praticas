CC = g++
CPPFLAGS = -O0 -g -W -Wall -pedantic -std=c++14
SOURCES = $(wildcard src/*.cpp) $(wildcard src/*/*.cpp) $(wildcard src/*/*/*.cpp)
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = bin/main

$(PROG): $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $^ -o $@

%.o: %.cpp
	$(CC) $(CPPFLAGS) -c $< -o $@

clean:
	del src\*.o
	del src\utils\*.o
	del src\TADS\DoublyLinkedList\*.o
	del src\TADS\Set\*.o
	del bin\main.exe

.PHONY: run
run: $(EXECUTABLE)
	./$(EXECUTABLE)