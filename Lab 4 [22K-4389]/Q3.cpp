#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(){
        this -> data = 0;
        this -> next = NULL;
		this -> prev=NULL;
    }
    
    Node(int d){
        this -> data = d;
        this -> next = NULL;
		this -> prev=NULL;
    }
    
    ~Node(){
        int val = this -> data;
        next = NULL;
		cout << "Destructor Called for Value " << val << endl;
	}
};

class CircDoublyLinkedList {
	public:
		Node* tail;
        Node* head;
        
		CircDoublyLinkedList(){
            head = NULL;
			tail = NULL;
		}
		CircDoublyLinkedList(Node* n){
			head = n;
			tail = n;
		}
		
		void insertatHead(int d){
			Node* temp = new Node(d);
			if(head==NULL){
                tail = temp;
        		head = temp;
			}
			else{
				temp -> next = head;
				temp -> prev = tail;
        		head -> prev = temp;
        		head = temp;
			}
		}

		void insertatTail(int d){
			Node* temp = new Node(d);
			if(tail==NULL){
                tail = temp;
        		head = temp;
			}
			else{
        		temp -> next = tail -> next;
        		temp -> prev = tail;
				tail -> next  = temp;
        		tail = temp;
			}
		}
       
		void insertatGivenPos(int d,int pos){
			
			if(pos==1){
				insertatHead(d);
				return;
			}
			
			Node* temp = head;
			int ctr = 1;
			while(ctr < pos){
				ctr++;
				temp = temp -> next;
					
				if(temp->next==tail->next){
					insertatTail(d);
					return;
				}
			}
				Node* newNode=new Node(d);
				temp -> prev -> next = newNode;
				newNode -> prev = temp -> prev;
				temp -> prev = newNode;
				newNode -> next = temp;		
		}
        
		void deleteatanyPos(int pos){
			//assuming the position given is valid
			Node* prev = NULL;
	        Node* curr = head;
	        int count = 1;
	        if(pos == 1){
	            curr -> next -> prev = tail -> next;
        		head = curr ->next;
        		tail -> next = curr -> next;
        		curr -> next = NULL;
        		curr -> prev = NULL;
        		delete curr;
        		return;
	        }
	
	        while(count < pos){
	            prev = curr;
	            curr = curr -> next;
	            count++;
	        }
	        curr -> next -> prev = curr -> prev;
	        prev -> next = curr -> next;
	        if(curr -> next == head){
	            tail = prev;
	        }
	        curr -> next = NULL;
	        curr -> prev = NULL;
	        delete curr;
		}
        
        void updateGivenVal(int val, int d){
	        Node* temp = head;
	        while(temp->data != val){
	            temp = temp -> next;
	            if(temp -> next == head && temp -> data != val){		
	                cout << "Value Does not exist" << endl;
	                return;
	            }
	        }	
	        temp -> data = d;
   		}
		
		void print(){
        Node* temp = head;  
        if(temp != NULL){
            do{
                cout << temp -> data << " ";
                temp = temp -> next;
            }while(temp != tail->next);
        }
        cout << endl;
    	}

};
int main(){
	
	CircDoublyLinkedList list;
    list.insertatHead(3);
    list.insertatHead(2);
    list.insertatHead(1);
    list.print();
	list.insertatTail(7);
	list.insertatTail(9);
	list.insertatTail(11);
	list.print();
    list.insertatGivenPos(0,1);
    list.print();
    list.insertatGivenPos(5,5);
    list.insertatGivenPos(13,9);
    list.print();
	list.deleteatanyPos(1);
	list.print();
	list.deleteatanyPos(8);
	list.print();
	list.deleteatanyPos(3);
	list.print();
    list.updateGivenVal(5,4);
    list.print();
    list.updateGivenVal(2,3);
    list.print();
    list.updateGivenVal(69,3);
    list.print();
    
	cout << list.head->data << endl;
    cout << list.tail->data << endl;
 }