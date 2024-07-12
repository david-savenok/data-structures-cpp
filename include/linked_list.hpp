#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <stdexcept>

struct ListNode {
    int val;
    ListNode* next;
};

class LinkedList {
private:
    int size_val;
    ListNode* head;
    ListNode* tail;

public:
    LinkedList();

    LinkedList(const LinkedList& rhs);

    LinkedList& operator=(const LinkedList& rhs);

    ~LinkedList();

    void clear();

    void insert(int idx, int val);

    void prepend(int val);

    void append(int val);

    void remove(int idx);

    int at(int idx);

    int pop_front();

    int pop_back();

    int front() const;

    int back() const;

    bool empty() const;

    int size() const;
};

#endif