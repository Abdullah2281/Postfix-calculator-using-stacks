#include "stack_c.h"
#include <stdexcept>
#include<iostream>
using namespace std;

Stack_C::Stack_C() {
    stk = new List();
}

Stack_C::~Stack_C() {
    delete stk;
}

void Stack_C::push(int data) {
    try {
        stk->insert(data);
    }
    catch (const std::bad_alloc& e) {
        throw std::runtime_error("Out of Memory");
    }
}

int Stack_C::pop() {
    if(stk -> get_size() > 0) {
        return stk->delete_tail();
    }
    else {
        throw std::runtime_error("Empty Stack");
    }
}


int Stack_C::get_element_from_top(int idx) {
    if (idx >= 0 && idx < stk->get_size()) {
        Node* current = stk->get_head()->next;
        int count = 0;
        int ans = 0;
        int final_idx = stk->get_size() - idx - 1;
        while (!current->is_sentinel_node()) {
            if (count == final_idx) {
                ans = current->get_value();
                break;
            }
            current = current->next;
            count++;
        }
        return ans;
    } else {
        throw std::runtime_error("Index out of range");
    }
    return 0;
}

int Stack_C::get_element_from_bottom(int idx) {
    if (idx >= 0 && idx < stk->get_size()) {
        Node* current = stk->get_head()->next;
        int count = 0;
        int ans = 0;
        while (!current->is_sentinel_node()) {
            if (count == idx) {
                ans = current->get_value();
                break; 
            }
            current = current->next;
            count++;
        }
        return ans;
    } else {
        throw std::runtime_error("Index out of range");
    }
    return 0;
}



void Stack_C::print_stack(bool top_or_bottom) {
    Node* current;
    if (top_or_bottom) {
        current = stk->get_head()->next;
        while (!current->is_sentinel_node()) {
            current = current->next;
        }
        Node* temp = current -> prev;
        while (!temp->is_sentinel_node()) {
            std::cout << temp->get_value() << std::endl;
            temp = temp->prev;
        }
    } 
    else {
        current = stk->get_head()->next;
        while (!current->is_sentinel_node()) {
            std::cout << current->get_value() << std::endl;
            current = current->next;
        }
    }
}


int Stack_C::add() {
    if (stk->get_size() < 2) {
        throw std::runtime_error("Not Enough Arguments");
    }
    int a1 = pop();
    int a2 = pop();
    int result = a1+a2;
    push(result);
    return result;
}

int Stack_C::subtract() {
    if (stk->get_size() < 2) {
        throw std::runtime_error("Not Enough Arguments");
    }
    int a1 = pop();
    int a2 = pop();
    int result = a2-a1;
    push(result);
    return result;
}

int Stack_C::multiply() {
    if (stk->get_size() < 2) {
        throw std::runtime_error("Not Enough Arguments");
    }
    int a1 = pop();
    int a2 = pop();
    int result = a1*a2;
    push(result);
    return result;
}

int Stack_C::divide() {
    if (stk->get_size() < 2) {
        throw std::runtime_error("Not Enough Arguments");
    }
        int a1 = pop();
        int a2 = pop();
    if(a1 == 0) {
        throw std::runtime_error("Divide by Zero Error");
    }
    else if(a2 == 0) {
        int ans = 0;
        push(ans);
        return ans;
    }
    else if((a2<0 && a1>0) || (a2>0 && a1<0)) {
        int ans = a2/a1;
        if(ans == 0) {
            push(-1);
            return -1;
        }
        else {
            push(ans-1);
            return ans-1;
        }
    }
    else {
        int ans = a2/a1;
        push(ans);
        return ans;
    }
}

List* Stack_C::get_stack() {
    return stk;
}

int Stack_C::get_size() {
    return stk->get_size();
}