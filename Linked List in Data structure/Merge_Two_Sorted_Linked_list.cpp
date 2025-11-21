#include<iostream>

using namespace std;

class Node {
    public:
        int data;     // value stored in the node
        Node* next;   // pointer to the next node

        // Constructor to initialize node with value
        Node(int val) {
            data = val;
            next = NULL;
        }
};

class MLL {
    public:
        // Function to merge two sorted linked lists (h1 and h2)
        Node* mergeList(Node* h1, Node* h2) {
            
            // Base cases:
            if(h1 == NULL || h2 == NULL){ 
				return h1 == NULL ? h2 : h1; 
			}

            if(h1->data <= h2->data) {
                h1->next = mergeList(h1->next, h2);     // move h1 forward
                return h1;                              // return h1 as current node of merged list
            } 
            else {
                h2->next = mergeList(h2->next, h1);  // move h2 forward
                return h2;                          // return h2 as current node of merged list
            }
        }       
};

int main(){
    
	// Create first sorted list: 1 -> 3 -> 5
    Node* h1 = new Node(1);
    h1->next = new Node(3);
    h1->next->next = new Node(5);

    // Create second sorted list: 2 -> 4 -> 6
    Node* h2 = new Node(2);
    h2->next = new Node(4);
    h2->next->next = new Node(6);

    MLL l;
    Node* merged = l.mergeList(h1, h2);

    // Print merged list
    cout<<"Merged List: ";
    Node* temp = merged;
    while (temp != NULL) {
        cout<<temp->data<< " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";

    return 0;
}
