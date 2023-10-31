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

Node* createfromPreOrder(vector<int> pre, int &count){
    if(count >= pre.size()){
        return NULL;
    }
    Node* root = new Node(pre[count]);
    count++;
    
    root->left = createfromPreOrder(pre, count);
    root->right = createfromPreOrder(pre, count);
    return root;
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

void Preorder(Node* root){
    if(root == NULL)
        return;

    cout << root->data << " ";
    Preorder(root->left);
    Preorder(root->right);
}

int main(){
    Node* root = NULL;
    vector<int> preorder = {1,2,4,5,3,6,7};
    // int size;
    // cout << "Enter Array Size" << endl;
    // cin >> size;
    // cout << "Enter Array" << endl;
    // for(int i=0; i<size; i++){
    //     int temp;
    //     cin >> temp;
    //     preorder.push_back(temp);
    // }
    // for(int i=0; i<preorder.size();i++){
    //     cout << preorder[i] << " "; 
    // }
    int count = 0;
    root = createfromPreOrder(preorder,count);
    cout << endl;
    Preorder(root);





    return 0;
}