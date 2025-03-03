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

void pot_usingstack(Node *root)
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
    if (root==NULL) return ;

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

            if(node->left)  q.push(make_pair(node->left, idx * 2 + 1));

            if(node->right) q.push(make_pair(node->right, idx * 2 + 2));
        }
    }
    cout<< maxW;
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
    maxWidth(root);

    return 0;
}