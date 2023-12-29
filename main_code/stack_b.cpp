#include<iostream>
#include "stack_b.h"
#include<stdexcept>
#include<new>
using namespace std;

Stack_B::Stack_B() {
    size = 0;
    capacity = 1024;
    stk = new int[capacity];
}

Stack_B::~Stack_B() {
    delete[] stk;
}

void Stack_B::push(int data) {
    if(size < capacity) {
        stk[size] = data;
        size++;
    }
    else {
        try {
        int abdullah_capacity = capacity*2;
        int* abdullah = new int[abdullah_capacity];
        for(int i=0; i < size; i++) {
            abdullah[i] = stk[i];
        }
        abdullah[size] = data;
        size++;
        delete[] stk;
        stk = abdullah;
        capacity = abdullah_capacity;
    } 
    catch (const std::bad_alloc& e) {
        throw std::runtime_error("Out of Memory");
    }
    }
}

int Stack_B::pop() {
    if(size > 0) {
        size--;
        int value = stk[size];
        int threshold = capacity/4;
        if(capacity > 2048 && size < threshold) {
        int abdullah_capacity = capacity/2;
        int* abdullah = new int[abdullah_capacity];
        for(int i=0; i < size; i++) {
            abdullah[i] = stk[i];
        }
        delete[] stk;
        stk = abdullah;
        capacity = abdullah_capacity;
    }
        return value;
    }
    else {
        throw std::runtime_error("Empty Stack");
    }
}

int Stack_B::get_element_from_top(int idx) {
    if (idx >= 0 && idx < size) {
        return stk[size - idx - 1];
    } 
    else {
        throw std::runtime_error("Index out of range");
    }
}

int Stack_B::get_element_from_bottom(int idx) {
    if (idx >= 0 && idx < size) {
        return stk[idx];
    } 
    else {
        throw std::runtime_error("Index out of range");
    }
}

void Stack_B::print_stack(bool top_or_bottom) {
    if(size == 0) {
        return;  //here error can occur
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

int Stack_B::add() {
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

int Stack_B::subtract() {
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

int Stack_B::multiply() {
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

int Stack_B::divide() {
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

int* Stack_B::get_stack() {
    return stk;
}

int Stack_B::get_size() {
    return size;
}

