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

/*
int length_of_loop(Node* head){
    Node* slow = head;
    Node* fast = head;
    
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            slow = head;
            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
            slow = slow->next;
            int count = 1;
            while(slow != fast){
                count++;
                slow = slow->next;
            }
            return count;
            
        }
    }
}
*/

Node* removeNthFromEnd(Node* head, int k){
    
    Node* temp1 = head;
    Node* temp2 = head;

    while(k > 0){
        temp2 = temp2->next;
        k--;
    }
    
    if(temp1 == NULL) return head->next;

    while(temp1->next != NULL){
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    temp1->next = temp1->next->next;
    return head;

}

Node* add2LL(Node* head1,Node* head2){
    Node* dummyNode = new Node(-1);
    Node* curr = dummyNode;
    Node* t1 = head1;
    Node* t2 = head2;
    int carry = 0;

    while(t1 != NULL || t2 != NULL){
        
        int sum = carry;

        if(t1) sum+=t1->data;
        if(t2) sum+=t2->data;

        Node* newNode = new Node(sum%10);
        carry = sum/10;

        curr->next = newNode;
        curr = curr->next;

        if(t1) t1 = t1->next;
        if(t2) t2 = t2->next;

    }
    if(carry){
        Node* newNode = new Node(carry);
        curr->next = newNode;
    }
    return dummyNode->next;

}

int main(){
    
    vector<int > nums1 = {1,1,1};
    vector<int > nums2 = {4,3,2};
    Node *head1 = convert_Arr2LL(nums1);
    Node *head2 = convert_Arr2LL(nums2);
    // Print(head);
    // cout<<countLength(head);
    // cout<<search(head,35);
    // Node* head1 = deleteNode(head,0);
    // Print(head1);
    // Node* head1 = removeNthFromEnd(head, 1);
    // Print(head1);
    Node* sum = add2LL(head1,head2);
    Print(sum);
    
}