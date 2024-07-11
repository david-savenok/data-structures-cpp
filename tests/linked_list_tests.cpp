#include "catch.hpp"
#include "../include/linked_list.hpp"

TEST_CASE("testing default constructor", "[constructor]") {
    LinkedList list = LinkedList();

    REQUIRE(list.size() == 0);
    REQUIRE(list.back() == nullptr);
    REQUIRE(list.front() == nullptr);
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
    REQUIRE(list.back()->val == 0);

    list.append(1);
    REQUIRE(list.back()->val == 1);

    list.remove(1);
    REQUIRE(list.back()->val == 0);
}

TEST_CASE("testing front method", "[front]") {
    LinkedList list = LinkedList();

    list.append(0);
    REQUIRE(list.front()->val == 0);

    list.append(1);
    REQUIRE(list.front()->val == 0);

    list.remove(0);
    REQUIRE(list.front()->val == 1);
}

TEST_CASE("testing append method", "[append]") {
    LinkedList list = LinkedList();

    list.append(0);
    REQUIRE(list.size() == 1);
    REQUIRE(list.back()->val == 0);
    REQUIRE(list.front()->val == 0);

    list.append(1);
    REQUIRE(list.size() == 2);
    REQUIRE(list.back()->val == 1);
    REQUIRE(list.front()->val == 0);

    list.remove(0);
    REQUIRE(list.size() == 1);
    REQUIRE(list.back()->val == 1);

    list.append(2);
    REQUIRE(list.size() == 2);
    REQUIRE(list.back()->val == 2);
}

TEST_CASE("testing prepend method", "[prepend]") {
    LinkedList list = LinkedList();

    list.prepend(0);
    REQUIRE(list.size() == 1);
    REQUIRE(list.back()->val == 0);
    REQUIRE(list.front()->val == 0);

    list.prepend(1);
    REQUIRE(list.size() == 2);
    REQUIRE(list.front()->val == 1);
    REQUIRE(list.back()->val == 0);

    list.remove(0);
    REQUIRE(list.size() == 1);
    REQUIRE(list.front()->val == 0);
    REQUIRE(list.back()->val == 0);

    list.prepend(2);
    REQUIRE(list.size() == 2);
    REQUIRE(list.front()->val == 2);
    REQUIRE(list.back()->val == 0);
}

TEST_CASE("testing pop_front method", "[pop_front]") {
    LinkedList list = LinkedList();

    list.append(0);
    list.append(1);
    list.append(2);
    list.append(3);

    REQUIRE(list.size() == 4);

    REQUIRE(list.pop_front()->val == 0);
    REQUIRE(list.size() == 3);
    REQUIRE(list.front()->val == 1);
    REQUIRE(list.back()->val == 3);

    REQUIRE(list.pop_front()->val == 1);
    REQUIRE(list.size() == 2);
    REQUIRE(list.front()->val == 2);
    REQUIRE(list.back()->val == 3);

    REQUIRE(list.pop_front()->val == 2);
    REQUIRE(list.size() == 1);
    REQUIRE(list.front()->val == 3);
    REQUIRE(list.back()->val == 3);

    REQUIRE(list.pop_front()->val == 3);
    REQUIRE(list.size() == 0);
    REQUIRE(list.front() == nullptr);
    REQUIRE(list.back() == nullptr);

    REQUIRE(list.pop_front() == nullptr);
    REQUIRE(list.size() == 0);
    REQUIRE(list.front() == nullptr);
    REQUIRE(list.back() == nullptr);
}

TEST_CASE("testing pop_back method", "[pop_back]") {
    LinkedList list = LinkedList();

    list.append(0);
    list.append(1);
    list.append(2);
    list.append(3);

    REQUIRE(list.size() == 4);

    REQUIRE(list.pop_back()->val == 3);
    REQUIRE(list.size() == 3);
    REQUIRE(list.front()->val == 0);
    REQUIRE(list.back()->val == 2);

    REQUIRE(list.pop_back()->val == 2);
    REQUIRE(list.size() == 2);
    REQUIRE(list.front()->val == 0);
    REQUIRE(list.back()->val == 1);

    REQUIRE(list.pop_back()->val == 1);
    REQUIRE(list.size() == 1);
    REQUIRE(list.front()->val == 0);
    REQUIRE(list.back()->val == 0);

    REQUIRE(list.pop_back()->val == 0);
    REQUIRE(list.size() == 0);
    REQUIRE(list.front() == nullptr);
    REQUIRE(list.back() == nullptr);

    REQUIRE(list.pop_back() == nullptr);
    REQUIRE(list.size() == 0);
    REQUIRE(list.front() == nullptr);
    REQUIRE(list.back() == nullptr);
}

TEST_CASE("testing at method", "[at]") {
    LinkedList list = LinkedList();

    list.append(0);
    list.append(1);
    list.append(2);
    list.append(3);

    REQUIRE(list.at(0)->val == 0);
    REQUIRE(list.at(1)->val == 1);
    REQUIRE(list.at(2)->val == 2);
    REQUIRE(list.at(3)->val == 3);
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

    list.remove(2);
    REQUIRE(list.size() == 5);
    REQUIRE(list.at(2)->val == 3);

    list.remove(0);
    REQUIRE(list.size() == 4);
    REQUIRE(list.at(0)->val == 1);
    REQUIRE(list.front()->val == 1);
    REQUIRE(list.back()->val == 5);

    list.remove(3);
    REQUIRE(list.size() == 3);
    REQUIRE(list.at(2)->val == 4);
    REQUIRE(list.back()->val == 4);
    REQUIRE(list.front()->val == 1);

    list.remove(0);
    REQUIRE(list.size() == 2);
    REQUIRE(list.at(0)->val == 3);
    REQUIRE(list.back()->val == 4);
    REQUIRE(list.front()->val == 3);

    list.remove(1);
    REQUIRE(list.size() == 1);
    REQUIRE(list.at(0)->val == 3);
    REQUIRE(list.front()->val == 3);
    REQUIRE(list.back()->val == 3);

    list.remove(0);
    REQUIRE(list.size() == 0);
    REQUIRE(list.at(0) == nullptr);
    REQUIRE(list.back() == nullptr);
    REQUIRE(list.front() == nullptr);
}