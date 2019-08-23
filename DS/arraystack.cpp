#include<iostream>
#define SIZE 5;
using namespace std;

int A[SIZE];
int top = -1;

//check whether empty:
bool isEmpty(){
    if(top == -1){
        return true;
    }else{
        return false;
    }
}

//insert a new element:
void push(int value){
    if(top == SIZE-1){
        cout << "Stack is FUll!" << endl;
    }else{
        top++;
    }
}

//remove an element:
void pop(){
    if(isEmpty()){
        cout << "Stack is empty!" << endl;
    }else{
        top--;
    }
}

//return element at top:
void top(){
    if(isEmpty()){
        cout << "Stack is empty!" << endl;
    }else{
        cout << "Element at top is : " << A[top] << endl;
    }
}

//display stack:
void displayStack(){
    if(isEmpty()){
        cout << "Stack is empty!" << endl;
    }else{
        for(int i = 0; i <= top; i++){
            cout << A[i] << " ";
        }
    }
}

int main(){
    push(2);
    push(3);

    displayStack();

    pop();

    top();

    return 0;
}