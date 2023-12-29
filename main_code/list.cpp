#include "list.h"
#include<iostream>
#include<stdexcept>
using namespace std;
List::List() {
    sentinel_head = new Node(true);
    sentinel_tail = new Node(true);
    size = 0;
    sentinel_head->next = sentinel_tail;
    sentinel_tail->prev = sentinel_head;
}

List::~List() {
    Node* current = sentinel_head->next;
    while (current != sentinel_tail) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
    delete sentinel_head;
    delete sentinel_tail;
}

void List::insert(int v) {
    Node* newNode = new Node(v, sentinel_tail, sentinel_tail->prev);
    sentinel_tail->prev->next = newNode;
    sentinel_tail->prev = newNode;
    size++;
}

int List::delete_tail() {
    if (size > 0) {
        Node* tail = sentinel_tail->prev;
        int value = tail->get_value();
        tail->prev->next = sentinel_tail;
        sentinel_tail->prev = tail->prev;
        delete tail;
        size--;
        return value;
    } else {
        throw std::runtime_error("Empty List");
    }
}

int List::get_size() {
    return size;
}

Node* List::get_head() {
    return sentinel_head;
}