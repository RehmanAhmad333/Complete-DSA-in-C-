#include<iostream>
using namespace std;

//Node class (building block of the list)
class Node {  
    public:
        int data;       // stores the data
        Node* next;     // pointer to the next node

        // Constructor: initializes a node with given value
        Node(int val) {
            data = val;     // store the value
            next = NULL;    // initially, the node doesn't point to anything
        }
};

 
// List class (manages all nodes)
class List {
    public:
        Node* head;   // pointer to the first node
        Node* tail;   // pointer to the last node

        // Constructor: initialize an empty list
        List() {
            head = tail = NULL;
        }

         
        // Insert element at the beginning
         
        void push_front(int val) {
            Node* newNode = new Node(val); // create a new node
            if (head == NULL) {            // if list is empty
                head = tail = newNode;     // both head and tail are this node
                return;
            } else {
                newNode->next = head;  // new node points to old head
                head = newNode;        // update head to new node
            }
        }

         // Insert element at the end
         void push_back(int val) {
            Node* newNode = new Node(val); // create a new node
            if (head == NULL) {            // if list is empty
                head = tail = newNode;
                return;
            } else {
                tail->next = newNode; // last node points to new node
                tail = newNode;       // update tail to new node
            }           
        }

    
        // Remove element from the front
        void pop_front() {
            if (head == NULL) {   // empty list
                cout << "The linked list is empty.\n";
                return;
            } else {
                Node* temp = head;     // store old head
                head = temp->next;     // move head to the next node
                temp->next = NULL;     // detach the node
                delete temp;           // free memory
            }
        }


        // Remove element from the end     
        void pop_back() {
            if (head == NULL) {   // empty list
                cout << "The linked list is empty.\n";
                return;
            } 
            else if (head->next == NULL) { // only one node
                delete head;
                head = tail = NULL;
                return;
            }
            else {
                Node* temp = head;

                // move until the second-last node
                while (temp->next != tail) {
                    temp = temp->next;
                }

                temp->next = NULL;  // break the link to last node
                delete tail;        // delete old tail
                tail = temp;        // update tail
            }
        }

         
        // Insert at a specific position
        // pos = 0 -> insert at head
        void insert(int val, int pos) {
            if (pos < 0) {
                cout << "Invalid Position.\n";
                return;
            }

            if (pos == 0) {   // if position is at head
                push_front(val);
                return;
            }

            Node* temp = head;

            // move (pos-1) steps to reach previous node
            for (int i = 0; i < pos - 1; i++) {
                if (temp == NULL) {   // position exceeds length
                    cout << "INVALID POSITION.\n";
                    return;
                }
                temp = temp->next;
            }

            Node* newNode = new Node(val);

            // insert node between temp and temp->next
            newNode->next = temp->next;
            temp->next = newNode;

            // if inserted at last position, update tail
            if (newNode->next == NULL) {
                tail = newNode;
            }
        }

         
        // Search for a value in the list
        // Returns index (0-based) if found
        // Returns -1 if not found
        int search(int val) {
            if (head == NULL) {
                cout << "Linked list is empty.\n";
                return -1;
            } else {
                Node* temp = head;
                int idx = 0;

                while (temp != NULL) {
                    if (temp->data == val) {
                        return idx;   // value found
                    }
                    idx++;
                    temp = temp->next;
                }
                return -1;  // value not found
            }
        }

         
        // Print the list
        void print() {
            Node* temp = head;
            while (temp != NULL) {
                cout << temp->data << " -> ";
                temp = temp->next;
            }
            cout << "NULL\n";
        }
};


int main() {
    List l;

    // Insert elements
    l.push_front(3);   // list: 3
    l.push_back(90);   // list: 3 -> 90
    l.push_front(5);   // list: 5 -> 3 -> 90
    l.push_back(67);   // list: 5 -> 3 -> 90 -> 67
    l.insert(45, 2);   // list: 5 -> 3 -> 45 -> 90 -> 67

    // Print list
    l.print();

    return 0;
}