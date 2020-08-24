CXX=clang++
CPPFLAGS=-pedantic -Wall -Wextra -Wno-unused-variable -std=c++17 -I

OBJECTS = main.cc bst.cc node.cc repl_bst.cc repl_linkedlist.cc repl.cc linkedlist.cc

trees: $(OBJECTS)
	$(CXX) -o $@ $^

