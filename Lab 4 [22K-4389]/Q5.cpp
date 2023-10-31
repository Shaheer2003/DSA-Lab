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
    
    ~Node(){
        int val = this -> data;
            next = NULL;
		cout << "Destructor Called for Value " << val << endl;
	}
};

class CircularLinkedList{
    public:
    Node* head;
    Node* tail;

    CircularLinkedList(){
        this -> head = NULL;
        this -> tail = NULL;
    }

    CircularLinkedList(Node *n){
        this -> head = n;
        this -> tail = n;
    }

    void insertatHead(int data){
        if(head == NULL){
            Node *temp = new Node(data);
            tail = head = temp;
        }
        else {
            Node *temp = new Node(data);
            temp -> next = head;
            head = temp;
            tail->next = head;
        }
    }

    void insertatTail(int data){
        if(tail == NULL){
            Node *temp = new Node(data);
            head = tail = temp;
        }
        else {
            Node *temp = new Node(data);
            tail -> next = temp;
            tail = temp;
            temp -> next = head;
        }
    }

//    void insertatGivenPos(int pos, int d){
//        Node* temp = head;
//        int count = 1;
//        if(pos == 1){
//            insertatHead(d);
//            return;
//        }
//        
//        while(count < pos-1){
//            temp = temp -> next;
//            count++;
//            if (temp->next == head){
//                insertatTail(d);
//                return;
//            }
//        }
//        Node* newnode = new Node(d);
//        newnode -> next = temp -> next;
//        temp -> next = newnode;
//    }

    void print(){
        Node* temp = head;  
        if(temp != NULL){
            do{
                cout << temp -> data << " ";
                temp = temp -> next;
            }while(temp != head);
        }
        cout << endl;
    }

//    void deleteatanyPos(int pos){
//        //assuming the position given is valid
//        Node* prev = NULL;
//        Node* curr = head;
//        int count = 1;
//        if(pos == 1){
//            head = head -> next;
//            tail->next = head;
//            delete curr;
//            return;
//        }
//
//        while(count < pos){
//            prev = curr;
//            curr = curr -> next;
//            count++;
//        }
//        prev -> next = curr -> next;
//        if(curr->next == head){
//            tail = prev;
//        }
//        curr -> next = NULL;
//        delete curr;
//    }

//    void updateGivenVal(int val, int d){
//        Node* temp = head;
//        while(temp->data != val){
//            temp = temp -> next;
//            if(temp -> next == head && temp -> data != val){		
//                cout << "Value Does not exist" << endl;
//                return;
//            }
//        }	
//        temp -> data = d;
//    }
	CircularLinkedList reverse (){
		CircularLinkedList list;
		Node* temp = head;  
        if(temp == NULL){
    		cout << "Empty List" << endl;
		}
		else {
		    do{
                list.insertatHead(temp->data);
                temp = temp -> next;
            }while(temp != head);
		return list;
		}
	}

};

int main(){
    CircularLinkedList list;
    CircularLinkedList revlist;
    list.insertatTail(1);
    list.insertatTail(2);
    list.insertatTail(3);
	list.insertatTail(4);
	list.insertatTail(5);
    list.print();
    revlist = list.reverse();
    revlist.print();
    cout << revlist.head->data << endl;
    cout << revlist.tail->data << endl;


    return 0;   
}