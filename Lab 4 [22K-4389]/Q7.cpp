#include <iostream>
using namespace std;

class Node{
	public:
    int data;
    Node *next;
	Node *prev;

    Node(){
        data = 0;
        next = NULL;
		prev = NULL;
    }

    Node(int d){
        data = d;
        next = NULL;
		prev = NULL;
    }

    ~Node(){
        next = NULL;
        prev = NULL;
    }
};

class CircDoublyLinkedList{
	public:
    Node *head;
    Node *tail;

    CircDoublyLinkedList(){
        head = NULL;
		tail = NULL;
    }

    CircDoublyLinkedList(Node *n){
        head = n;
        tail = n;
    }


    void insertatHead(int d){
        Node *temp = new Node(d);
        if (head == NULL){
            head = temp;
			tail = temp;
            tail -> next = head;
        }
        else{
        	
            temp -> next = head;
            head -> prev = temp;
            tail -> next = temp;
            temp -> prev = tail;
            head = temp;
        }
    }

    void insertatTail(int d){
        Node *temp = new Node(d);
        if (tail == NULL){
            head = temp;
			tail = temp;
            temp->next = head;
        }
        else{
        	
            tail -> next = temp;
            temp -> prev = tail;
            temp -> next = head;
            head -> prev = temp;
            tail = temp;
        }
    }
    
    void insertatGivenPos(int pos, int d){
        Node *temp = head;
        int count = 1;
        if (pos == 1){
            insertatHead(d);
            return;
        }
        while(count<pos-1){
            temp = temp->next;
            count++;
        }
        if (temp -> next == NULL){
            insertatTail(d);
            return;
        }
        Node *newNode = new Node(d);
        newNode -> next = temp -> next;
        temp -> next -> prev = newNode;
        temp -> next = newNode;
        newNode -> prev = temp;
    }

    void deleteatPos(int pos){
    	//assuming data is present in list
        Node *pre = NULL;
        Node *curr = head;
        int count = 1;
        if (head == NULL){
            cout << "Empty List" << endl;
        }
        if (pos == 1){
            Node *temp = head;
            head = head -> next;
            temp -> next = NULL;
            head -> prev = tail;
            delete temp;
            return;
        }
    
        while (count<pos){
            pre = curr;
            curr = curr -> next;
            count++;
        }
        if(curr -> next == head){
            tail = pre;
            pre -> next = head;
        }
        curr -> next -> prev = curr -> prev;
        curr -> prev = NULL;
        pre -> next = curr -> next;
        curr -> next = NULL;
        delete curr;
        
    }

    void updateNode(int pos, int d){
        Node *temp = head;
        int count = 1;
        while (count<pos){
            temp = temp -> next;
            count++;
        }
        temp -> data = d;
    }
    
    void print(){
        Node *temp = head;
        do{
            cout << temp -> data << " ";
            temp = temp -> next;
        }while (temp != head);
    }
};

class NodeSingle{
	public:
    NodeSingle *next;
    CircDoublyLinkedList *doublyaddress;

    NodeSingle(){
        next = NULL;
        doublyaddress = NULL;
    }

    NodeSingle(CircDoublyLinkedList *head){
        doublyaddress = head;
        next = NULL;
    }

    ~NodeSingle(){
            next = NULL;
    }
};

class SingleLinkedList{
	public:
    NodeSingle *head;
    NodeSingle *tail;

    SingleLinkedList(){
        head = NULL;
		tail = NULL;
    }

    SingleLinkedList(NodeSingle *n){
        head = n;
        tail = n;
    }

    void insertatHead(CircDoublyLinkedList *head){
        NodeSingle *temp = new NodeSingle(head);
        if (head == NULL){
            this -> head = tail = temp;
        }
        else{
            temp -> next = this -> head;
            this -> head = temp;
        }
    }
    
    void insertatTail(CircDoublyLinkedList *head){
        NodeSingle *temp = new NodeSingle(head);
        if (tail == NULL){
            this -> head = tail = temp;
        }
        else{
            tail -> next = temp;
            tail = temp;
        }
    }

    void insertatGivenPos(int pos, CircDoublyLinkedList *head){
        NodeSingle *temp = this -> head;
        int count = 1;
        if (pos == 1){
            insertatHead(head);
            return;
        }
        while (count<pos-1){
            temp = temp -> next;
            count++;
        }
        if (temp -> next == NULL){
            insertatTail(head);
            return;
        }
        NodeSingle *newNode = new NodeSingle(head);
        newNode -> next = temp -> next;
        temp -> next = newNode;
    }

