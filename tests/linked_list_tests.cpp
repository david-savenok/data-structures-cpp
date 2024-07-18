#include "catch.hpp"
#include "linked_list.hpp"

TEST_CASE("testing default constructor", "[constructor]") {
    LinkedList list = LinkedList();

    REQUIRE(list.size() == 0);
    REQUIRE_THROWS(list.back());
    REQUIRE_THROWS(list.front());
}

TEST_CASE("testing size method", "[size]") {
    LinkedList list = LinkedList();

    REQUIRE(list.size() == 0);

    list.append(0);
    REQUIRE(list.size() == 1);

    list.append(1);
    REQUIRE(list.size() == 2);
}

TEST_CASE("testing empty method", "[empty]") {
    LinkedList list = LinkedList();

    REQUIRE(list.empty() == true);

    list.append(0);
    REQUIRE(list.empty() == false);

    list.remove(0);
    REQUIRE(list.empty() == true);
}

TEST_CASE("testing back method", "[back]") {
    LinkedList list = LinkedList();

    list.append(0);
    REQUIRE(list.back() == 0);

    list.append(1);
    REQUIRE(list.back() == 1);

    list.remove(1);
    REQUIRE(list.back() == 0);
}

TEST_CASE("testing front method", "[front]") {
    LinkedList list = LinkedList();

    list.append(0);
    REQUIRE(list.front() == 0);

    list.append(1);
    REQUIRE(list.front() == 0);

    list.remove(0);
    REQUIRE(list.front() == 1);
}

TEST_CASE("testing append method", "[append]") {
    LinkedList list = LinkedList();

    list.append(0);
    REQUIRE(list.size() == 1);
    REQUIRE(list.back() == 0);
    REQUIRE(list.front() == 0);
    // 0

    list.append(1);
    REQUIRE(list.size() == 2);
    REQUIRE(list.back() == 1);
    REQUIRE(list.front() == 0);
    // 0 -> 1

    list.remove(0);
    REQUIRE(list.size() == 1);
    REQUIRE(list.back() == 1);
    // 1

    list.append(2);
    REQUIRE(list.size() == 2);
    REQUIRE(list.back() == 2);
    REQUIRE(list.front() == 1);
    // 1 -> 2
}

TEST_CASE("testing prepend method", "[prepend]") {
    LinkedList list = LinkedList();

    list.prepend(0);
    REQUIRE(list.size() == 1);
    REQUIRE(list.back() == 0);
    REQUIRE(list.front() == 0);
    // 0

    list.prepend(1);
    REQUIRE(list.size() == 2);
    REQUIRE(list.front() == 1);
    REQUIRE(list.back() == 0);
    // 1 -> 0

    list.remove(0);
    REQUIRE(list.size() == 1);
    REQUIRE(list.front() == 0);
    REQUIRE(list.back() == 0);
    // 0

    list.prepend(2);
    REQUIRE(list.size() == 2);
    REQUIRE(list.front() == 2);
    REQUIRE(list.back() == 0);
    // 2 -> 0
}

TEST_CASE("testing pop_front method", "[pop_front]") {
    LinkedList list = LinkedList();

    list.append(0);
    list.append(1);
    list.append(2);
    list.append(3);
    // 0 -> 1 -> 2 -> 3

    REQUIRE(list.size() == 4);

    REQUIRE(list.pop_front() == 0);
    REQUIRE(list.size() == 3);
    REQUIRE(list.front() == 1);
    REQUIRE(list.back() == 3);
    // 1 -> 2 -> 3

    REQUIRE(list.pop_front() == 1);
    REQUIRE(list.size() == 2);
    REQUIRE(list.front() == 2);
    REQUIRE(list.back() == 3);
    // 2 -> 3

    REQUIRE(list.pop_front() == 2);
    REQUIRE(list.size() == 1);
    REQUIRE(list.front() == 3);
    REQUIRE(list.back() == 3);
    // 3

    REQUIRE(list.pop_front()== 3);
    REQUIRE(list.size() == 0);
    REQUIRE_THROWS(list.front());
    REQUIRE_THROWS(list.back());

    REQUIRE_THROWS(list.pop_front());
    REQUIRE(list.size() == 0);
    REQUIRE_THROWS(list.front());
    REQUIRE_THROWS(list.back());
}

TEST_CASE("testing pop_back method", "[pop_back]") {
    LinkedList list = LinkedList();

    list.append(0);
    list.append(1);
    list.append(2);
    list.append(3);
    // 0 -> 1 -> 2 -> 3

    REQUIRE(list.size() == 4);

    REQUIRE(list.pop_back() == 3);
    REQUIRE(list.size() == 3);
    REQUIRE(list.front() == 0);
    REQUIRE(list.back() == 2);
    // 0 -> 1 -> 2

    REQUIRE(list.pop_back() == 2);
    REQUIRE(list.size() == 2);
    REQUIRE(list.front() == 0);
    REQUIRE(list.back() == 1);
    // 0 -> 1

    REQUIRE(list.pop_back() == 1);
    REQUIRE(list.size() == 1);
    REQUIRE(list.front() == 0);
    REQUIRE(list.back() == 0);
    // 0

    REQUIRE(list.pop_back() == 0);
    REQUIRE(list.size() == 0);
    REQUIRE_THROWS(list.front());
    REQUIRE_THROWS(list.back());

    REQUIRE_THROWS(list.pop_back());
    REQUIRE(list.size() == 0);
    REQUIRE_THROWS(list.front());
    REQUIRE_THROWS(list.back());
}

