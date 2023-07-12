CC = g++
CFLAGS = -c -Wall -std=c++17 -g 
SRCDIR = src
INCDIR = includes
OBJDIR = bin
BINDIR = build
SRCS := $(wildcard $(SRCDIR)/*.cpp) $(wildcard $(SRCDIR)/*/*.cpp)
OBJS := $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SRCS))
EXECUTABLE = $(BINDIR)/run

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJS)
	@if not exist "$(BINDIR)" (mkdir "$(BINDIR)")
	$(CC) $^ -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@if not exist "$(dir $@)" (mkdir "$(dir $@)")
	$(CC) $(CFLAGS) -I$(INCDIR) $< -o $@

run: $(EXECUTABLE)
	$(EXECUTABLE)

clean:
	del /Q /F "$(OBJDIR)\*" 2>NUL
	del /Q /F "$(EXECUTABLE)" 2>NUL
