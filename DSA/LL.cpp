#include <iostream>
#include <vector>
using namespace std;
struct Node
{
public:
    int data;
    Node *next;

public:
    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }

public:
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};
Node *convertarrtoLL(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *mover = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

Node *removehead(Node *head)
{
    if (head == NULL)
        return head;
    Node *temp = head;
    head = head->next;
    delete temp;
    return head;
}

int lengthofLL(Node *head)
{
    int cnt = 0;
    Node *temp = head;
    while (temp)
    {
        temp = temp->next;
        cnt++;
    }
    return cnt;
}

void print(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// delete the tail of the LL
Node *deletetail(Node *head)
{
    if (head == NULL || head->next == NULL)
        return NULL;
    Node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
    return head;
}

// deleting the kth element from the LL
Node *deletekth(Node *head, int k)
{
    if (head == NULL)
        return head;
    if (k == 1)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    Node *temp = head;
    Node *prev = NULL;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        if (count == k)
        {
            prev->next = prev->next->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}
// insert in tail
Node *insertattail(Node *head, int val)
{
    if (head == NULL)
    {
        return new Node(val);
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    Node *newNode = new Node(val);
    temp->next = newNode;
    return head;
}

Node *reverse(Node *head){
    Node* temp=head;
    Node* prev = NULL;
    Node* next = NULL;
    while (temp!=NULL)
    {
        next = temp->next;
        temp -> next = prev;
        prev=temp;
        temp=next;
    }
    return prev;
    
}

int main()
{
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);
    Node *head = convertarrtoLL(arr);
    Node *temp = head;
    cout << "This is the linked list -> ";

    // while (temp)
    // {
    //     cout<< temp->data <<" ";
    //     temp=temp->next;

    // }
    // cout<<endl;

    // cout<<"Length of the LL -> "<<lengthofLL(head);

    // cout<<endl;

    // head=removehead(head);

    // head=deletetail(head);

    // head=deletekth(head,2);
    head=reverse(head);

    // head = insertattail(head, 100);
    print(head);
}