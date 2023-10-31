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