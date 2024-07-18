#include "linked_list.hpp"

LinkedList::LinkedList() : size_val(0), head(nullptr), tail(nullptr) {

}

LinkedList::LinkedList(const LinkedList& rhs) : size_val(0), head(nullptr), tail(nullptr) {
    ListNode* curr = rhs.head;

    while (curr != nullptr) {
        this->append(curr->val);
        curr = curr->next;
    }
}

LinkedList& LinkedList::operator=(const LinkedList& rhs) {
    if (this != &rhs) {
        this->clear();
        ListNode* curr = rhs.head;

        while (curr != nullptr) {
            this->append(curr->val);
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

    if (idx >= size_val) throw std::out_of_range("Index not within list bounds");

    while (curr != nullptr) {
        if (pos == idx) {
            ListNode* new_node = new ListNode{val, curr};
            if (curr == head) {
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

int LinkedList::at(int idx) {
    int pos = 0;
    ListNode* curr = head;

    while (curr != nullptr) {
        if (pos == idx) {
            return curr->val;
        }
        pos++;
        curr = curr->next;
    }
    throw std::out_of_range("ERROR: trying to access out of range index");
}

int LinkedList::pop_front() {
    if (head == nullptr) throw std::runtime_error("ERROR: attempting to pop_front empty list");
    ListNode* temp = head;
    
    if (head == tail) {
        tail = nullptr;
    }
    head = head->next;
    size_val--;
    int temp_val = temp->val;
    delete temp;
    return temp_val;
}

int LinkedList::pop_back() {
    if (head == nullptr) throw std::runtime_error("ERROR: attempting to pop_back empty list");
    ListNode* curr = head;

    if (head == tail) {
        size_val--;
        head = nullptr;
        tail = nullptr;
        int temp_val = curr->val;
        delete curr;
        return temp_val;
    }
    while (curr->next != tail) {
        curr = curr->next;
    }
    curr->next = tail->next;
    ListNode* temp = tail;
    int temp_val = temp->val;
    tail = curr;
    size_val--;
    delete temp;
    return temp_val;
}

int LinkedList::front() const {
    if (head == nullptr) throw std::runtime_error("ERROR: attempting to access front of empty list");
    return head->val;
}

int LinkedList::back() const {
    if (tail == nullptr) throw std::runtime_error("ERROR: attempting to access back of empty list");
    return tail->val;
}

bool LinkedList::empty() const {
    if (size_val == 0) return true;
    return false;
}

int LinkedList::size() const {
    return size_val;
}