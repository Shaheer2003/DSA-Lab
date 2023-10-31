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

void Inorder(Node* root){
    if(root == NULL)
        return;

    Inorder(root->left);
    cout << root->data << " ";
    Inorder(root->right);
}

Node* LCA(Node* root, Node* node1, Node* node2){
    if(root == NULL){
        return NULL;
    }
    if(root->data < node1->data && root->data < node2->data){
        return LCA(root->right, node1, node2);
    }
    if(root->data > node1->data && root->data > node2->data){
        return LCA(root->left, node1, node2);
    }

    return root;
}

int main(){
    Node* root = NULL;
    Insert(root,5);
    Insert(root,7);
    Insert(root,3);
    Insert(root,10);
    Insert(root,1);
    Insert(root,17);
    Inorder(root);
    cout << endl;

    Node* Lca = LCA(root,root->right,root->left->left);
    cout << Lca->data << endl;


    return 0;
}