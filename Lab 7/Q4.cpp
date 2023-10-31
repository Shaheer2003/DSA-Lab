#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    int priority;
    Node(int d, int p){
        data = d;
        next = NULL;
        priority = p;
    }

};

class Queue {
public:
    Node* front;
    Node* rear;

    Queue() {
        front = NULL;
        rear = NULL;
    }

    void enqueue(int x, int p) {
        Node* newNode = new Node(x,p);
        if(rear == NULL){
            front = rear = newNode;
        }
        else {
            Node* prev = NULL;
            Node* curr = front;
            while( (curr!=NULL) &&(curr->priority < p)){
                prev = curr;
                curr = curr->next;
            }
            if(prev==NULL){
                front = newNode;
            }
            else {
                prev->next=newNode;
            }
            newNode->next = curr;
        }
    }

    void dequeue() {
        if(front==NULL){
            cout << "Queue Underflow"<< endl;
        }
        else {
            Node* temp = front;
            front = front->next;
            delete[] temp;
        }
    }

    int peek() {
    	if(front==NULL){ 
            cout << "Queue is Empty" << endl;
            return -1;
        }
        else return front->data;
    }

    bool empty() {
        return (front==NULL);
    }
};

int main() {
    Queue q;
    bool isEmpty;
    q.enqueue(1,3);
    q.enqueue(2,2);
    q.enqueue(3,1);
    cout << "front element is: " << q.peek() << endl;
    q.dequeue();
    cout << "front element is: " << q.peek() << endl;
     q.dequeue();
     isEmpty = q.empty();
     if(!isEmpty) cout << "Queue is Not Empty" << endl;
     else cout << "Queue is Empty" << endl;
     q.dequeue();
     isEmpty = q.empty();
     if(!isEmpty) cout << "Queue is Not Empty" << endl;
	 else cout << "Queue is Empty" << endl;
    
    return 0;
}