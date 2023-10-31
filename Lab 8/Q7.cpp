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

Node* BinaryExpressionTree(string infix, int lb, int ub, Node* root) {
    
    if(lb>=ub){
        root = new Node(infix[lb]);
        return root;
    }

    int prec;
    pair<int,int> symbol; //first is precedence, second is index
    symbol.first = 4;
    symbol.second = 0;
    for(int i=lb;i<=ub;i++){
        if(infix[i] == '*' || infix[i] == '/' || infix[i] == '+' || infix[i] == '-' || infix[i] == '^'){
            prec = precedence(infix[i]);
            if(prec <= symbol.first){
                symbol.first = prec;
                symbol.second = i;
            }
        }
    }
    // cout << symbol.first << " " << infix[symbol.second] << " " << symbol.second << endl;
    // getchar();
    root = new Node(infix[symbol.second]);
    root->left = BinaryExpressionTree(infix,lb,symbol.second-1,root->left);
    root-> right = BinaryExpressionTree(infix,symbol.second+1,ub,root->right);
    
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

void Inorder(Node* root){
    if(root == NULL)
        return;

    Inorder(root->left);
    cout << root->data << " ";
    Inorder(root->right);
}

int evaluate(Node* root){
    if(root->left == NULL && root->right == NULL){
        return (root->data)-48;
    }

    int val;
    if(root->data == '+' || root->data == '-' || root->data == '/' || root->data == '*' || root->data == '^'){
        
        int op1 = evaluate( root->left);
        int op2 = evaluate( root->right);
        if(root->data == '+'){
            val = op1 + op2;
        }
        else if(root->data == '-'){
            val = op1 - op2;
        }
        if(root->data == '*'){
            val = op1 * op2;
        }
        if(root->data == '/'){
            val = op1 / op2;
        }
        if(root->data== '^'){
            val = pow(op1, op2);
        }
         
    }
    return val;

}

int main(){
    Node* root = NULL;
    string infix = "2+3*4-8/2^3";
    int len = infix.size();
    root = BinaryExpressionTree(infix,0,len-1,root);
    Levelorder(root);
    cout << endl;
    cout << "Answer of Expression : " <<  evaluate(root);


    return 0;
}