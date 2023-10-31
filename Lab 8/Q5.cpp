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

bool isSame(Node* root, Node* root1){
    if(root == NULL && root1 == NULL)
        return true;
    if((root == NULL && root1 != NULL) || (root1 == NULL && root != NULL))
        return false;

    bool rightAns = isSame(root->left,root1->left);
    bool leftAns = isSame(root->right,root1->right);
    if(root->data == root1->data && leftAns && rightAns)
        return true;
    else return false;
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

    Node* root1 = NULL;
    Insert(root1, 1);
    Insert(root1, 3);
    Insert(root1, 7);
    Insert(root1, 5);
    Insert(root1, 11);
    Insert(root1, 17);
    Levelorder(root1);

    Node* root2 = NULL;
    Insert(root2, 1);
    Insert(root2, 3);
    Insert(root2, 7);
    Insert(root2, 5);
    Insert(root2, 11);
    Insert(root2, 69);
    Levelorder(root2);

    if(isSame(root,root1)) cout << "Both Trees are Same " << endl;
    else cout << "Both Trees are not Same " << endl;

    if(isSame(root1,root2)) cout << "Both Trees are Same " << endl;
    else cout << "Both Trees are not Same " << endl;











    return 0;
}