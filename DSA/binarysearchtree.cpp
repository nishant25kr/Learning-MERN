#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data; // Corrected initialization
        left = nullptr;
        right = nullptr;
    }
};

// Function to insert a new node into the BST
Node *insert(Node *root, int value)
{
    if (root == nullptr)
    {
        return new Node(value);
    }
    if (value < root->data)
    {
        root->left = insert(root->left, value);
    }
    else
    {
        root->right = insert(root->right, value);
    }
    return root;
}

// deleting the node

Node *findlastright(Node *root)
{
    if (root->right == NULL)
    {
        return root;
    }
    return findlastright(root->right);
}

Node *Helper(Node *root)
{

    if (root->left == NULL)
    {
        return root->right;
    }
    if (root->right == NULL)
    {
        return root->left;
    }
    Node *right = root->right;
    Node *lastright = findlastright(root->left);
    lastright->right = right;

    return root->left;
}

// Node *deletenode(Node *root, int val)
// {
//     if (root == NULL)
//     {
//         return NULL;
//     }
//     if (root->data == val)
//     {
//         return Helper(root);
//     }
//     while (root)
//     {
//         if (root->data > val)
//         {
//             if (root->left != NULL and root->left->data == val)
//             {
//                 root->left = Helper(root->left);
//                 break;
//             }
//             else
//             {
//                 root = root->left;
//             }
//         }
//         else
//         {
//             if (root->right != NULL and root->right->data == val)
//             {
//                 root->right = Helper(root->right);
//                 break;
//             }
//             else
//             {
//                 root = root->right;
//             }
//         }
//     }
// }




void inorderts(Node *root, vector<int> &res)
{
    if (root != nullptr)
    {
        inorderts(root->left, res);  
        res.push_back(root->data);   
        inorderts(root->right, res); 
    }
}



bool two_sum(Node *root, int k)
{
    vector<int> res;
    inorderts(root, res); 

    int left = 0, right = res.size() - 1;
    while (left < right)
    {
        int sum = res[left] + res[right];
        if (sum == k)
            return 1;
        else if (sum < k)
            left++;
        else
            right--;
    }
    return 0;
}

//check bst

bool check(Node* root,long minVal, long maxVal){
    if(root == NULL) return 1;

    if(root->data < minVal || root->data > maxVal) return 0;

    return check(root->left,minVal,root->data) && check(root->right,root->data,maxVal);
}

bool check_bst(Node* root){
    // if(root == NULL) return 0;

    return check(root,INT_MIN,INT_MAX);

}


int main()
{
    Node *root = nullptr;
    root = insert(root, 4);
    insert(root, 2);
    insert(root, 6);
    insert(root, 1);
    insert(root, 3);
    insert(root, 5);
    insert(root, 7);

    // struct Node *root = new Node(1);
    // root->left = new Node(2);
    // root->right = new Node(3);
    // root->left->left = new Node(4);
    // root->left->right = new Node(5);
    // root->right->left = new Node(6);
    // root->right->right = new Node(7);

    // cout << "Inorder Traversal of BST: ";
    // inorder(root);
    // cout << endl;

    // cout<<"BST after deleting the node";
    // deletenode(root,3);
    // inorder(root);

    // cout<<two_sum(root, 4);

    cout<<check_bst(root);
    

    return 0;
}
