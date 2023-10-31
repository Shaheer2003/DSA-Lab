#include<bits\stdc++.h>
using namespace std;
#define nl "\n"
template<typename T>
class Queue{
	class Node{
		public:
		T data;
		int priority;
		Node * next;
		Node(T data,int priority){
			this->data=data;
			this->next=NULL;
			this->priority=priority;
		}
		~Node(){
			if(!this->next){
				this->next=NULL;
				delete next;
			}
		}
	};
	Node*front;
	Node*rear;
	int n;
	public:
	Queue(){
		front=rear=NULL;
		n=0;
	}
	int size(){
		return n;
	}
	bool isEmpty(){
		return n==0;
	}
	void enqueue(T data, int priority){
        Node *temp = new Node(data,priority);
        if(!front){
            front=rear=temp;
        }
        else{
            Node *prev=NULL;
            Node *curr=front;
            while(curr&&curr->priority<priority){
                prev=curr;
                curr=curr->next;
            }
            if(prev){
                prev->next=temp;
            }
            else{
                front=temp;
            }
            temp->next=curr;
        }
        n++;
    }
	void dequeue(){
		if(isEmpty())return;
		Node*temp=front;
		front=front->next;
		delete temp;
		n--;
	}
	T peek(){
		return front->data;
	}
	void print(){
		Node*temp=front;
		while(temp){
			cout<<temp->data<<"\t";
			temp=temp->next;
		}
		cout<<nl;
	}
};
int main() {
    Queue<int> p;
    p.enqueue(10, 2);
    p.enqueue(20, 1);
    p.enqueue(30, 3);
    p.enqueue(40, 2);
    cout<<"Size: "<< p.size()<<nl;

    cout<<"peek: "<<p.peek()<<nl;

    p.print();

    p.dequeue();
    p.print();
    

}

