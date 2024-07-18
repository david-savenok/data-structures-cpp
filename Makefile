CXX=clang++
CXX_FLAGS=-std=c++20 -Iinclude -Itests -Wall -fstandalone-debug -fsanitize=address,null -fno-omit-frame-pointer -O0 -gdwarf-4

linked_list_tests: 
	$(CXX) $(CXX_FLAGS) ./tests/test.cpp ./src/linked_list.cpp ./tests/linked_list_tests.cpp -o bin/linked_list_tests

bst_tests:
	$(CXX) $(CXX_FLAGS) ./tests/test.cpp ./src/binary_search_tree.cpp ./tests/bst_tests.cpp -o bin/bst_tests

.PHONY: clean

clean:
	rm -rf bin/*
