#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(){
        data = 0;
        left = right = NULL;
    }
    Node(int d){
        data = d;
        left = right = NULL;
    }
};

void Inorder(Node* root){
    if(root == NULL)
        return;

    Inorder(root->left);
    cout << root->data << " ";
    Inorder(root->right);
}

void Preorder(Node* root){
    if(root == NULL)
        return;

    cout << root->data << " ";
    Preorder(root->left);
    Preorder(root->right);
}

void Postorder(Node* root){
    if(root == NULL)
        return;

    Postorder(root->left);
    Postorder(root->right);
    cout << root->data << " ";
}

void Levelorder(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty()){
        Node* temp = q.front();
        
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

void Insert(Node* &root, int data){
    if(root == NULL){
        root = new Node(data);
        return;
    }

    if(root->data == data){
        cout << "Invalid Value" << endl;
        return;
    }

    if(data < root->data)
        Insert(root->left, data);
    
    else if(data > root->data)
        Insert(root->right, data);
    
    return;
}

int main(){
    Node* root = NULL;
    Insert(root,5);
    Insert(root,7);
    Insert(root,3);
    Insert(root,10);
    Insert(root,1);
    Insert(root,17);
    cout << "Inorder Traversal : ";
    Inorder(root);
    cout << endl;
    cout << "Preorder Traversal : ";
    Preorder(root);
    cout << endl;
    cout << "Postorder Traversal : ";
    Postorder(root);
    cout << endl;
    cout << "Levelorder Traversal : " << endl;
    Levelorder(root);
    cout << endl;

    return 0;
}