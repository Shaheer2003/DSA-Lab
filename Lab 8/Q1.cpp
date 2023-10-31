#include <bits/stdc++.h>
using namespace std;
template<typename T>
class Queue{
	class QNode{
		public:
		T data;
		QNode * next;
		QNode(T data){
			this->data=data;
			this->next=NULL;
		}
	};
	QNode* front;
	QNode* rear;
	public:
	Queue(){
		front=rear=NULL;
	}
	bool empty(){
		return (front == NULL);
	}
	void push(T data){
        if(!front){
            QNode *newNode = new QNode(data);
            front=rear=newNode;
        }
        else{
            QNode* newNode = new QNode(data);
            rear->next = newNode;
            rear = newNode;
        }
        
    }
	void pop(){
		if(front==NULL){
            cout << "Queue Underflow"<< endl;
        }
		else {
            QNode* temp = front;
            front = front->next;
            delete[] temp;
        }
	}
	T peek(){
		return front->data;
	}
};
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(){
        data = 0;
        left = NULL;
        right = NULL;
    }
    Node(int d){
        data=d;
        left=NULL;
        right=NULL;
    }
};

void Insert(Node* &root, int data){
    if(root == NULL){
        root = new Node(data);
        return;
    }
    if(root->left == NULL){
        Node* temp = new Node(data);
        root->left = temp;
        return;
    }
    else if(root->right == NULL){
        Node* temp = new Node(data);
        root->right = temp;
        return;
    }

    if(root->left != NULL){
        Insert(root->left, data);
    }
    else if(root->right != NULL){
        Insert(root->right, data);
    }
    
    return;
}

void levelOrderTrav(Node* root){
    Queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty()){
        Node* temp = q.peek();
        
        q.pop();

        if(temp == NULL){
            cout << endl;
            if(!q.empty())
                q.push(NULL);
        }
        else {
            cout << temp->data << " "; 
            if(temp->left!=NULL){
                q.push(temp->left);
            }
            if(temp->right!=NULL){
                q.push(temp->right);
            }
        }
    }
}
        //level order trav se height nikaal kr dekhna hai..
int height(Node* root){
    int count = 0;
    Queue<Node*> q;
    q.push(root);
    q.push(NULL);
    count++;
    while (!q.empty()){
        Node* temp = q.peek();
        
        q.pop();

        if(temp == NULL){
            if(!q.empty()){
                q.push(NULL);
                count++;
            }
        }
        else {
            if(temp->left!=NULL){
                q.push(temp->left);
            }
            if(temp->right!=NULL){
                q.push(temp->right);
            }
            
        }
    }
    return count;
}

bool search(Node* root, int x){
    if(root == NULL)
         return false;
    if(root->data == x)
        return true;
    else {
        search(root->left, x);
        search(root->right, x);
    }
}

int size(Node* root){
    static int count = 0;
    if(root==NULL){
        return 0;
    }
    size(root->left);
    size(root->right);
    count++;
    return  count;
}

Node* predecessor(Node* root){
    Node* temp = root;
    while(temp->left != NULL){
        temp = temp->left;
    }
    return temp;
}

Node* deleteNode(Node* root, int x){
    if(root == NULL){
        return root;
    }
    if(root->data == x){
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }
        if(root->left == NULL && root->right != NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }
        if(root->left != NULL && root->right == NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        if(root->left != NULL && root->right != NULL){
            int pre = predecessor(root->left)->data;
            root->data = pre;
            root->left = deleteNode(root->left, pre);
            return root;
        }
    }
    else if(x > root->data){
        root->right = deleteNode(root->right, x);
        return root;
    }
    else if(x < root->data){
        root->left = deleteNode(root->left, x);
        return root;
    }
}

int main(){
    Node* root = NULL;
    Insert(root, 1);
    Insert(root, 3);
    Insert(root, 7);
    Insert(root, 5);
    Insert(root, 11);
    Insert(root, 17);
    levelOrderTrav(root);
    cout << "Height of BT : " << height(root) << endl;
    cout << "Size of BT : " << size(root) << endl;
    if(search(root,7)) cout << "7 Found" << endl;
    else cout << "7 Not Found" << endl;
    if(search(root,69)) cout << "69 Found" << endl;
    else cout << "69 Not Found" << endl;
    deleteNode(root,7);
    levelOrderTrav(root);
    return 0;
}