    void deleteatPos(int pos){
        NodeSingle *pre = NULL;
        NodeSingle *curr = head;
        int count = 1;
        if (head == NULL){
            cout << "Empty List" << endl;
        }
        if (pos == 1){
            NodeSingle *temp = head;
            head = head -> next;
            temp -> next = NULL;
            delete temp;
            return;
        }
        while(count < pos){
            pre = curr;
            curr = curr->next;
            count++;
        }
        if(curr->next == NULL){
            tail = pre;
            pre->next = NULL;
        }
        pre->next = curr->next;
        curr->next = NULL;
        delete curr;
    }

    void updateNode(int pos, CircDoublyLinkedList *head){
        NodeSingle *temp = this->head;
        int count = 1;
        while (count<pos){
            temp = temp->next;
            count++;
        }
        temp -> doublyaddress = head;
    }
    
    void print(){
        NodeSingle *temp = head;
        while (temp != NULL){
            cout << temp -> doublyaddress << " ";
            temp = temp -> next;
        }
    }
};

class LinkedList2D{
    public:
    SingleLinkedList headptrs;
    int row; 
	int col;

    LinkedList2D(){
        row = 0;
		col = 0;
    }

    void insertatHead(int r, int data){
        if (r>row){
            CircDoublyLinkedList *list = new CircDoublyLinkedList();
            list -> insertatHead(data);
            headptrs.insertatTail(list);
            row++;
            return;
        }
		       
        int countRow = 1;
        NodeSingle *temp = headptrs.head;
        while (countRow<r){
            temp = temp->next;
            countRow++;
        }
        temp -> doublyaddress -> insertatHead(data);
        
    }

    void insertatTail(int r, int data){
        if (r>row){
            CircDoublyLinkedList *list = new CircDoublyLinkedList();
            list -> insertatTail(data);
            headptrs.insertatTail(list);
            row++;
            return;
        }
        
        int countRow = 1;
        NodeSingle *temp = headptrs.head;
        while(countRow<r){
        	temp = temp -> next;
            countRow++;
        }
        temp -> doublyaddress -> insertatTail(data);
        
    }
    
    void insertPos(int row, int col, int data){
        int countRow = 1;
        NodeSingle *temp = headptrs.head;
        while (countRow < row){
            temp = temp -> next;
            countRow++;
        }
        temp -> doublyaddress -> insertatGivenPos(col,data);
    }
	
    void deletePos(int row, int col){
        int countRow = 1;
        NodeSingle *temp = headptrs.head;
        while (countRow<row){
            temp = temp -> next;
            countRow++;
        }
        temp -> doublyaddress -> deleteatPos(col);
    }

    void updateNode(int r, int c, int data){
        int countRow = 1;
        NodeSingle *temp = headptrs.head;
        while (countRow<r){
            temp = temp -> next;
            countRow++;
        }
        temp -> doublyaddress -> updateNode(c, data);
    }

    void print(){
        NodeSingle *currentRow = headptrs.head;
        for (int i = 0; i < row; i++){
            cout << "Row " << i << " { ";
            currentRow -> doublyaddress -> print();
            cout << "}" << endl;
            currentRow = currentRow -> next;
        }
        cout << endl;
    }
};

int main(){
    LinkedList2D list;   
    list.insertatHead(1,2);
    list.insertatHead(1,1);
    list.insertatTail(1,3);
    list.insertatTail(1,4);
	list.print();
    list.insertatHead(2,3);
    list.insertatHead(2,4);
    list.insertatTail(2,2);
    list.insertatTail(2,1);
	list.print();
	list.insertatHead(3,7);
    list.insertatTail(3,69);
    list.insertatTail(3,420);
    list.insertatTail(3,404);
	list.print();
    list.insertatTail(4,2);
    list.insertatTail(4,9);
    list.insertatTail(4,11);
    list.insertatHead(4,5);
	list.print();
    list.insertPos(3, 2, 6);   
    list.deletePos(1, 2);
    list.updateNode(2, 2, 5);
    list.deletePos(4, 4);
    list.print();
    
    
    return 0;
}
