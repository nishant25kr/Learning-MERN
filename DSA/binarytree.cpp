#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    Node(int val){
        data=val;
        left=nullptr;
        right=nullptr;
    }
};

void preorder(Node* root){
    if(root==nullptr)
        return;  
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root){
    if(root==nullptr)
        return;  
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void printleft(Node* root){
    if(root == NULL){
        return ;
    }
    cout<<root->data;
    printleft(root->left);
}

void pot_usingstack(Node* root){
    if(root == NULL) return ;
    stack<Node*> s1,s2;
    s1.push(root);
    while (!s1.empty())
    {
        root = s1.top();  // Get top node from s1
        s1.pop();
        // cout<<root->data;
        s2.push(root);
        if(root->left != NULL){
            s1.push(root->left);
        }
        if(root->right != NULL){
            s1.push(root->right);
        }
    }
    while (!s2.empty())
    {
        cout<<s2.top()->data<<" ";
        s2.pop();
    }
}

bool isLeaf(Node* cur) {
    return cur && cur->left == nullptr && cur->right == nullptr;
}


void addleft(Node* root ,vector<int> &res){
    Node* cur=root->left;
    while (cur)
    {
        if(!isLeaf(cur)) res.push_back(cur->data);
        if(cur->left) cur=cur->left;
        else cur=cur->right;
    }
}

void addleaf(Node* root ,vector<int> &res){
    if(isLeaf(root)){
        res.push_back(root->data);
        return;
    }
    if(root->left) addleaf(root->left,res);
    if(root->right) addleaf(root->right,res);

}
void addright(Node* root ,vector<int> &res){
    vector<int> tmp;
    Node* cur=root->right;
    while (cur)
    {
        if(!isLeaf(cur)){
            tmp.push_back(cur->data);
        }
        if(cur->right) cur=cur->right;
        else cur=cur->left;
        for (int i = 0; i < tmp.size(); i++)
        {
            res.push_back(tmp[i]);
        }
        
    }

}
void printboundries(Node* root){
    vector<int> res;
    addleft(root,res);
    addleaf(root,res);
    addright(root,res);
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }

}




int main(){

    struct Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    root->right->right=new Node(7);

    // preorder(root);
    // inorder(root);
    // printleft(root);
    // pot_usingstack(root);
    printboundries(root);

    return 0;
}