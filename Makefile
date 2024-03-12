CXX := g++
CXXFLAGS := -Wall -Wextra -Werror -Wextra -pedantic -std=c++23 -O3 -march=native

TAREGET := main

SRC := src/main.cpp src/utils.cpp src/disjoint_set.cpp
OBJ := $(SRC:.cpp=.o)

all: $(TAREGET)

$(TAREGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f $(TAREGET) $(OBJ)