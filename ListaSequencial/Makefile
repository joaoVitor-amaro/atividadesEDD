# Compilador
CXX = g++
CXXFLAGS = -Wall -std=c++17

# Arquivos-fonte
SRC = main.cpp ListaSequencial.cpp

# Arquivo final
TARGET = programa

# Regra padrão
all: $(TARGET)

# Como compilar o programa
$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Limpar arquivos antigos
clean:
	rm -f $(TARGET)
