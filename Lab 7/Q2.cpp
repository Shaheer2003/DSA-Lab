#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int d){
        data = d;
        next = NULL;
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

    void enqueue(int x) {
        if(rear == NULL){
            Node* newNode = new Node(x);
            front = rear = newNode;
        }
        else {
            Node* newNode = new Node(x);
            rear->next = newNode;
            rear = newNode;
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
        return (front == NULL);
    }
};

int main() {
    Queue q;
    bool isEmpty;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
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