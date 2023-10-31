#include <iostream>
#include <string>
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
    
    ~Node(){
    	if(this -> next != NULL){
    		delete next;
			next = NULL;
		}
		cout << "Destructor Called" << endl;
	}
};

// void insertatHead(Node* &head, Node* &tail, int d){
// 	if(tail != NULL){
// 		Node* temp = new Node(d);
//     	temp -> next = head;
//     	head = temp; 
// 	}
// 	else{
// 		Node* temp = new Node(d);
//     	head = temp;
//     	tail = temp;
// 	}
// }

void insertatTail(Node* &tail, Node* &head, int d){ // Q2
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

// void insertatGivenPos(Node* &head, Node* &tail, int pos, int d){
// 	Node* temp = head;
// 	int count = 1;
// 	if(pos == 1){
// 		insertatHead(head, tail, d);
// 		return;
// 	}
	
// 	while(count < pos-1){
// 		temp = temp -> next;
// 		count++;
// 		if (temp->next == NULL){
// 			insertatTail(tail,head,d);
// 			return;
// 		}
// 	}
// 	Node* newnode = new Node(d);
// 	newnode -> next = temp -> next;
// 	temp -> next = newnode;

// }

// void deleteGivenVal(Node* &head, Node* &tail, int val){
// 	Node* prev = NULL;
// 	Node* curr = head;
// 	if(curr -> data == val){
// 		head = curr -> next;
// 		curr -> next = NULL;
// 		delete curr;
// 		return;
// 	}
	
// 	while(curr -> data != val){
// 		prev = curr;
// 		curr = curr -> next;
// 	}
// 	if(curr->next == NULL && curr->data == val){
// 		tail = prev;
// 	}
	
// 	prev -> next = curr -> next;
// 	curr -> next = NULL;
// 	delete curr;
// }

// void updateGivenVal(Node* &head, Node* &tail, int x, int d){
// 	Node* temp = head;
// 	while(temp->data != x){
// 		temp = temp -> next;
// 		if(temp -> next == NULL && temp -> data != x){		
// 			cout << "Value Does not exist" << endl;
// 			return;
// 		}
// 	}	
// 	temp -> data = d;
// }

void print(Node* &head){
    Node* temp = head;
    while (temp != NULL){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

int main(){
    Node* head = NULL;
    Node* tail = NULL;
    
    insertatTail(tail,head, 10);
    print(head);
    
    insertatTail(tail,head,11);
    print(head);

	insertatTail(tail,head,20);
    print(head);

	insertatTail(tail,head,35);
    print(head);

	insertatTail(tail,head,50);
    print(head);	
	
	cout << "head " << head->data << endl;
	cout << "tail " << tail->data << endl;	
	
    return 0;
}
