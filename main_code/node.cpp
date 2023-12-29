#include "node.h"
#include<iostream>
#include<stdexcept>

Node::Node(bool sentinel) : is_sentinel(true){
    is_sentinel=true;
}

Node::Node(int v, Node* nxt, Node* prv) {
    value=v;
    next =nxt;
    prev=prv;
}

bool Node::is_sentinel_node() {
    return is_sentinel;
}

int Node::get_value() {
    return value;
}