CXX = g++

CXXFLAGS = -std=c++98 -Wall -g -O2

# BIN_DIR = bin  <-- Remove or comment out this line
BIN_DIR =

INCLUDE_DIR = lab4/include
SRC_DIR = lab4/src
OBJ_DIR = obj

SOURCES := $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SOURCES))

# TARGET = $(BIN_DIR)/main <-- Change this line
TARGET = main

# --- Reglas de Compilación ---

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

# --- Reglas de Limpieza y Ejecución ---

.PHONY: all clean run
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR) 

run: all
	./$(TARGET) 