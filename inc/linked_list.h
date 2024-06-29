#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct ListNode {
    int value;
    ListNode* next;
};

class LinkedList {
private:
    int size;
    ListNode* head;

public:
    LinkedList();

    LinkedList(const LinkedList& rhs);

    LinkedList& operator=(const LinkedList& rhs);

    ~LinkedList();

    void clear();

    void insert_after(int idx, int val);

    void push_front(int val);

    void push_back(int val);

    void remove_at(int idx);

    ListNode* pop_front();

    ListNode* pop_back();

    ListNode* front() const;

    bool empty() const;

    int size() const;
};

#endif