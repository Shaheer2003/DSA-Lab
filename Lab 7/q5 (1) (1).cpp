#include<bits/stdc++.h>
using namespace std;
#define nl "\n"
template<typename T>
class Queue {
public:
    class Node {
    public:
        T data;
        int sec;
        int priority;
        Node* next;
        Node(T data, int priority, int sec) {
            this->data = data;
            this->next = NULL;
            this->priority = priority;
            this->sec = sec;
        }
        ~Node() {
		    if (next) {
		        delete next;
		    }
		}

    };

    Node* front;
    Node* rear;
    int n;

    Queue() {
        front = rear = NULL;
        n = 0;
    }

    int RAM() {
        return n;
    }

    bool isEmpty() {
        return n == 0;
    }

    void enqueue(T data, int priority, int sec) {
        Node* temp = new Node(data, priority, sec);
        if (!front) {
            front = rear = temp;
        } else {
            Node* prev = NULL;
            Node* curr = front;
            while (curr && curr->priority < priority) {
                prev = curr;
                curr = curr->next;
            }
            if (prev) {
                prev->next = temp;
            } else {
                front = temp;
            }
            temp->next = curr;
        }
        n += data;
    }

    void dequeue() {
        if (isEmpty()) return;
        Node* temp = front;
        front = front->next;
        n -= temp->data;
        delete temp;
    }

    T peek() {
        return front->data;
    }

    void print() {
        Node* temp = front;
        while (temp) {
            cout << "RAM : "<< temp->data << "\t sec "<<temp->sec<<"\t priority "<<temp->priority<<nl;
            temp = temp->next;
        }
        cout << nl;
    }
};

bool spawn() {
    int n = rand() % 100 + 1;
    return n <= 15;
}

int getPriority() {
    return rand() % 20 + 1;
}

int getRam() {
    return rand() % 500 + 1;
}

int getSec() {
    return rand() % 10 + 1;
}

void deleteNode(Queue<int>& q, int RAM) {
	q.n-=RAM;
    Queue<int>::Node* head = q.front;
    if (head == NULL) return;
    if (head->data == RAM) {
        Queue<int>::Node* temp = q.front;
        q.front = q.front->next;
        delete temp;
        return;
    }
    Queue<int>::Node* curr = head;
    Queue<int>::Node* prev = nullptr;
    while (curr != NULL && curr->data != RAM) {
        prev = curr;
        curr = curr->next;
    }
    if (curr != NULL) {
        prev->next = curr->next;
        curr->next = nullptr;
        delete curr;
    }
    
}


void simulate() {
    Queue<int> q;
    Queue<int> waiting;
    for (int i = 0; i < 100; i++) {
        if (spawn()) {
            int RAM = getRam();
            int priority = getPriority();
            int sec = getSec();
            if (q.RAM() + RAM <= 2000) {
                q.enqueue(RAM, priority, sec);
            } else if (q.front && q.rear->priority > priority) {
                while(q.RAM() + RAM > 2000){
                	waiting.enqueue(q.rear->data,q.rear->priority,q.rear->sec);
                	deleteNode(q, q.rear->data);
				}
                q.enqueue(RAM, priority, sec);
            }
            else{
            	waiting.enqueue(RAM, priority, sec);
			}
        }

        Queue<int>::Node* temp = q.front;
        while (temp) {
            temp->sec--;
            if (temp->sec <= 0) {
                deleteNode(q,temp->data);
                if(!waiting.isEmpty()){
 	               q.enqueue(waiting.front->data,waiting.front->priority,waiting.front->sec);
 	               waiting.dequeue(); 
				}
            }
            temp = temp->next;
        }

        cout << "Second " << i + 1 << " - RAM: " << q.RAM() << " MB - Running Processes: "<<nl;
        q.print();
		cout<<nl<<nl<<nl;
    }
}

int main() {
    srand(time(0));
    simulate();
    return 0;
}
