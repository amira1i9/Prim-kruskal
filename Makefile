CXX := g++
CXXFLAGS := -Wall -Wextra -Werror -Wextra -pedantic -std=c++23 -O3 -march=native

TARGET := main

SRC := src/main.cpp src/utils.cpp src/disjoint_set.cpp
OBJ := $(SRC:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f $(TARGET) $(OBJ)
