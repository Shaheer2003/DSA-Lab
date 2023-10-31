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
};

class SingleLinkedList{
    Node* head;
    Node* tail;
    SingleLinkedList(){
        this -> head = NULL;
        this -> tail = NULL;
    }
    SingleLinkedList(Node *n){
        this -> head = n;
        this -> tail = n;
    }
};