#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* link;
};
Node* front = NULL;
Node* rear = NULL;

//checks whether empty
bool isEmpty(){
    if(front == NULL && rear == NULL){
        return true;
    }else{
        return false;
    }
}

//insert element at rear
void enqueue(int value){
    Node* ptr = new Node();
    ptr -> data = value;
    ptr -> link = NULL;

    if(front == NULL){
        front = ptr;
        rear = ptr;
    }else{
        rear -> link = ptr;
        rear = ptr;
    }
}

//remove element from front
void dequeue(){
    if(isempty()){
        cout << "Queue is empty!" << endl;
    }else{
        if(front == rear){
            delete(front);
            front = rear = NULL;
        }else{
            Node* ptr = front;
            front = front -> link;
            delete(ptr);
        }
    }
}

//display queue
void displayQueue(){
    if(isEmpty()){
        cout << "Queue is empty!" << endl;
    }else{
        Node* ptr = front;
        while(ptr != NULL){
            cout << ptr -> data << " ";
            ptr = ptr -> link;
        }
    }
}