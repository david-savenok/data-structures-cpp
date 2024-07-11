CXX=clang++
CXX_FLAGS=-std=c++20 -Iincludes -Itests -Wall -Wextra -Werror -O0 -gdwarf-4 -fsanitize=address

linked_list_tests: 
	$(CXX) $(CXX_FLAGS) ./tests/test.cpp ./src/linked_list.cpp ./tests/linked_list_tests.cpp -o bin/linked_list_tests

.PHONY: clean

clean:
	rm -rf bin/*
