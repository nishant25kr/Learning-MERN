#include<iostream>
using namespace std;

struct Node
{
    public:
    int data;
    Node* next;
    Node* prev;

    public:
    Node(int data1, Node* next1, Node* prev1){
        data = data1;
        next = next1;
        prev = prev1;
    }

    public:
    Node(int data1){
        data = data1;
        next = nullptr;
        prev = nullptr;
    }

};

Node* convert_Arr2LL(vector<int > &nums){
    Node* head = new Node(nums[0]);
    Node* prev = head;
    for(int i = 1; i < nums.size(); i++){
        Node* temp = new Node(nums[i]);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

void print_DLL(Node* head){
    Node * temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

Node* insert_DLL(Node* head,int data){
    Node* newNode = new Node(data);
    
    if(head == nullptr) return newNode;

    Node* temp = head;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    temp -> next = newNode;
    newNode->prev = temp;

    return head;
}

Node* delete_node(Node* head, int ind){
    int cnt = 0;
    Node* temp = head;
    while(temp){
        if(cnt == ind-1){
            temp->next = temp->next->next;
            temp->next->prev = temp;

        }
        cnt++;
        temp = temp->next;
    }
    return head;
}

Node* reverse(Node* head){
    if(head == nullptr || head->next == nullptr){
        return head;
    }
    
    Node* curr = head;
    Node* temp = nullptr;

    while(curr!=nullptr){
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;

        curr = curr->prev;
    }
    return temp->prev;
    
}
int main(){
    vector<int > nums = {1,2,3,4,5};
    Node *head = convert_Arr2LL(nums);
    // print_DLL(head);
    Node* head1 = insert_DLL(head,21);
    // Node* head2 = delete_node(head1,3);
    Node* head3 = reverse(head);
    print_DLL(head3);

    return 0;
}