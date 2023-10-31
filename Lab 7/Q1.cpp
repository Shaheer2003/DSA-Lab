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

class Stack {
public:
    Node* top;
    Stack() {
        top = NULL;
    }

    void push(int x) {
        if(top == NULL){
            Node* newNode = new Node(x);
            top = newNode;
        }
        else {
            Node* newNode = new Node(x);
            newNode->next = top;
            top = newNode;
        }
    }

    void pop() {
        if(top==NULL){
            cout << "Stack Underflow"<< endl;
        }
        else {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }

    int peak() {
    	if(top==NULL){ 
            cout << "Stack is Empty" << endl;
            return -1;
        }
        else return top->data;
    }

    bool empty() {
        return top == NULL;
    }
};

int main() {
    Stack s;
    bool isEmpty;
    s.push(1);
    s.push(2);
    s.push(3);
    cout << "Top element is: " << s.peak() << endl;
    s.pop();
    cout << "Top element is: " << s.peak() << endl;
    s.pop();
    isEmpty = s.empty();
    if(!isEmpty) cout << "Stack is Not Empty" << endl;
    else cout << "Stack is Empty" << endl;
    s.pop();
    isEmpty = s.empty();
    if(!isEmpty) cout << "Stack is Not Empty" << endl;
	else cout << "Stack is Empty" << endl;
    
    return 0;
}