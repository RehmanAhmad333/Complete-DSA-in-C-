#include<iostream>

using namespace std;

class Node{
	public:
		int data;
		Node* next;
		
		Node(int val){
			data = val;
			next= NULL;
		}
};

class CLL{
	public:
		Node* head;
		Node* tail;
		
		CLL(){
			head=tail=NULL;
		}
		
		void insertAtHead(int val){
			Node* newNode=new Node(val);
			if ( head == NULL ){
				head=tail=newNode;
				tail->next=head;
			}
			else{
				newNode->next=head;
				head=newNode;
				tail->next=head;
			}
		}
		
		void insertAtTail(int val){
			Node* newNode=new Node(val);
			if(head==NULL){
				head=tail=newNode;
				tail->next=head;
			}
			else{
				tail->next=newNode;
				tail=newNode;
				
				newNode->next=head;
			}
		}
		
		void delAtHead(){
			if(head == NULL){
				cout<<"Circuler Linked List is empty.\n";
				
			}
			else if(head == tail){
				delete head;
				head=tail=NULL;
			}
			else{
				Node* temp=head;
				head=temp->next;
				tail->next=head;
				
				temp->next=NULL;
				delete temp;
				
			}
			return;
		}
		
		void delAtTail(){
			if(head == NULL){
				cout<<"Circuler Linked List is empty.\n";
				
			}
			else if(head == tail){
				delete head;
				head=tail=NULL;
			}
			else{
				Node* temp = head;
				while(temp->next != tail){
					temp = temp->next;
				}
				
				tail->next=NULL;
				temp->next=head;
				
				delete tail;
				tail=temp;
				
			}
		}
		
		void print(){
			if(head == NULL){
				cout<<"List is empty.\n";
				return;
			}
			
			Node* temp=head->next;
			cout<<head->data<<" -> ";
			
			while(temp != head){
				cout<<temp->data<<" -> ";
				
				temp = temp->next;
			}
			cout<<head->data<<endl;
			return;
		}
		
		
};

int main(){
	CLL l;
	l.insertAtHead(90);
	l.insertAtTail(60);
	l.insertAtHead(30);
	l.insertAtTail(20);
	
	l.delAtHead();
	l.delAtTail();
	
	l.print();
}