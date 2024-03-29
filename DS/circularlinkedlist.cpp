typedef string Elem; // element type
class CNode { // circularly linked list node
    private:
        Elem elem; // linked list element value
        CNode* next; // next item in the list
    friend class CircleList; // provide CircleList access
};
class CircleList { // a circularly linked list
    public:
        CircleList(); // constructor
        ˜CircleList(); // destructor
        bool empty() const; // is list empty?
        const Elem& front() const; // element at cursor
        const Elem& back() const; // element following cursor
        void advance(); // advance cursor
        void add(const Elem& e); // add after cursor
        void remove(); // remove node after cursor
    private:
        CNode* cursor; // the cursor
};

//constructor & destructor
CircleList::CircleList() // constructor
    : cursor(NULL) { }
CircleList::˜CircleList() // destructor
    { while (!empty()) remove(); }

//simple member functions
bool CircleList::empty() const // is list empty?
    { return cursor == NULL; }
const Elem& CircleList::back() const // element at cursor
    { return cursor−>elem; }
const Elem& CircleList::front() const // element following cursor
    { return cursor−>next−>elem; }
void CircleList::advance() // advance cursor
    { cursor = cursor−>next; }

//insertion just after cursor
void CircleList::add(const Elem& e) { // add after cursor
    CNode* v = new CNode; // create a new node
    v−>elem = e;
    if (cursor == NULL) { // list is empty?
        v−>next = v; // v points to itself
        cursor = v; // cursor points to v
    }
    else { // list is nonempty?
        v−>next = cursor−>next; // link in v after cursor
        cursor−>next = v;
    }
}

//removing node following cursor:
void CircleList::remove() { // remove node after cursor
    CNode* old = cursor−>next; // the node being removed
    if (old == cursor) // removing the only node?
        cursor = NULL; // list is now empty
    else
        cursor−>next = old−>next; // link out the old node
    delete old; // delete the old node
}