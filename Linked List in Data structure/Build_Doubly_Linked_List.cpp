#include<iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;
        Node* pre;

        // Constructor to initialize node with value
        Node(int val) {
            data = val;
            next = pre = NULL;
        }
};

class DLL {
    public:
        Node* head; // pointer to first node
        Node* tail; // pointer to last node

        // Constructor: initializes empty list
        DLL() {
            head = tail = NULL;
        }

        // Insert a new node at the front
        void push_front(int val) {
            Node* newNode = new Node(val);
            if (head == NULL) {  // if list is empty
                head = tail = newNode;
                return;
            } else {
                newNode->next = head; // connect new node to current head
                head->pre = newNode;  // link back from old head
                head = newNode;       // update head
                return;
            }
        }

        // Insert a new node at the back
        void push_back(int val) {
            Node* newNode = new Node(val);
            if (head == NULL) {  // if list is empty
                head = tail = newNode;
                return;
            } else {
                tail->next = newNode; // connect current tail to new node
                newNode->pre = tail;  // link back from new node
                tail = newNode;       // update tail
                return;
            }
        }

        // Remove node from the front
        void pop_front() {
            if (head == NULL) {
                cout << "The linked list is empty.\n";
                return;
            } else {
                Node* temp = head;     // store current head
                head = temp->next;     // move head forward
                if (head != NULL) {    // if list not empty after removal
                    head->pre = NULL;  // remove backward link
                }
                temp->next = NULL;     // disconnect old node
                delete temp;           // free memory
                return;
            }
        }

        // Remove node from the back
        void pop_back() {
            if (head == NULL) {
                cout << "The linked list is empty.\n";
                return;
            } else {
                Node* temp = tail;     // store current tail
                tail = temp->pre;      // move tail backward
                if (tail != NULL) {    // if list not empty after removal
                    tail->next = NULL; // remove forward link
                }
                temp->pre = NULL;      // disconnect old node
                delete temp;           // free memory
                return;
            }
        }

        // Print the entire list
        void print() {
            Node* temp = head;
            while (temp != NULL) {
                cout << temp->data << " <=> ";
                temp = temp->next;
            }
            cout << "NULL" << endl;
            return;
        }
};


// Main function 
int main() {
    DLL l;

    // Insert elements at both ends
    l.push_front(23);
    l.push_back(32);
    l.push_front(20);
    l.push_back(38);
    l.push_front(28);
    l.push_front(24);

    // Remove one element from each end
    l.pop_back();
    l.pop_front();

    // Print final list
    l.print();
    cout << "End program\n";
    return 0;
}
