CXX=clang++
CPPFLAGS=-pedantic -Wall -Wextra -std=c++17 -I

OBJECTS = main.cc bst.cc node.cc repl.cc

trees: $(OBJECTS)
	$(CXX) -o $@ $^

