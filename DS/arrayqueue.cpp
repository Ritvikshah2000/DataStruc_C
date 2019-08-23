#include<iostream>
using namespace std;
#define SIZE 5;

int A[SIZE];
int front = -1;
int rear = -1;

//checks whether queue is empty
bool isEmpty(){
    if(front == -1 && rear == -1){
        return true
    }else{
        return false;
    }
}

//add from the rear:
void enqueue(int value){
    if(rear == SIZE-1){ //queue is full
        cout << "Queue is full!" << endl;
    }else{
        if(front == -1){ //first element is inserted
            front = 0;
        }
        rear++;
        A[rear] = value; //insert at rear
    }
}

//remove fromt front:
void dequeue(){
    if(isEmpty()){
        cout << "Queue is empty!" << endl;
    }else{
        if(front == rear){ //only one element
            front = rear = -1;
        }else{
            front++;
        }
    }
}

//return element at front of queue:
void showfront(){
    if(isEmpty()){
        cout << "Queue is empty" << endl;
    }else{
        cout << "Element at front is: " << A[front] << endl;
    }
}

//display entire queue:
void displayQueue(){
    if(isEmpty()){
        cout << "Queue is empty!" << endl;
    }else{
        for(int i = 0; i <= rear; i++){
            cout << A[i] << " ";
        }
    }
}

int main(){
    enqueue(2);
    enqueue(3);

    displayQueue();
}