#include <iostream>
using namespace std;
class Node {
	public:
	    int data;
	    Node* next;
	    Node(int val) : data(val), next(NULL) {}
};
class SLL{
	public:
		Node* swapNodesPair(Node* head){   //check point if head is a null or list contain only one ele then return head
			if(head == NULL || head->next == NULL){
                return head; 
            }  
				
			Node* first=head;
			Node* sec=head->next;
			Node* pre=NULL; //pre pointer helping connection of each pair
			
			while(first != NULL && sec != NULL){   //running loop until "first" or "sec" pointer not NULL
				Node* third = sec->next;  // third pointer helping to reach next pair
				
				sec->next=first;  
				first->next=third;
				
				if(pre == NULL){
					head = sec;
				}else{
					pre->next=sec;  //in this line each previous pair connect with next pair 
				}				
				//updates
				first=third;
				if(third != NULL){
					sec=third->next;  //if third not is null then "sec" pointer point to third's next
				}else{
					sec=NULL;
				}
			}
			return head;   //return a head
		}
};

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    SLL obj;
    Node* newHead = obj.swapNodesPair(head);

    // Print final list
    cout << "After Swapping in Pairs: ";
    Node* temp = newHead;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";

    return 0;
}