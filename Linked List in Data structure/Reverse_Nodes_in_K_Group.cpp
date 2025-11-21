#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class RLL {
	public:
	    Node* reverseInKgroup(Node* head, int k) {
	        if (head == nullptr || k <= 1) return head;
	
	        // 1) Check if there are at least k nodes available from head.
	        Node* temp = head;
	        int count = 0;
	        while (count < k) {
	            if (temp == nullptr) {
	                // fewer than k nodes -> do not reverse this part
	                return head;
	            }
	            temp = temp->next;
	            count++;
	        }
	
	        // 2) Recursively reverse the remaining list starting from temp
	        //    (temp points to the node right after the current k-block).
	        Node* preReversed = reverseInKgroup(temp, k);
	
	        // 3) Reverse the current k-group and attach its tail to preReversed.
	        temp = head;
	        count = 0;
	        Node* newHead = nullptr;   // will become the head of this reversed group
	        
	        while (count < k) {
	            Node* nextNode = temp->next; // store next
	            temp->next = preReversed;   // link current node to already reversed part
	            preReversed = temp;         // move 'preReversed' forward (acts like prev)
	            
	            newHead = temp;              // update newHead (last assigned will be group's head)
	            
	            temp = nextNode;             // move to next node in original order
	            count++;
	        }
	
	        // newHead is the head of reversed group (previously the k-th node)
	        return newHead;
	    }
};

void printList(Node* head) {
    Node* t = head;
    while (t != nullptr) {
        cout << t->data;
        if (t->next) cout << " -> ";
        t = t->next;
    }
    cout << " -> NULL\n";
}


int main() {
    // Build list:- 1->2->3->4->5->6->7
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->next = new Node(7);

    cout << "Original list:\n";
    printList(head);

    RLL r;
    int k = 3;
    Node* newHead = r.reverseInKgroup(head, k);

    cout << "After reversing in groups of " << k << ":\n";
    printList(newHead);

    return 0;
}
