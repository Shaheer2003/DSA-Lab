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

class DoublyLinkedList {
	public:
		Node* tail;
        Node* head;
        
		DoublyLinkedList(){
            head = NULL;
			tail = NULL;
		}
		DoublyLinkedList(Node* n){
			head = n;
			tail = n;
		}
		
		void insertatHead(int d){
			Node* temp = new Node(d);
			if(head==NULL){
                head = temp;
        		tail = temp;
			}
			else{
				temp -> next = head;
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
				tail -> next  = temp;
        		temp -> prev = tail;
        		tail = temp;
			}
		}
		
		void concatList(DoublyLinkedList list2){
			tail -> next = list2.head;
			tail = list2.tail;
			tail -> next = NULL;
		}
		
//       
//		void insertatGivenPos(int d,int pos){
//			
//			if(pos==1){
//				insertatHead(d);
//				return;
//			}
//			
//			Node* temp = head;
//			int ctr = 1;
//			while(ctr < pos-1){
//				ctr++;
//				temp = temp -> next;
//					
//				if(temp->next==NULL){
//					insertatTail(d);
//					return;
//				}
//			}
//				Node* newNode=new Node(d);
//				newNode -> next = temp -> next;
//				temp -> next -> prev = newNode;
//				temp -> next = newNode;
//				newNode -> prev = temp;			
//		}
//        
//		void deleteatanyPos(int pos){
//			//assuming the position given is valid
//			Node* prev = NULL;
//	        Node* curr = head;
//	        int count = 1;
//	        if(pos == 1){
//	            curr -> next -> prev = NULL;
//        		head = curr ->next;
//        		curr -> next = NULL;
//        		delete curr;
//        		return;
//	        }
//	
//	        while(count < pos){
//	            prev = curr;
//	            curr = curr -> next;
//	            count++;
//	        }
//	        curr -> prev = NULL;
//	        prev -> next = curr -> next;
//	        if(curr->next == NULL){
//	            tail = prev;
//	        }
//	        curr -> next = NULL;
//	        delete curr;
//		}
//        
//        void updateGivenVal(int val, int d){
//	        Node* temp = head;
//	        while(temp->data != val){
//	            temp = temp -> next;
//	            if(temp -> next == NULL && temp -> data != val){		
//	                cout << "Value Does not exist" << endl;
//	                return;
//	            }
//	        }	
//	        temp -> data = d;
//   		}
//		
		void print(){
        	Node* temp = head;  
        	while(temp != NULL) {
        		cout << temp -> data << " ";
        		temp  = temp -> next;
    		}
    		cout << endl;
    	}

};
int main(){
	
	DoublyLinkedList list;
	DoublyLinkedList list1;
	list.insertatTail(1);
	list.insertatTail(2);
	list.insertatTail(3);
	list.print();
	list1.insertatTail(4);
	list1.insertatTail(5);
	list1.insertatTail(6);
	list1.print();
	list.concatList(list1);
	cout << "Merged List" << endl;
    list.print();
    
	cout << list.head->data << endl;
    cout << list.tail->data << endl;
 }