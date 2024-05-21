#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include<iostream>

using namespace std;

//Singly linked list
template <class T>
class ListNode{
  public:
    T value;
    ListNode<T>* next;
    ListNode(T nodeValue){
        value = nodeValue;
        next = nullptr;
    }
};

template<class T>
class LinkedList{
    private:
        ListNode<T>* head; //list head pointer
    public:
        LinkedList(){
            head = nullptr;
        }
        ~LinkedList();
        void appendNode(T);
        void insertNode(T);
        void deleteNode(T);
        void displayList() const;
        void 
}; 

template<class T>
void LinkedList<T>::appendNode(T newValue){ //add the value to the end of linked list
    ListNode<T>* newNode; //points to new node
    ListNode<T>* nodePtr; //go through the list
    newNode = new ListNode<T>(newValue);
    if(!head){ //Empty list
        head = newNode;
    }else{// non-empty list
        nodePtr = head;
        while(nodePtr->next){ //If the next node is not the nullptr, we keep going
            nodePtr = nodePtr->next;
        }//at the end nodePtr points to the last node of the list
        nodePtr->next = newNode;
    }
}

template<class T>
void LinkedList<T>::displayList() const{
    ListNode<T>* nodePtr;
    nodePtr = head;
    while(nodePtr){
        cout << nodePtr->value << " " << endl;
        nodePtr = nodePtr->next;
    }
}

template<class T>
LinkedList<T>::~LinkedList(){
    ListNode<T>* nodePtr;
    ListNode<T>* nextNode;

    nodePtr = head;
    while(nodePtr != nullptr){
        nextNode = nullptr->next;
        delete nodePtr;
        nodePtr = nextNode;
    }
}

template<class T>
void LinkedList<T>::insertNode(T newValue){
    ListNode<T>* newNode;
    ListNode<T>* nodePtr;
    ListNode<T>* prevPtr;

    newNode = new ListNode<T>(newValue);
    if(!head){
        head = newNode;
    }else{
        nodePtr = head;
        prevPtr = nullptr;

        while(nodePtr != nullptr && nodePtr->value > newValue){
            prevPtr = nodePtr;
            nodePtr = nodePtr->next;
        }

        if(prevPtr == nullptr){
            head = newNode;
            newNode->next = nodePtr;
        }else{
            prevPtr->next = newNode;
            newNode->next = nodePtr;
        }
    }
}

template<class T>
void LinkedList<T>::deleteNode(T keyValue){
    ListNode<T>* nodePtr;
    ListNode<T>* prevPtr;

    if(!head){
        return;
    }

    if(head->value == keyValue){
        nodePtr = head->next;
        delete head;
        head = nodePtr;
    }else{
        nodePtr = head;

        while(nodePtr != nullptr && nodePtr->value != keyValue){
            prevPtr = nodePtr;
            nodePtr = nodePtr->next;
        }
        
        if(nodePtr){        // if keyValue is found, then nodePtr is never nullPtr
            prevPtr->next = nodePtr->next;
            delete nodePtr;
        }
    }
}

#endif