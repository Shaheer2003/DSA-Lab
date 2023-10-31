#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    int priority;
    int sec;
    Node(int d, int p, int s){
        data = d;
        next = NULL;
        priority = p;
        sec = s;
    }

};

class Queue {
public:
    Node* front;
    Node* rear;
    int ram;

    Queue() {
        front = NULL;
        rear = NULL;
        ram = 0;
    }

    void enqueue(int x, int p, int s) {
        Node* newNode = new Node(x,p,s);
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
        ram+=x;
    }

    void dequeue() {
        if(front==NULL){
            cout << "Queue Underflow"<< endl;
        }
        else {
            Node* temp = front;
            front = front->next;
            ram-=temp->data;
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

    void print() {
        Node* temp = front;
        while (temp!=NULL) {
            cout << "RAM : "<< temp->data << endl << "Sec : " << temp->sec << endl <<"Priority : "<< temp->priority <<endl;
            temp = temp->next;
        }
        cout << endl;
    }

};

    bool spawnproc(){ 
        return (rand() % 100 + 1) <= 15;
    }

    int get_prior(){
        return (rand() % 20 + 1);
    }

    int get_ram(){
        return (rand() % 5000 + 1);
    }

    int get_sec(){
        return (rand() % 10 + 1);
    }

    void killProc(Queue q, int r) {
        Node* head = q.front;
        Node* curr = head;
        Node* prev = NULL;
        if (head == NULL) 
            return;

        q.ram-=r;
        if (head->data == r) {
            Node* temp = q.front;
            q.front = q.front->next;
            delete temp;
            return;
        }
        while (curr != NULL && curr->data != r) {
            prev = curr;
            curr = curr->next;
        }
        if (curr != NULL) {
            prev->next = curr->next;
            curr->next = NULL;
            delete curr;
        }
        
    }

int main() {      // Question is not running for some reason function error: 'get_ram' was not declared in this 
                  //      scope. This error is being shown for all class functiuons
	srand(time(0));
    Queue proc;
    Queue wait;
    for (int i = 0; i < 100; i++) {
        if (spawnproc()) {
            int RAM = get_ram();
            int priority = get_prior();
            int sec = get_sec();
            if ((proc.ram) + RAM <= 2000) {
                proc.enqueue(RAM, priority, sec);
            } 
            else if (!(proc.empty()) && proc.rear->priority > priority) {
                while(proc.ram + RAM > 2000){
                	wait.enqueue(proc.rear->data,proc.rear->priority,proc.rear->sec);
                	killProc(proc, proc.rear->data);
				}
                proc.enqueue(RAM, priority, sec);
            }
            else{
            	wait.enqueue(RAM, priority, sec);
			}
        }
        proc.print();              
    }
    
    return 0;
}