#include <iostream>
#include <vector>
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

void preorder(Node *root)
{
    if (root == nullptr)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node *root)
{
    if (root == nullptr)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void printleft(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data;
    printleft(root->left);
}

void lot_usingstack(Node *root)
{
    if (root == NULL)
        return;
    stack<Node *> s1, s2;
    s1.push(root);
    while (!s1.empty())
    {
        root = s1.top(); // Get top node from s1
        s1.pop();
        // cout<<root->data;
        s2.push(root);
        if (root->left != NULL)
        {
            s1.push(root->left);
        }
        if (root->right != NULL)
        {
            s1.push(root->right);
        }
    }
    while (!s2.empty())
    {
        cout << s2.top()->data << " ";
        s2.pop();
    }
}

bool isLeaf(Node *cur)
{
    return cur && cur->left == nullptr && cur->right == nullptr;
}

void addleft(Node *root, vector<int> &res)
{
    Node *cur = root->left;
    while (cur)
    {
        if (!isLeaf(cur))
            res.push_back(cur->data);
        if (cur->left)
            cur = cur->left;
        else
            cur = cur->right;
    }
}

void addleaf(Node *root, vector<int> &res)
{
    if (isLeaf(root))
    {
        res.push_back(root->data);
        return;
    }

    if (root->left)
        addleaf(root->left, res);

    if (root->right)
        addleaf(root->right, res);
}
void addright(Node *root, vector<int> &res)
{
    vector<int> tmp;
    Node *cur = root->right;
    while (cur)
    {
        if (!isLeaf(cur))
        {
            tmp.push_back(cur->data);
        }
        if (cur->right)
            cur = cur->right;
        else
            cur = cur->left;
        for (int i = 0; i < tmp.size(); i++)
        {
            res.push_back(tmp[i]);
        }
    }
}
void printboundries(Node *root)
{
    vector<int> res;
    addleft(root, res);
    addleaf(root, res);
    addright(root, res);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
}

// checkouting the height of the tree

int height(Node *root)
{
    if (root == NULL)
        return 0;

    int lh = height(root->left);
    int rh = height(root->right);

    return 1 + max(lh, rh);
}
void levelorder(Node *root)
{
    if (!root)
        return; // Edge case: Empty tree

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int s = q.size();
        vector<int> level; // Stores values of the current level

        for (int i = 0; i < s; i++)
        {
            Node *node = q.front();
            q.pop();
            level.push_back(node->data);

            if (node->left != NULL)
                q.push(node->left);
            if (node->right != NULL)
                q.push(node->right);
        }
        // Print the level
        // for (int val : level) {
        //     cout << val << " ";
        // }
        // cout << endl;  // Print new line after each level
    }
}
void sideview(Node *root, int level, vector<int> &rsv)
{
    if (root == NULL)
        return;
    if (rsv.size() == level)
    {
        rsv.push_back(root->data);
    }
    sideview(root->right, level + 1, rsv);
    sideview(root->left, level + 1, rsv);
}

void rightsideview(Node *root)
{
    vector<int> rsv;
    sideview(root, 0, rsv);
    // for (int val : rsv) {
    //     cout << val << " ";
    // }
}

Node *lowestcommonansister(Node *root, Node *p, Node *q)
{
    if (root == NULL)
        return NULL;

    if (root == p || root == q)
    {
        return root;
    }

    Node *leftN = lowestcommonansister(root->left, p, q);
    Node *rightN = lowestcommonansister(root->right, p, q);

    if (leftN != NULL && rightN != NULL)
        return root;

    if (leftN != NULL)
        return leftN;
    else
        return rightN;
}

