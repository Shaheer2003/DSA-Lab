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

void insertatHead(Node* &head, Node* &tail, int d){ // Q3
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

void insertatTail(Node* &tail, Node* &head, int d){
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

void insertatGivenPos(Node* &head, Node* &tail, int pos, int d){
	Node* temp = head;
	int count = 1;
	if(pos == 1){
		insertatHead(head, tail, d);
		return;
	}
	
	while(count < pos-1){
		temp = temp -> next;
		count++;
		if (temp->next == NULL){
			insertatTail(tail,head,d);
			return;
		}
	}
	Node* newnode = new Node(d);
	newnode -> next = temp -> next;
	temp -> next = newnode;

}

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
    
    insertatGivenPos(head,tail,1,10);
    print(head);
    
    insertatGivenPos(head,tail,2,11);
    print(head);

	insertatGivenPos(head,tail,2,15);
    print(head);

	insertatGivenPos(head,tail,3,20);
    print(head);

	insertatGivenPos(head,tail,4,35);
    print(head);	
	
	cout << "head " << head->data << endl;
	cout << "tail " << tail->data << endl;	
	
    return 0;
}