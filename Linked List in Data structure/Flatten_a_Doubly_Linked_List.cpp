#include<iostream>

using namespace std;

class Node{
	public:
		int data;
		Node* next;
		Node* prev;
		Node* child;
		
		Node(int val){
			data= val;
			next = prev = child = NULL;
		}	
};

class Solution{
	public:
		Node* flatten(Node* head){
			if(head == NULL){
				return NULL;
			}
			
			Node* curr = head;
			// Loop through all nodes in the main list
			while(curr != NULL){   
				// If current node has a child list
				if(curr->child != NULL){
					Node* newNext = curr->next;  //Save current node's next pointer (so we can reconnect later)
					
					curr->next = flatten(curr->child); //Flatten the child list and attach it after the current node
					
					//Connect backward link: child list ka first node ka prev = current node
					if(curr->next != NULL){
						curr->next->prev = curr;   // This line ensures the doubly link is maintained						
					}
					curr->child = NULL; //Child is now merged, so remove the child pointer
					
					Node* tail= curr->next;					
					while(tail != NULL && tail->next != NULL){  //Move to the end (tail) of the newly attached child list
						tail = tail->next;
					}
					
					// Reconnect the previously saved 'next' node (newNext)
					if(newNext != NULL){
						tail->next = newNext;        // Link tail to original next node
						newNext->prev = tail;         // Maintain backward link
					}
				}
				curr = curr->next;
			}
			return head;
		}
};

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;

    head->next->child = new Node(4);
    head->next->child->next = new Node(5);
    head->next->child->next->prev = head->next->child;

    Solution s;
    Node* flat = s.flatten(head);

    cout << "Flattened list: ";
    while (flat != NULL) {
        cout << flat->data << " ";
        flat = flat->next;
    }
    cout << endl;
    return 0;
}