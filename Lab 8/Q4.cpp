#include <bits/stdc++.h>
using namespace std;

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

void InsertBST(Node* &root, int data){
    if(root == NULL){
        root = new Node(data);
        return;
    }

    if(root->data == data){
        cout << "Invalid Value" << endl;
        return;
    }

    if(data < root->data)
        InsertBST(root->left, data);
    
    else if(data > root->data)
        InsertBST(root->right, data);
    
    return;
}


bool isBST(Node* root){
    if(root == NULL){
        return false;
    }
    if (root->right != NULL && root->right->data < root->data){
        return false;
    }
    if (root->left != NULL && root->left->data > root->data){
        return false;
    }
    return true;
    return isBST(root->left);
    return isBST(root->right);
}

bool isFullBT(Node* root){
    if(root == NULL){
        return false;
    }
    if (root->right != NULL && root->left == NULL){
        return false;
    }
    if (root->left != NULL && root->right == NULL){
        return false;
    }
    return true;
    return isFullBT(root->left);
    return isFullBT(root->right);
}

bool isPerfectBT(Node* root){
    if(root == NULL)
        return false;
    int h = height(root);
    int s = size(root);
    return (pow(2,h)-1 == s); // formula for max number of nodes
}

bool isDegenBT(Node* root){
    if(root == NULL)
        return false;
    if(root->right == NULL && root->left == NULL)
        return true;
    if(root->right != NULL && root->left != NULL)
        return false;
    if(root->right != NULL && root->left == NULL){
        isDegenBT(root->right);
    }
    if(root->left != NULL && root->right == NULL){
        isDegenBT(root->left);
    }
    return true;
}

bool isCompBT(Node* root) {
    if (root == NULL)
        return true;

    queue<Node*> q;
    q.push(root);
    
    bool leaf = false;

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();

        if (curr != NULL) {
            if (leaf)
                return false;
            q.push(curr->left);
            q.push(curr->right);
        } else {
            leaf = true;
        }
    }

    return true;
}

int main(){
    Node* root = NULL;
    Insert(root, 1);
    Insert(root, 3);
    Insert(root, 7);
    Insert(root, 5);
    Insert(root, 11);
    Insert(root, 17);
    Levelorder(root);
    if(isBST(root)) cout << "Is A BST" << endl;
    else cout << "Isnot A BST" << endl;

    Node* root1 = NULL;
    InsertBST(root1, 5);
    InsertBST(root1, 3);
    InsertBST(root1, 7);
    InsertBST(root1, 1);
    InsertBST(root1, 11);
    InsertBST(root1, 4);
    InsertBST(root1, 6);
    Levelorder(root1);
    if(isBST(root1)) cout << "Is A BST" << endl;
    else cout << "Isnot A BST" << endl;

    if(isFullBT(root1)) cout << "Is A Full BT" << endl;
    else cout << "Isnot A Full BT" << endl;

    if(isPerfectBT(root1)) cout << "Is A Perfect BT" << endl;
    else cout << "Isnot A Perfect BT" << endl;

    Node* root2 = NULL;
    InsertBST(root2, 1);
    InsertBST(root2, 3);
    InsertBST(root2, 7);
    InsertBST(root2, 2);
    Levelorder(root2);
    if(isDegenBT(root2)) cout << "Is A Degenerate BT" << endl;
    else cout << "Isnot A Degenerate BT" << endl;

    Node* root3 = NULL;
    InsertBST(root3, 6);
    InsertBST(root3, 3);
    InsertBST(root3, 7);
    InsertBST(root3, 2);
    Levelorder(root3);
    if(isCompBT(root3)) cout << "Is A Complete BT" << endl;
    else cout << "Isnot A Complete BT" << endl;

    return 0;
}