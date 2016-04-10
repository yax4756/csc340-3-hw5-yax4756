#pragma once

#include "StackInterface.h"
#include "Node.h"
#include <vector>
#include <cassert>

using namespace std;

template<class ItemType>
class DLinkedStack : public StackInterface<ItemType> {
private:
    Node<ItemType> *headPtr;    // Pointer to first node in the chain;
    Node<ItemType> *topPtr;    // Pointer to (last) node in the chain that contains the stack's top
public:

    DLinkedStack();

    DLinkedStack(const DLinkedStack<ItemType> &aStack);    // Copy constructor

    virtual ~ DLinkedStack();    // Destructor

    Node<ItemType> *getPointerTo(const ItemType &target) const;

    bool isEmpty() const;

    bool push(const ItemType &newItem);

    bool pop();

    ItemType peek() const;

    vector<ItemType> toVector() const;

    Node<ItemType> *getHeadPTR() const;

    Node<ItemType> *getTopPTR() const;
};

template<class ItemType>
DLinkedStack<ItemType>::DLinkedStack() : headPtr(nullptr), topPtr(nullptr) {
}

template<class ItemType>
DLinkedStack<ItemType>::DLinkedStack(const DLinkedStack<ItemType> &aStack) {
    //TODO - Implement the copy constructor
    this->headPtr= nullptr;
    this->topPtr= nullptr;
    if(aStack.headPtr== nullptr)return;
    vector<ItemType> entries = aStack.toVector();
    for(int i = entries.size()-1; i >=0 ; i--){
        this->push(entries[i]);
    }

}

template<class ItemType>
DLinkedStack<ItemType>::~DLinkedStack() {
    //TODO - Implement the destructor
    Node<ItemType> *ptr=this->headPtr;
    while(this->headPtr != nullptr){
        ptr=this->headPtr->getNext();
        delete this->headPtr;
        this->headPtr=ptr;
    }
}

template<class ItemType>
Node<ItemType> *DLinkedStack<ItemType>::getPointerTo(const ItemType &target) const {
    //TODO - Return the Node pointer that contains the target(return nullptr if not found)
    if(headPtr== nullptr)
        return nullptr;
    Node<ItemType> *ptr=this->headPtr;
    do{
        if(ptr->getItem()==target)return ptr;
        ptr=ptr->getNext();
    }while(ptr!= nullptr);

    return nullptr;
}

template<class ItemType>
bool DLinkedStack<ItemType>::isEmpty() const {
    //TODO - Return True if the list is empty
    if(this->headPtr== nullptr)return true;
    return false;
}

template<class ItemType>
bool DLinkedStack<ItemType>::push(const ItemType &newItem) {
    //TODO - Push an item on the Doubly Linked Stack
    Node<ItemType> *ptr=new Node<ItemType>(newItem);
    if(this->isEmpty()){
        headPtr=ptr;

        this->topPtr=ptr;

        return true;
    }
    ptr->setPrev(topPtr);
    ptr->setNext(nullptr);
    this->topPtr->setNext(ptr);
    topPtr=ptr;
    return true;
}

template<class ItemType>
bool DLinkedStack<ItemType>::pop() {
    //TODO - Pop an item from the stack - Return true if successful
    if(headPtr== nullptr)return false;
    topPtr=topPtr->getPrev();
    topPtr->setNext(nullptr);
    return true;
}

template<class ItemType>
ItemType DLinkedStack<ItemType>::peek() const {//Assume this never fails.
    //TODO - return the element stored at the top of the stack (topPtr)

    return topPtr->getItem();//garbage
}

template<class ItemType>
vector<ItemType> DLinkedStack<ItemType>::toVector() const {
    // DO NOT MODIFY THIS FUNCTION
    vector<ItemType> returnVector;
    // Put stack items into a vector in top to bottom order
    Node<ItemType> *curPtr = topPtr;
    while (curPtr != nullptr) {
        returnVector.push_back(curPtr->getItem());
        curPtr = curPtr->getPrev();
    }
    return returnVector;
}

template<class ItemType>
Node<ItemType> *DLinkedStack<ItemType>::getHeadPTR() const {
    // DO NOT MODIFY THIS FUNCTION
    return headPtr;
}

template<class ItemType>
Node<ItemType> *DLinkedStack<ItemType>::getTopPTR() const {
    // DO NOT MODIFY THIS FUNCTION
    return topPtr;
}