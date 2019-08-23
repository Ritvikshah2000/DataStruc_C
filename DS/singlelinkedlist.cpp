#include<cstdlib>
class StringNode{ // a node in a list of strings
    private:
    string elem; //element value
    stringNode* next; //next element in list

    friend class StringLikedList; //provide StringLinkedList access
};

//the StringLinkedList is the actual linked list class, which supports a nunber of member functions, including a constructor
//a destructor and functions for insertion and deletion
class StringLikedList{
    public:
        StringLikedList(); //empty list constructor
        ~StringLikedList(); //destructor
        bool empty() const; //isthe list empty?
        const string& front() const; //get fron element
        void addFront(const string& e); //add to fron of list
        void removeFront(); //remove front item list
    private:
        StringNode* head; //pointer to head of list
};

StringLikedList::StringLikedList() : head(NULL){} //constructor
StringLikedList::~StringLikedList(){while(!empty()) removeFront();} //destructor
bool StringLinkedList::empty() const{return head == NULL;} //is list empty?
const string& StringLikedList::front() const {return head -> elem;} //get front element

//insertion to front of list
void StringLinkedList::addFront(const string& e){
    StringNode* v = new StringNode; //create new node
    v -> elem = e; //store data
    v -> next = head; //head now follows v
    head = v; // v is now head
}

//removal from front
void StringLinkedList::removeFront(){
    StringNode* old = head; //save current head
    head = old -> next; //skip over old head
    delete old; //delete old head
}