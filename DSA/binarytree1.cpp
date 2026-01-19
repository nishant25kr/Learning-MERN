#include <iostream>
#include <queue>
#include <stack>
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

void preorder(Node* head ){
    if(head == nullptr) return;
    cout<<head->data;
    preorder(head->left);
    preorder(head->right);
}

void preorderUsingStack(Node* head){
    vector<int>preorder;
    if(head == NULL) return preorder;

    stack<Node* >st;
    st.push(head);
    while (!st.empty())
    {
        head = st.top();
        st.pop();
        preorder.push_back(head->data);
        if(head->right != NULL){
            st.push(head->right);
        }
        if(head->left != NULL){
            st.push(head->left);
        }
    }
    return preorder;
}

void inorder(Node* root ){
    if(root == nullptr) return;
    inorder(root->left);
    cout<<root->data;
    inorder(root->right);
}

void levelOrder(Node* root){
    vector<vector<int>> ans;
    if(root == nullptr) return ans;
    queue<Node*>q;
    while (!q.empty())
    {
        int n = q.size();
        vector<int>temp;
        q.push(root);
        for(int i=0;i<n;i++){
            Node* top = q.front();
            q.pop();
            temp.push_back(top->data);

            if(top->left != nullptr) q.push(top->left);
            if(top->right != nullptr) q.push(top->right);
        }
        ans.push_back(temp);
    }
}

int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    // preorder(root);
    inorder(root);

}