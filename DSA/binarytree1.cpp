#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

/* ------------------ Recursive Traversals ------------------ */


void preorder(Node* root) {
    if (!root) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

/* ------------------ Iterative Preorder ------------------ */

vector<int> preorderUsingStack(Node* root) {
    vector<int> result;
    if (!root) return result;

    stack<Node*> st;
    st.push(root);

    while (!st.empty()) {
        Node* curr = st.top();
        st.pop();
        result.push_back(curr->data);

        if (curr->right) st.push(curr->right);
        if (curr->left) st.push(curr->left);
    }
    return result;
}

/* ------------------ Level Order Traversal ------------------ */

vector<vector<int>> levelOrder(Node* root) {
    vector<vector<int>> ans;
    if (!root) return ans;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int n = q.size();
        vector<int> level;

        for (int i = 0; i < n; i++) {
            Node* curr = q.front();
            q.pop();

            level.push_back(curr->data);

            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
        ans.push_back(level);
    }
    return ans;
}

/* ------------------ Right Side View ------------------ */

vector<int> rightSideView(Node* root) {
    vector<int> ans;
    if (!root) return ans;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int n = q.size();

        for (int i = 0; i < n; i++) {
            Node* curr = q.front();
            q.pop();

            if (i == n - 1)
                ans.push_back(curr->data);

            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
    }
    return ans;
}

/* ------------------ Symmetric Tree ------------------ */

bool isMirror(Node* root1, Node* root2) {
    if (!root1 && !root2) return true;
    if (!root1 || !root2) return false;

    return (root1->data == root2->data) &&
           isMirror(root1->left, root2->right) &&
           isMirror(root1->right, root2->left);
}

bool isSymmetric(Node* root) {
    if (!root) return true;
    return isMirror(root->left, root->right);
}

/* ------------------ Driver Code ------------------ */

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(4);
    root->right->right = new Node(3);

    // cout << "Preorder: ";
    // preorder(root);
    // cout << endl;

    // cout << "Inorder: ";
    // inorder(root);
    // cout << endl;

    // cout << "Postorder: ";
    // postorder(root);
    // cout << endl;

    // cout << "Iterative Preorder: ";
    // vector<int> pre = preorderUsingStack(root);
    // for (int x : pre) cout << x << " ";
    // cout << endl;

    // cout << "Level Order:\n";
    // vector<vector<int>> levels = levelOrder(root);
    // for (auto level : levels) {
    //     for (int x : level) cout << x << " ";
    //     cout << endl;
    // }

    // cout << "Right Side View: ";
    // vector<int> rightView = rightSideView(root);
    // for (int x : rightView) cout << x << " ";
    // cout << endl;

    cout << "Is Symmetric Tree? ";
    cout << (isSymmetric(root) ? "Yes" : "No") << endl;

    return 0;
}