TEST_CASE("testing at method", "[at]") {
    LinkedList list = LinkedList();

    list.append(0);
    list.append(1);
    list.append(2);
    list.append(3);

    REQUIRE(list.at(0) == 0);
    REQUIRE(list.at(1) == 1);
    REQUIRE(list.at(2) == 2);
    REQUIRE(list.at(3) == 3);
    REQUIRE(list.size() == 4);
}

TEST_CASE("testing remove method", "[remove]") {
    LinkedList list = LinkedList();

    list.append(0);
    list.append(1);
    list.append(2);
    list.append(3);
    list.append(4);
    list.append(5);
    // 0 -> 1 -> 2 -> 3 -> 4 -> 5

    list.remove(2);
    REQUIRE(list.size() == 5);
    REQUIRE(list.at(2) == 3);
    // 0 -> 1 -> 3 -> 4 -> 5

    list.remove(0);
    REQUIRE(list.size() == 4);
    REQUIRE(list.at(0) == 1);
    REQUIRE(list.front() == 1);
    REQUIRE(list.back() == 5);
    // 1 -> 3 -> 4 -> 5

    list.remove(3);
    REQUIRE(list.size() == 3);
    REQUIRE(list.at(2) == 4);
    REQUIRE(list.back() == 4);
    REQUIRE(list.front() == 1);
    // 1 -> 3 -> 4

    list.remove(0);
    REQUIRE(list.size() == 2);
    REQUIRE(list.at(0) == 3);
    REQUIRE(list.back() == 4);
    REQUIRE(list.front() == 3);
    // 3 -> 4

    list.remove(1);
    REQUIRE(list.size() == 1);
    REQUIRE(list.at(0) == 3);
    REQUIRE(list.front() == 3);
    REQUIRE(list.back() == 3);
    // 3

    list.remove(0);
    REQUIRE(list.size() == 0);
    REQUIRE_THROWS(list.at(0));
    REQUIRE_THROWS(list.back());
    REQUIRE_THROWS(list.front());
}

TEST_CASE("testing insert method", "[insert]") {
    LinkedList list = LinkedList();

    REQUIRE_THROWS(list.insert(0, 0));
    REQUIRE(list.size() == 0);
    REQUIRE_THROWS(list.front());

    list.append(0);
    REQUIRE_THROWS(list.insert(1, 1));
    REQUIRE(list.size() == 1);
    REQUIRE(list.front() == 0);
    REQUIRE(list.back() == 0);
    // 0

    list.insert(0, -1);
    REQUIRE(list.size() == 2);
    REQUIRE(list.front() == -1);
    REQUIRE(list.back() == 0);
    // -1 -> 0

    list.insert(1, 2);
    REQUIRE(list.size() == 3);
    REQUIRE(list.at(1) == 2);
    REQUIRE(list.front() == -1);
    REQUIRE(list.back() == 0);
    // -1 -> 2 -> 0

    list.insert(1, 3);
    REQUIRE(list.size() == 4);
    REQUIRE(list.at(2) == 2);
    REQUIRE(list.at(1) == 3);
    REQUIRE(list.front() == -1);
    REQUIRE(list.back() == 0);
    // -1 -> 3 -> 2 -> 0

    REQUIRE_THROWS(list.insert(5, 5));
    REQUIRE_THROWS(list.insert(4, 4));
    REQUIRE(list.size() == 4);
    REQUIRE(list.back() == 0);
}

TEST_CASE("testing clear method", "[clear]") {
    LinkedList list = LinkedList();

    list.append(0);
    list.append(1);
    list.append(2);
    list.append(3);

    list.clear();
    REQUIRE(list.size() == 0);
    REQUIRE_THROWS(list.front());
    REQUIRE_THROWS(list.back());
}

TEST_CASE("testing copy assignment operator", "[copy_assignment]") {
    LinkedList list = LinkedList();

    list.append(0);
    list.append(1);

    LinkedList list_copy = LinkedList();
    list_copy = list;

    REQUIRE(list_copy.size() == list.size());
    REQUIRE(list_copy.front() == list.front());
    REQUIRE(list_copy.back() == list.back());
    REQUIRE(list_copy.at(0) == list.at(0));
    REQUIRE(list_copy.at(1) == list.at(1));
}

TEST_CASE("testing copy constructor", "[copy_constructor]") {
    LinkedList list = LinkedList();

    list.append(0);
    list.append(1);

    LinkedList list_copy(list);

    REQUIRE(list_copy.size() == list.size());
    REQUIRE(list_copy.front() == list.front());
    REQUIRE(list_copy.back() == list.back());
    REQUIRE(list_copy.at(0) == list.at(0));
    REQUIRE(list_copy.at(1) == list.at(1));
}
