#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    char data;
    Node* left;
    Node* right;
    Node(){
        data = 0;
        left = NULL;
        right = NULL;
    }
    Node(char d){
        data=d;
        left=NULL;
        right=NULL;
    }
};

int precedence(char op){
    if(op == '+' || op == '-'){
        return 1;
    }
    else if(op == '/' || op == '*'){
        return 2;
    }
    else if(op == '^'){
        return 3;
    }
}

Node* infixToPostfix(string infix, int lb, int ub, Node* root) {
    
    if(lb>=ub){
        root = new Node(infix[lb]);
        return root;
    }

    int prec;
    pair<int,int> symbol; //first is precedence, second is index
    symbol.first = 4;
    symbol.second = 0;
    for(int i=lb;i<ub;i++){
        if(infix[i] == '*' || infix[i] == '/' || infix[i] == '+' || infix[i] == '-' || infix[i] == '^'){
            prec = precedence(infix[i]);
            if(prec <= symbol.first){
                symbol.first = prec;
                symbol.second = i;
            }
        }
    }
    root = new Node(infix[symbol.second]);
    root->left = infixToPostfix(infix,lb,symbol.second-1,root->left);
    root-> right = infixToPostfix(infix,symbol.second+1,ub,root->right);
    
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

int main(){
    Node* root = NULL;
    string infix = "5+1-2*9+4-1/2*5+3";
    int len = infix.size();
    root = infixToPostfix(infix,0,len,root);
    Levelorder(root);









    return 0;
}