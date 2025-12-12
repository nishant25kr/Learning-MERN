#include<iostream>
#include<vector>
using namespace std;

struct Node{
    public:
    int data;
    Node* next;

    public:
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

Node* convert_Arr2LL(vector<int > &nums){
    Node* head = new Node(nums[0]);
    Node* mover = head;
    for(int i=1;i<nums.size();i++){
        Node* temp = new Node(nums[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

void Print(Node *head){
    Node *temp = head;
    while(temp){
        cout<<temp->data;
        temp = temp->next;
    }
    cout<<endl;
}

int countLength(Node* head){
    int cnt = 0;
    Node* temp = head;
    while(temp){
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

bool search(Node* head,int target){
    Node * temp = head;
    while(temp){
        if(temp->data == target) return true;
        temp = temp->next; 
    }
    return false;
}

Node* deleteNode(Node* head, int ind){
    if(ind == 0 ) return head->next;
    int cnt = 0;
    Node * temp = head;
    while(temp){
        if(cnt == ind-1){
            Node * del = temp->next;
            temp->next = temp->next->next;
            delete(del);
            break;
        }
        temp = temp->next;
        cnt++;
    }
    return head;
}

int main(){
    vector<int > nums = {1,2,3,4,5};
    Node *head = convert_Arr2LL(nums);
    Print(head);
    // cout<<countLength(head);
    // cout<<search(head,35);
    Node* head1 = deleteNode(head,0);
    Print(head1);
    
}