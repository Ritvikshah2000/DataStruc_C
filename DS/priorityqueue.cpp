#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>

using namespace std;

//declare the node:
struct node{
    int priority;
    int info;
    struct node *link;
};

//priority queue class:
class priorityQueue{
    private:
        node *front;
    public:
        priorityQueue(){
            front = NULL;
        }

        //insert into PQ:
        void insert(int item, int priority){
            node *temp, *q;
            temp = new node;
            temp -> info = item;
            temp -> priority = priority;
            if(front == NULL || priority < front -> priority){
                temp -> link = front;
                front = temp;
            }else{
                q = front;
                while(q -> link != NULL && q -> link -> priority <= priority){
                    q = q-> link;
                }
                temp -> link = q -> link;
                q -> link = temp;
            }
        }

        //delete from PQ:
        void del(){
            node *temp;
            if(front == NULL){
                cout << "Queue is underflow!" << endl;
            }else{
                temp = front;
                cout << "Delete item is: " << temp -> info << endl;
                front = front -> link;
                free(temp);
            }
        }
        
        //display items:
        void display(){
            node* ptr;
            ptr = front;
            if(front == NULL){
                cout << "Queue is empty" << endl;
            }else{
                cout << "Queue is : " << endl;
                cout << "Priority       Item" << endl;
                while(ptr != NULL){
                    cout << ptr -> priority << "            " << ptr -> info << endl;
                    ptr = ptr -> link;
                }
            }
        }
};

int main(){
    int choice, item, priority;
    priorityQueue pq;
    do{
        cout << "1. Insert" << endl;
        cout << "2. Delete" << endl;
        cout << "3. Display" << endl;
        cout << "4. Quit" << endl;
        cout << "Enter your choice : ";
        cin >> choice;
        switch(choice){
            case 1:
                cout << "Input item value to be added :";
                cin >> item;
                cout << "Enter its priority : ";
                cin >> priority;
                pq.insert(item, priority);
                break;
            case 2:
                pq.del();
                break;
            case 3:
                pq.display();
                break;
            case 4:
                break;
            default:
                cout << "Wrong choice" << endl;
        }       
    }  
    while(choice != 4);
    return 0; 
}