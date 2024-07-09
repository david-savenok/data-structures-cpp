#include "../include/linked_list.hpp"

LinkedList::LinkedList() : size_val(0), head(nullptr), tail(nullptr) {

}

LinkedList::LinkedList(const LinkedList& rhs) : size_val(0), head(nullptr), tail(nullptr) {
    ListNode* curr = rhs.head;

    while (curr != nullptr) {
        this->append(curr.val);
        curr = curr->next;
    }
}

LinkedList& LinkedList::operator=(const LinkedList& rhs) {
    if (this != &rhs) {
        this->clear();
        ListNode* curr = rhs.head;

        while (curr != nullptr) {
            this->append(curr.val);
            curr = curr->next;
        }
    }
    return *this;
}

LinkedList::~LinkedList() {
    this->clear();
}

void LinkedList::clear() {
    ListNode* curr = head;
    ListNode* prev = nullptr;
    while (curr != nullptr) {
        prev = curr;
        curr = curr->next;
        delete prev;
    }
    size_val = 0;
    head = nullptr;
    tail = nullptr;
}

void LinkedList::insert(int idx, int val) {
    int pos = 0;
    ListNode* curr = head;
    ListNode* prev = nullptr;

    while (curr != nullptr) {
        if (pos == idx) {
            ListNode* new_node = new ListNode{val, curr};
            if (curr == head) {
                if (curr == tail) {
                    tail = new_node;
                }
                head = new_node;
                size_val++;
                return;
            }
            prev->next = new_node;
            size_val++;
        }
        pos++;
        prev = curr;
        curr = curr->next;
    }
}

void LinkedList::prepend(int val) {
    ListNode* new_node = new ListNode{val, head};

    if (head == nullptr) {
        tail = new_node;
    }
    head = new_node;
    size_val++; 
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
    size_val++;
}

void LinkedList::remove(int idx) {
    int pos = 0;
    ListNode* curr = head;
    ListNode* prev = nullptr;

    while (curr != nullptr) {
        if (pos == idx) {
            if (curr == head) {
                ListNode* temp = head->next;
                if (curr == tail) {
                    tail = temp;
                }
                delete head;
                head = temp;
                size_val--;
                return;
            }
            
            prev->next = curr->next;
            if (curr == tail) {
                tail = prev;
            }
            delete curr;
            size_val--;
            return;
        }
        pos++;
        prev = curr;
        curr = curr->next;
    }
}

ListNode* LinkedList::pop_front() {
    if (head == nullptr) return nullptr;
    ListNode* temp = head;
    
    if (head == tail) {
        tail = nullptr;
    }
    head = head->next;
    size_val--;
    return temp;
}

ListNode* LinkedList::pop_back() {
    if (head == nullptr) return nullptr;
    ListNode* temp = head;

    if (head == tail) {
        size_val--;
        head = nullptr;
        tail = nullptr;
        return temp;
    }
    while (temp->next != tail) {
        temp = temp->next;
    }
    temp->next = tail->next;
    return tail;
}

ListNode* LinkedList::front() const {
    return head;
}

ListNode* LinkedList::back() const {
    return tail;
}

bool LinkedList::empty() const {
    if (size == 0) return true;
    return false;
}

int LinkedList::size() const {
    return size_val;
}