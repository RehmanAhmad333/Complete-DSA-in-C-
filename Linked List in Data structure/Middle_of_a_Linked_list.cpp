#include<iostream>

using namespace std;

struct Node {
    int data;     // variable to store the data of the node
    Node* next;   // pointer to the next node in the linked list

    // Default constructor
    Node() {
        data = 0;          // initialize data with 0
        next = nullptr;    // initialize next pointer as NULL
    }

    // Constructor with only data
    Node(int val) {
        data = val;        // store the given value in data
        next = nullptr;    // next is still NULL by default
    }

    // Constructor with data and next pointer
    Node(int val, Node* nextNode) {
        data = val;        // store the given value
        next = nextNode;   // link to the provided next node
    }
};

class MLL {
    public:

        // Function to find the middle of the linked list
        Node* middleOfList(Node* head) {
            
            Node* slow = head;  // slow pointer moves 1 step at a time          
            Node* fast = head->next;  // fast pointer moves 2 steps at a time

            // move until fast reaches end of list
            while (fast != NULL && fast->next != NULL) {
                slow = slow->next;           // move slow one step
                fast = fast->next->next;     // move fast two steps
            }

            // when fast reaches end, slow will be at the middle
            return slow;   // return slow as the middle node
        }
};

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    MLL list;
    Node* mid = list.middleOfList(head);

    cout << "Middle element is: " << mid->data << endl;

    return 0;
}
