#include <iostream>
#include <vector>
using namespace std;
struct Node
{
public:
    int data;
    Node *next;
    Node *back;

public:
    Node(int data1, Node *next1, Node *back1)
    {
        data = data1;
        next = next1;
        back = back1;
    }

public:
    Node(int data1)
    {
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

Node *convert2DLL(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *prev = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i], NULL, prev);
        prev->next = temp;
        prev = temp;
    }

    return head;
}

void print(Node *head)
{
    Node *temp = head;
    cout << "This is the LL -> ";
    while (temp != NULL)
    {
        // cout<<temp->back<<" ";
        cout << temp->data << " ";
        // cout<<temp->next<<" ";

        temp = temp->next;
    }
}

// deleting head of DLL
Node *deletehead(Node *head)
{
    if (head == NULL || head->next == NULL)
        return NULL;
    Node *temp = head;
    head = temp->next;
    head->back = NULL;
    delete temp;
    return head;
}

// deleting the tail of DLL
Node *deletetail(Node *head)
{
    if (head == NULL || head->next == NULL)
        return NULL;
    Node *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->back->next = NULL;
    // delete temp->next;
    // temp->next=NULL;
    return head;
}

// deleting the kth element

Node *deletekthele(Node *head, int k)
{
    if (head == NULL)
        return NULL;
    int count = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        count++;
        if (count == k)
            break;
        temp = temp->next;
    }
    if (temp->next == NULL)
    {
        return deletetail(head);
    }
    else if (temp->back == NULL)
    {
        return deletehead(head);
    }
    else if (temp->next and temp->back == NULL)
    {
        return NULL;
    }

    Node *back = temp->back;
    Node *next = temp->next;

    back->next = next;
    next->back = back;
    delete temp;

    return head;
}
// deleting the node of DLL
void deleteNode(Node *temp)
{
    Node *back = temp->back;
    Node *next = temp->next;
    if (next == NULL)
    {
        back->next = nullptr;
        next->back = nullptr;
        delete temp;
        return;
    }
    back->next = next;
    next->back = back;

    temp->next = temp->back = nullptr;
    delete temp;
}
// inserting before the head of DLL
Node *insertbeforehead(Node *head, int k)
{
    Node *newhead = new Node(k, head, nullptr);
    head->back = newhead;
    return newhead;
}

// iserting the new tail of the DLL
Node *insert_at_tail(Node *head, int val)
{
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    Node *newtail = new Node(val, nullptr, temp);
    temp->next = newtail;
    return head;
}

// insert at the kth positio of the DLL

Node *inser_at_kth_positon(Node *head, int k, int val)
{
    if (k == 0)
    {
        Node *newhead = new Node(k, head, nullptr);
        head->back = newhead;
        return newhead;
    }
    int count = 0;
    Node *temp = head;
    while (temp->next != NULL)
    {
        count++;
        if (count == k)
            break;
        temp = temp->next;
    }
    Node *next = temp;
    Node *back = temp->back;

    Node *newele = new Node(val, next, back);
    back->next = newele;
    next->back = newele;
    return head;
}

int main()
{
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);
    Node *head = convert2DLL(arr);
    // head=deletehead(head);
    // head=deletetail(head);
    // head=deletekthele(head,2);
    // deleteNode(head->next->next);
    // head=insertbeforehead(head,0);
    // head=insert_at_tail(head,5);
    head = inser_at_kth_positon(head, 0, 0);
    print(head);
}