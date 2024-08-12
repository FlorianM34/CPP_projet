
# Nom de l'exécutable
TARGET = monProgramme

# Compilateur
CXX = g++

# Options de compilation
CXXFLAGS = -std=c++11 -Wall

# Fichiers source
SRCS = main.cpp Personne.cpp

# Fichiers objets
OBJS = $(SRCS:.cpp=.o)

# Règle par défaut
all: $(TARGET)

# Règle pour créer l'exécutable
$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)

# Règle pour compiler les fichiers .cpp en .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Règle pour nettoyer les fichiers objets et l'exécutable
clean:
	rm -f $(OBJS) $(TARGET)
