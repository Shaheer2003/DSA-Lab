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

bool search(Node* root, int x){
    if(root == NULL)
         return false;
    if(root->data == x)
        return true;
    else if(x > root->data)
        search(root->right, x);
    else if(x < root->data)
        search(root->left, x);
}

int height(Node* root){
    int count = 0;
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    count++;
    while (!q.empty()){
        Node* temp = q.front();
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
    Insert(root,5);
    Insert(root,7);
    Insert(root,3);
    Insert(root,10);
    Insert(root,1);
    Insert(root,17);
    Inorder(root);
    cout << endl;
    deleteNode(root,7);
    Inorder(root);
    cout << endl;
    if(search(root,10)) cout << "10 Found" << endl;
    else cout << "10 Not Found" << endl;
    if(search(root,69)) cout << "69 Found" << endl;
    else cout << "69 Not Found" << endl;
    cout << "Height of BST : " << height(root) << endl;
    cout << "Size of BST : " << size(root) << endl;
    return 0;
}
