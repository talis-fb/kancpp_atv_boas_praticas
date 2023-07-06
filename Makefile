CC = g++
CPPFLAGS = -O0 -g -W -Wall -pedantic -std=c++14
SRCDIR = src
OBJDIR = bin
BINDIR = build
SOURCES = $(wildcard $(SRCDIR)/*.cpp)
OBJECTS = $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SOURCES))
EXECUTABLE = $(BINDIR)\run

# Commands
RM = del 

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJDIR)\main.o
	$(RM) $(OBJDIR)\Column.o
	$(RM) $(OBJDIR)\Board.o
	$(RM) $(OBJDIR)\Admin.o
	$(RM) $(OBJDIR)\User.o
	$(RM) $(OBJDIR)\Member.o
	$(RM) $(OBJDIR)\Task.o
	$(RM) $(EXECUTABLE)