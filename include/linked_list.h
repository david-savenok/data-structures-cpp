#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct ListNode {
    int val;
    ListNode* next;
};

class LinkedList {
private:
    int size;
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

    ListNode* pop_front();

    ListNode* pop_back();

    ListNode* front() const;

    bool empty() const;

    int size() const;
};

#endif