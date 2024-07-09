CXX = g++
CXXFLAGS = -Iinclude -Wall -Wextra -std=c++17

SRC = $(wildcard tests/*.cpp)
OBJ = $(SRC:.cpp=.o)
TARGET = StaticAnalyzer

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -f $(OBJ) $(TARGET)
