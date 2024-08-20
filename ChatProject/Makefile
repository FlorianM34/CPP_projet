# Nom du compilateur
CXX = g++

# Options de compilation
CXXFLAGS = -std=c++11 -Wall -ggdb -O0

# Fichiers source pour chaque programme
CLIENT_SRC = mainClient.cpp User.cpp Room.cpp Message.cpp 
SERVER_SRC = mainServer.cpp Server.cpp Room.cpp User.cpp Message.cpp

# Fichiers objets
CLIENT_OBJ = $(CLIENT_SRC:.cpp=.o)
SERVER_OBJ = $(SERVER_SRC:.cpp=.o)

# Noms des exécutables
CLIENT_TARGET = mainClient
SERVER_TARGET = mainServer

# Règle par défaut : compile les deux exécutables
all: $(CLIENT_TARGET) $(SERVER_TARGET)

# Compilation du programme client
$(CLIENT_TARGET): $(CLIENT_OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compilation du programme serveur
$(SERVER_TARGET): $(SERVER_OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Règle pour nettoyer les fichiers objets et les exécutables
clean:
	rm -f $(CLIENT_OBJ) $(SERVER_OBJ) $(CLIENT_TARGET) $(SERVER_TARGET)
