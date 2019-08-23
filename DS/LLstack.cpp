#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* link;
};
Node* top = NULL;

//checks whether empty
bool isEmpty(){
    if(top == NULL){
        return true;
    }else{
        return false;
    }
}

//insert item:
void push(int value){
    Node* ptr = new Node();
    ptr -> data = value;
    ptr -> link = top;
    top = ptr;
}

//remove item:
void pop(){
    if(isEmpty()){
        cout << "Stack is empty!" << endl;
    }else{
        Node* ptr = top;
        top = top -> link;
        delete(ptr);
    }
}

//return top item;
void top(){
    if(isempty()){
        cout << "Stack is empty!" << endl;
    }else{
        cout << "Element at top is: " << top -> data << endl;
    }
}

int main(){
    push(1);
    push(2);
    pop();

    return 0;
}