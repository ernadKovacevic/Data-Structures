#pragma once
template<typename T>
class node{
public:
    T value;
    node* next;
    node* prev;

node():value(0),next(nullptr),prev(nullptr){};
node(const T& other):value(other),next(nullptr),prev(nullptr){};

};
