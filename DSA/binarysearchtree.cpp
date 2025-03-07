#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;  // Corrected initialization
        left = nullptr;
        right = nullptr;
    }
};

// Function to insert a new node into the BST
Node* insert(Node* root, int value) {
    if (root == nullptr) {
        return new Node(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }
    return root;
}


//deleting the node

Node* findlastright(Node* root){
    if(root->right == NULL){
        return root;
    }
    return findlastright(root->right);
}

Node* Helper(Node* root){

    if(root->left == NULL){
        return root->right;
    }
    if(root->right == NULL){
        return root->left;
    }
    Node* right=root->right;
    Node* lastright = findlastright(root->left);
    lastright->right=right;

    return root->left;

}


Node* deletenode(Node* root,int val){
    if(root == NULL){
        return NULL;
    }
    if(root->data == val){
        return Helper(root);
    }
    while (root)
    {
        if (root->data > val)
        {
            if (root->left != NULL and root->left->data == val)
            {
                root->left= Helper(root->left);
                break;
            }else{
                root=root->left;
            }
        }else{
            if (root->right != NULL and root->right->data == val)
            {
                root->right = Helper(root->right);
                break;
            }else{
                root=root->right;
            }
        }
    }
}


// Function to perform inorder traversal of BST (Left, Root, Right)
void inorder(Node* root) {
    if (root != nullptr) {
        cout << root->data << " ";
        inorder(root->left);
        inorder(root->right);
    }
}

int main() {
    Node* root = nullptr;
    root = insert(root, 4);
    insert(root, 2);
    insert(root, 6);
    insert(root, 1);
    insert(root, 3);
    insert(root, 5);
    insert(root, 7);

    cout << "Inorder Traversal of BST: ";
    inorder(root);
    cout << endl;

    cout<<"BST after deleting the node";
    deletenode(root,3);
    inorder(root);
    cout << endl;




    return 0;
}
