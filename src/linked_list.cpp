#include "inc/linked_list.h"

LinkedList::LinkedList() {
    size = 0;
    head = nullptr;
    tail = nullptr;
}

LinkedList::LinkedList(const LinkedList& rhs) {

}

LinkedList& LinkedList::operator=(const LinkedList& rhs) {

}

LinkedList::~LinkedList() {

}

void LinkedList::clear() {

}

void LinkedList::insert(int idx, int val) {

}

void LinkedList::prepend(int val) {
    ListNode* new_node = new ListNode{val, head};

    if (head == nullptr) {
        tail = new_node;
    }
    head = new_node;
    size++; 
}

void LinkedList::append(int val) {
    ListNode* new_node = new ListNode{val, nullptr};
    
    if (head == nullptr) {
        head = new_node;
    }
    else {
        tail->next = new_node;
    }
    tail = new_node;
    size++;
}

void LinkedList::remove(int idx) {

}

ListNode* LinkedList::pop_front() {

}

ListNode* LinkedList::pop_back() {

}

ListNode* LinkedList::front() const {

}

bool LinkedList::empty() const {

}

int LinkedList::size() const {

}