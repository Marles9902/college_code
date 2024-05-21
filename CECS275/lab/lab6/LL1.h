/*
 * This is singly linked list header file
 * CECS 275 - Spring 2022
 * @author Marwin Gonzales
 * @author Skye Rogers
 * @version 1.0.0
 * 
 */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
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
        ListNode<T>* head;                              //list head pointer
    public:
        LinkedList(){
            head = nullptr;
        }
        ~LinkedList();
        void add(T);
        void drop(T);
}; 

template<class T>
void LinkedList<T>::add(T newValue){                    //add the value to the end of linked list
    ListNode<T>* newNode;                               //points to new node
    ListNode<T>* nodePtr;                               //go through the list
    newNode = new ListNode<T>(newValue);
    if(!head){ //Empty list
        head = newNode;
    }else{// non-empty list
        nodePtr = head;
        while(nodePtr->next){//If the next node is not the nullptr, we keep going
            nodePtr = nodePtr->next;
        }//at the end nodePtr points to the last node of the list
        nodePtr->next = newNode;
    }
}

template<class T>
void LinkedList<T>::drop(T keyValue){
    ListNode<T>* nodePtr;
    ListNode<T>* prevNode;
    if(!head){
        return;
    }
    if(head->value == keyValue)
    {
        nodePtr = head->next;
        delete head;
        head = nodePtr;
    }else{
        nodePtr = head;
        while(nodePtr != nullptr && nodePtr->value != keyValue){
            prevNode = nodePtr;
            nodePtr = nodePtr->next;
        }
        if(nodePtr){//if keyValue is found, then nodePtr is never nullPtr
            prevNode->next = nodePtr->next;
            delete nodePtr;
        }
    }
}
#endif