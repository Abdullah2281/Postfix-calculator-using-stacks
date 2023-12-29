#include<iostream>
#include "stack_a.h"
#include<stdexcept>
using namespace std;

Stack_A::Stack_A() {
    int top = -1;
    size = 0;
}

void Stack_A::push(int data) {
    if (size < 1024) {
        stk[size] = data;
        size++;
    } 
    else {
        throw std::runtime_error("Stack Full");
    }
}

int Stack_A::pop() {
    if (size > 0) {
        size--;
        return stk[size];
    } 
    else {
        throw std::runtime_error("Empty Stack");
    }
}

int Stack_A::get_element_from_top(int idx) {
    if (idx >= 0 && idx < size) {
        return stk[size - idx - 1];
    } 
    else {
        throw std::runtime_error("Index out of range");
    }
}

int Stack_A::get_element_from_bottom(int idx) {
    if (idx >= 0 && idx < size) {
        return stk[idx];
    } 
    else {
        throw std::runtime_error("Index out of range");
    }
}

void Stack_A::print_stack(bool top_or_bottom) {
    if(size == 0) {
        return;
    }
    if (top_or_bottom) {
        for (int i = size - 1; i >= 0; i--) {
            std::cout << stk[i] << std::endl;
        }
    } 
    else {
        for (int i = 0; i < size; i++) {
            std::cout << stk[i] << std::endl;
        }
    }
}

int Stack_A::add() {
    if(size >= 2) {
        int a1 = pop();
        int a2 = pop();
        int result = a1 + a2;
        push(result);
        return result;
    }
    else {
        throw std::runtime_error("Not Enough Arguments");
    }
}

int Stack_A::subtract() {
    if(size >= 2) {
        int a1 = pop();
        int a2 = pop();
        int result = a2 - a1;
        push(result);
        return result;
    }
    else {
        throw std::runtime_error("Not Enough Arguments");
    }
}

int Stack_A::multiply() {
    if(size >= 2) {
        int a1 = pop();
        int a2 = pop();
        int result = a1 * a2;
        push(result);
        return result;
    }
    else {
        throw std::runtime_error("Not Enough Arguments");
    }
}

int Stack_A::divide() {
    if (size < 2) {
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

int* Stack_A::get_stack() {
    return stk;
}

int Stack_A::get_size() {
    return size;
}

