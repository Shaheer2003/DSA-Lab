#include <iostream>
#include <string>
using namespace std;

template<class T>
class Node{
    public:
    T data;
    Node* next;
    
    Node(){
        this -> data = 0;
        this -> next = NULL;
    }
    
    Node(T d){
        this -> data = d;
        this -> next = NULL;
    }
};

template<class T>
class SingleLinkedList{
    public:
	Node<T>* head;
    Node<T>* tail;
    SingleLinkedList(){
        this -> head = NULL;
        this -> tail = NULL;
    }
    SingleLinkedList(Node<T> *h, Node<T> *t){
        this -> head = h;
        this -> tail = t;
    }
    
    int len(){
    	Node<T>* temp = head;
    	int count = 0;
    	while (temp != NULL){
        	count++;
        	temp = temp -> next;
    	}
    	return count;
	}
    
    void print(){
    	Node<T>* temp = head;
    	while (temp != NULL){
        	cout << temp -> data << " ";
        	temp = temp -> next;
    	}
    	cout << endl;
	}
	
	void insertatHead(T d){
		if(tail != NULL){
			Node<T>* temp = new Node<T>(d);
	    	temp -> next = head;
	    	head = temp; 
		}
		else{
			Node<T>* temp = new Node<T>(d);
	    	head = temp;
	    	tail = temp;
		}
	}

	void insertatTail(T d){
		if(head != NULL){
			Node<T>* temp = new Node<T>(d);
		    tail -> next = temp;
		    tail = temp;
		}
		else {
			
			Node<T>* temp = new Node<T>(d);
		    temp -> next = tail;
		    head = temp;
		    tail = temp;
		}		
	}

    void checkPalindrome(){
		if (len() < 3) {
            cout << "Invalid List" << endl;
            return;
        }

        Node<T>* temp = head;
        SingleLinkedList<T> revList;
        while (temp != NULL) {
            revList.insertatHead(temp->data);
            temp = temp->next;
        }

        temp = head;
        Node<T>* newTemp = revList.head;
        while (temp != NULL && newTemp != NULL) {
            if (temp -> data != newTemp	-> data) {
                cout << "Linked List is not a Palindrome" << endl;
                return;
				//isPalindrome = false;
				//break;
            }
            temp = temp -> next;
            newTemp = newTemp -> next;
        }
        cout << "Linked List is a Palindrome" << endl; 
    }
	
};

int main(){
	SingleLinkedList<int> list1;
	list1.insertatHead(1);
	list1.insertatTail(0);
	list1.insertatTail(2);
	list1.insertatTail(0);
	list1.insertatTail(1);
    list1.print();
	list1.checkPalindrome();

	SingleLinkedList<char> list2;
	list2.insertatHead('a');
	list2.insertatTail('b');
	list2.insertatTail('c');
	list2.insertatTail('b');
	//list2.insertatTail('a');
	list2.print();
	list2.checkPalindrome();

    return 0;
}
