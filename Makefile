PROG = run
CC = g++
CPFLAGS = -c
BIN_DIR = ./bin
BUILD_DIR = ./build
INCLUDES_DIR = ./includes
SRC_DIR = ./src
OBJS = 

$(PROG): $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

clean:
	del $(BIN_DIR)/*.o	