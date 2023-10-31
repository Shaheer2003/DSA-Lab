#include<bits/stdc++.h>
using namespace std;
#define nl "\n"

class Node{
public:
	int data;
	Node* next;
	Node* prev;
	Node(int data){
		this->data=data;
		this->prev=NULL;
		this->next=NULL;
	}
	~Node(){
		this->prev=NULL;
		this->next=NULL;
	}
};
class Doubly{
public:
	Node* head;
	Doubly(){
		head=NULL;
	}
	void print(){
        if(!head) {
            return;
        }
        Node* temp = head;
        do{
            cout << temp->data << "\t";
            temp = temp->next;
        }while(temp != head);
        cout << nl;
    }
	void InsertAtHead(int data) {
	    Node* newNode = new Node(data);
	    if (!head) {
	        newNode->next = newNode;
	        newNode->prev = newNode;
	        head = newNode;
	    } else {
	        newNode->next = head;
	        newNode->prev = head->prev;
	        head->prev->next = newNode;
	        head->prev = newNode;
	        head = newNode;
	    }
	}
	void InsertAtTail(int data) {
        if (!head) {
            Node* temp = new Node(data);
            temp->next = temp;
            temp->prev = temp;
            head = temp;
        }
        else {
            Node* temp = new Node(data);
            temp->next = head;
            temp->prev = head->prev;
            head->prev->next = temp;
            head->prev = temp;
        }
    }
	void InsertAtPosition(int position,int data){
		if(position==1){
			InsertAtHead(data);
			return;
		}
		int cnt=1;
		Node* temp=head;
		while(cnt<position-1){
			temp=temp->next;
			cnt++;
		}
		if(temp->next==NULL){
			InsertAtTail(data);
			return;
		}
		Node* input=new Node(data);
		input->next=temp->next;
		temp->next->prev=input;
		temp->next=input;
		input->prev=temp;	
	}
	void DeleteNode(int position){
		if (!head) {
            return;
        }
        
        if (position == 1) {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            if (head->next == head) {
                delete head;
                head = NULL;
            }
            else {
                Node* input = head->next;
                temp->next = input;
                input->prev = temp;
                delete head;
                head = input;
            }
        }
        else {
            int cnt = 1;
            Node* curr = head;
            while (cnt < position) {
                curr = curr->next;
                cnt++;
            }
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
            delete curr;
        }
    }
	
};
int main() {
    Doubly dc;

    dc.InsertAtHead(10);
    dc.InsertAtHead(20);
    dc.InsertAtHead(30);

    dc.print();

    dc.InsertAtTail(40);
    dc.InsertAtTail(50);

    dc.print();

    dc.InsertAtPosition(3, 25);
    dc.InsertAtPosition(6, 45);

    dc.print();

    dc.DeleteNode(2);
    dc.DeleteNode(4);

    dc.print();
    return 0;
}