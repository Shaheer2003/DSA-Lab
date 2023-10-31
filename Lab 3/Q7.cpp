#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    
    Node(){
        this -> data = 0;
        this -> next = NULL;
    }
    
    Node(int d){
        this -> data = d;
        this -> next = NULL;
    }
};

class SingleLinkedList{
    public:
	Node* head;
    Node* tail;
    SingleLinkedList(){
        this -> head = NULL;
        this -> tail = NULL;
    }
    SingleLinkedList(Node *h, Node *t){
        this -> head = h;
        this -> tail = t;
    }
    
    int len(){
    	Node* temp = head;
    	int count = 0;
    	while (temp != NULL){
        	count++;
        	temp = temp -> next;
    	}
    	return count;
	}
    
    void print(){
    	Node* temp = head;
    	while (temp != NULL){
        	cout << temp -> data << " ";
        	temp = temp -> next;
    	}
    	cout << endl;
	}
	
	void insertatHead(int d){
		if(tail != NULL){
			Node* temp = new Node(d);
	    	temp -> next = head;
	    	head = temp; 
		}
		else{
			Node* temp = new Node(d);
	    	head = temp;
	    	tail = temp;
		}
	}

	void insertatTail(int d){
		if(head != NULL){
			Node* temp = new Node(d);
		    tail -> next = temp;
		    tail = temp;
		}
		else {
			
			Node* temp = new Node(d);
		    temp -> next = tail;
		    head = temp;
		    tail = temp;
		}		
	}

	bool sortList(SingleLinkedList &list){
		Node* temp = list.head;
		bool even = false, odd = false;
		while( temp!=NULL ){
			if(temp->data % 2 == 0){    // check if the list is all even/ all odd
				even = true;
			}
			if(temp->data % 2 != 0){
				odd = true;
			}
			temp = temp->next;
		}
		if(!even || !odd){
			cout << "No sorting needed" << endl;
			list.print();
			return false;
		}

		temp = list.head;
		while(temp != NULL){
			if(temp->data % 2 == 0){
				insertatTail(temp->data);
			}
			temp = temp -> next;
		}

		temp = list.head;
		while(temp != NULL){
			if(temp->data % 2 != 0){
				insertatTail(temp->data);
			}
			temp = temp -> next;
		}
		return true;
	}
	
};

int main(){
	SingleLinkedList list1;
	bool sortingNeeded;
	list1.insertatHead(17);
	list1.insertatTail(15);
	list1.insertatTail(8);
	list1.insertatTail(12);
	list1.insertatTail(10);
	list1.insertatTail(5);
	list1.insertatTail(4);
	list1.insertatTail(1);
	list1.insertatTail(7);
	list1.insertatTail(6);

	SingleLinkedList list2;
	sortingNeeded = list2.sortList(list1);
	if(sortingNeeded){
	cout << "Original List" << endl;
	list1.print();
	cout << "Sorted List" << endl;
	list2.print();
	}
	

	
	
	
	return 0;
}
