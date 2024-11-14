# Variables
CXX = g++
CXXFLAGS = -Wall -std=c++11 -Iinclude
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

# Dossiers
SRC_DIR = src
OBJ_DIR = build
BIN_DIR = bin

# Fichiers source et objets
SRC = $(SRC_DIR)/main.cpp $(SRC_DIR)/Game.cpp $(SRC_DIR)/Bird.cpp $(SRC_DIR)/Pipe.cpp $(SRC_DIR)/PipeManager.cpp $(SRC_DIR)/Score.cpp $(SRC_DIR)/Background.cpp $(SRC_DIR)/CollisionManager.cpp
OBJ = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC))

# Cible principale
all: $(BIN_DIR)/flappybird

# Règle pour compiler l'exécutable
$(BIN_DIR)/flappybird: $(OBJ)
	mkdir -p $(BIN_DIR)
	$(CXX) -o $(BIN_DIR)/flappybird $(OBJ) $(LDFLAGS)

# Règle pour compiler les fichiers objets
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Règle pour nettoyer les fichiers compilés
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)