#ifndef MYSTACK_H
#define MYSTACK_H

#include <iostream>

using namespace std;

template <class T>
class MyStack{
    private:
        struct StackNode{
            T value;
            StackNode* next;
        };
        StackNode* top;
        int count;
    public:
        MyStack(){
            top = nullptr;
        }
        ~MyStack();
        void push(T);
        void pop(T&);
        bool isEmpty() const;
        int size() const;
        void display();
};

template <class T>
MyStack<T>::~MyStack(){
    StackNode* nodePtr, *nextNode;
    nodePtr = top;

    while(nodePtr != nullptr){
        nextNode = nodePtr->next;
        delete nodePtr;
        nodePtr = nextNode;
    }
}

template <class T>
void MyStack<T>::push(T item){
    StackNode* newNode = nullptr;

    newNode = new StackNode;
    newNode->value = item;

    if(isEmpty()){
        top = newNode;
        newNode->next = nullptr;
    }else{
        newNode->next = top;
        top = newNode;
    }
    ++count;
}

template <class T>
void MyStack<T>::pop(T& item){
    StackNode *temp = nullptr;
    if(isEmpty()){
        cout << "The stack is empty. \n";
    }else{
        item = top->value;
        temp = top->next;
        delete top;
        top = temp;
        --count;
    }
}

template <class T>
bool MyStack<T>::isEmpty() const{
    return top == nullptr;
}

template <class T>
int MyStack<T>::size() const{
    return count;
}

template <class T>
void MyStack<T>::display(){
    StackNode* nodePtr;
    nodePtr = top;
    T item;
    while(!isEmpty()){
        pop(item);
        cout << item << " ";
    }
    cout << endl;
}

#endif