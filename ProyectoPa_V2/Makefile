CC = g++
CFLAGS = -std=c++20 -Wall

BIN_DIR = bin
TARGET = $(BIN_DIR)/main

# Lista de todos los archivos fuente .cpp
SRCS := $(wildcard *.cpp)

# Lista de todos los archivos de encabezado .h
HDRS := $(wildcard *.h)

# Lista de todos los archivos objeto generados a partir de los archivos fuente
OBJS := $(SRCS:%.cpp=%.o)

.PHONY: all clean run force_build zip

all: $(TARGET)

$(TARGET): $(OBJS)
	mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $^

# Regla genérica para compilar cada archivo fuente a un archivo objeto
%.o: %.cpp $(HDRS)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf $(BIN_DIR) $(OBJS)

force_build:
	@$(MAKE) clean
	@$(MAKE) all

run: force_build
	./$(TARGET)

zip:
	zip -r $(notdir $(CURDIR)).zip . -x "bin/*"