// maximum width of tree
void maxWidth(Node *root)
{
    if (root == NULL)
        return;

    queue<pair<Node *, int> > q;

    // q.push({root,0});
    q.push(make_pair(root, 0));

    int maxW = 0;
    while (!q.empty())
    {
        int LS = q.front().second;
        int RS = q.back().second;

        maxW = max(maxW, RS - LS + 1);
        int s = q.size();
        while (s--)
        {
            Node *node = q.front().first;
            int idx = q.front().second;
            q.pop();

            if (node->left)
                q.push(make_pair(node->left, idx * 2 + 1));

            if (node->right)
                q.push(make_pair(node->right, idx * 2 + 2));
        }
    }
    cout << maxW;
}

// counting the nodes
int countnodes(Node *root, vector<int> &res)
{

    if (root == NULL)
        return 0;

    countnodes(root->left, res);
    res.push_back(root->data);
    countnodes(root->right, res);

    return res.size();
}

// // void flatter(Node* root){

// // }

// void flatter_toLL(Node* root){
//     Node* prev= NULL;
//     if(root == NULL) return;
//     flatter_toLL(root->right);
//     flatter_toLL(root->left);
//     root->right = prev;
//     root->left = NULL;
//     prev=root;
// }

// total path to go to the node

bool search(Node *root, vector<int> &res, int n)
{

    if (root == NULL)
        return false;

    res.push_back(root->data);

    if (root->data == n)
        return true;

    if (search(root->left, res, n) || search(root->right, res, n))
        return true;

    res.pop_back();

    return false;
}

void path_to_Node(Node *root, int n)
{
    vector<int> res;

    // if(root == NULL) return res;

    cout << search(root, res, n);

    cout << endl;
    cout << "Path is: ";
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
}

// paths to go to the NULL
// void printPaths(vector<vector<int> > &allpaths)
// {
//     for (vector<int> &path : allpaths)
//     { // Explicit type instead of 'auto'
//         for (size_t i = 0; i < path.size(); i++)
//         { // Explicit loop instead of range-based for
//             cout << path[i] << " ";
//         }
//         cout << endl; // New line after each path
//     }
// }

void path(Node *root, vector<int> &currentpath, vector<vector<int> > &allpath)
{
    if (root == NULL)
        return;
    currentpath.push_back(root->data);

    if (root->left == NULL && root->right == NULL)
    {
        allpath.push_back(currentpath);
    }
    else
    {
        path(root->left, currentpath, allpath);
        path(root->right, currentpath, allpath);
    }
    currentpath.pop_back();
}

void path_to_NULL(Node *root)
{
    vector<vector<int> > allpath;
    vector<int> currentpath;

    path(root, currentpath, allpath);
    // printPaths(allpath);
}


//

bool check_sum(Node* root){
    if(root!= nullptr && root->left != NULL && root->right != NULL){

        if(root->data == root->left->data + root->right->data){
            check_sum(root->left);
            check_sum(root->right);
        }else{
            return false;
        }

    }
    return true;
}

bool check_sum_of_clildisNODE(Node *root)
{
    if (root == NULL) return 0;
    
    return check_sum(root);
}

//top view           

void rightview(Node* root,vector<int> &res){
    if(root== NULL) return ;
    res.push_back(root->data);
    rightview(root->right, res);
}

void leftview(Node* root,vector<int> &res){
    if(root==NULL) return;
    res.push_back(root->data);
    leftview(root->left, res);
}

void topview(Node *root){
    vector<int >res;
    leftview(root,res);
    reverse(res.begin(),res.end());
    rightview(root->right,res);

    for (int i = 0; i < res.size(); i++)
    {
        cout<<res[i]<< " ";
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

    int n = 5;
    // preorder(root);
    // inorder(root);
    // printleft(root);
    // pot_usingstack(root);
    // printboundries(root);

    // int h=height(root);
    // cout<<h;

    // levelorder(root);
    // rightsideview(root);
    // Node* l=lowestcommonansister(root, root->left->left, root->left->right);
    // cout<<l->data;
    // maxWidth(root);

    // countnodes(root,res);

    // flatter_toLL(root);
    // cout<<res.size();
    // path_to_Node(root,n);

    // path_to_NULL(root);

//    cout<<check_sum_of_clildisNODE(root);
    topview(root);

    return 0;
}