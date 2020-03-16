//
// Created by dietb on 3/16/2020.
//
//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.
#ifndef INC_2188HW6_ARRAYSTACK_H
#define INC_2188HW6_ARRAYSTACK_H

#include "StackInterface.h"

const int MAX_STACK = 5;

template<class ItemType>
class ArrayStack : public StackInterface<ItemType> {
private:
    static const int DEFAULT_CAPACITY = 50;
    ItemType items[DEFAULT_CAPACITY]; // Array of stack items
    int top;                     // Index to top of stack

public:
    ArrayStack();                    // Default constructor
    [[nodiscard]] bool isEmpty() const;

    bool push(const ItemType &newEntry);

    bool pop();

    ItemType peek() const;
};

#include <cassert>       // For assert

template<class ItemType>
ArrayStack<ItemType>::ArrayStack() : top(-1) {}

template<class ItemType>
bool ArrayStack<ItemType>::isEmpty() const {
    return top < 0;
}//# isEmpty

template<class ItemType>
bool ArrayStack<ItemType>::push(const ItemType &newEntry) {
    bool result = false;
    // if stack has room
    if (top < DEFAULT_CAPACITY - 1) {
        top++;
        items[top] = newEntry;
        result = true;
    }
    return result;
}//#push

template<class ItemType>
bool ArrayStack<ItemType>::pop() {
    bool result = false;
    if(!isEmpty()){
        top--;
        result = true;
    }
    return result;
}//# pop

template<class ItemType>
ItemType ArrayStack<ItemType>::peek() const {
assert(!isEmpty());
return items[top];
}//#peek
// end ArrayStack
#endif //INC_2188HW6_ARRAYSTACK_H
