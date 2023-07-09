# Compilador a ser usado
CC = g++

# Opções de compilação
CFLAGS = -c -Wall -std=c++11 

# Diretórios de origem dos arquivos .cpp e .h
SRCDIR = src
INCDIR = includes

# Diretórios de destino dos arquivos .o e do executável
OBJDIR = bin
BINDIR = build

# Lista de todos os arquivos .cpp (incluindo subpastas)
SRCS := $(wildcard $(SRCDIR)/*.cpp)

# Gera a lista de nomes dos arquivos .o correspondentes
OBJS := $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SRCS))


# Nome do executável
EXECUTABLE = $(BINDIR)/run

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJS)
	$(CC) $^ -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@if not exist "$(dir $@)" (mkdir "$(dir $@)")
	$(CC) $(CFLAGS) -I$(INCDIR) $< -o $@

clean:
	rmdir /S /Q "$(OBJDIR)" 2>NUL
	del /Q /F "$(EXECUTABLE)" 2>NUL