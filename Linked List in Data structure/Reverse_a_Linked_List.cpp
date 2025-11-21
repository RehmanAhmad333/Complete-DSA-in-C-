#include<iostream>
using namespace std;

struct Node{
	int data;
	Node* next;	
	Node(): data(0)	, next(nullptr){}
	Node(int x){
		data = x;
		next = nullptr;
	}
	Node(int x , Node* next){
		data= x;
		this->next=next;
	}
};

class RLL{
	public:
		Node* reverseList(Node* head){
			Node* pre=NULL;   //pointer to the previous node
			Node* curr=head;  //pointer to the current node that hold head
			Node* next=NULL;  //pointer to the next node
			
			while(curr != NULL){   //run a while loop intil curr not equal to null
				next=curr->next;  //for every time run loop next is equal to current's next
				curr->next=pre;   //for every time run loop current's next is equal to previous
				
				//updates 
				pre=curr;      
				curr=next;
			}
			return pre;  //return a pre as a new header 
		}
};

int main(){
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    cout << "Original List: ";
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    // Reverse the list
    RLL r;
    Node* newHead = r.reverseList(head);

    // Print reversed list
    cout << "Reversed List: ";
    temp = newHead;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}