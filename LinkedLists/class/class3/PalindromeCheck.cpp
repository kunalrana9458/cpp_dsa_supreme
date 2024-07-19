#include<iostream>
using namespace std;
class ListNode{
    public:
    int val;
    ListNode* next;
    ListNode(int val){
        this->val=val;
        this->next=nullptr;
    }
};

ListNode* getMiddle(ListNode* head,ListNode*& middleNodePrev){
    ListNode* slow=head;
    ListNode* fast=head;
    while(fast!=nullptr){
        fast=fast->next;
        if(fast!=nullptr){
            fast=fast->next;
            middleNodePrev=slow;
            slow=slow->next;
        }
    }
    return slow;
}

ListNode* reverseLL(ListNode*& prev,ListNode*& curr){
    while(curr!=nullptr){
        ListNode* forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
    }
    return prev;
}
int llPalin(ListNode* A) {
    if(A==nullptr || A->next==nullptr) return 1;
    // travel till middle node and break the LL into two halves
    ListNode* middleNodePrev=nullptr;
    ListNode* middleNode=getMiddle(A,middleNodePrev);
    middleNodePrev->next=nullptr;
    // reverse a second halves
    ListNode* prev=nullptr;
    ListNode* curr=middleNode;
    ListNode* secondHalfHead=reverseLL(prev,curr);
    ListNode* temp=A;
    // compare both the halves
    // even length case dono part ki length equal hogi
    // odd wala case second half ki length baadi hogi by 1
    // that why comparison hamesha compare acc to first half length
    while(temp!=nullptr){
        if(temp->val != secondHalfHead->val) return 0;
        temp=temp->next;
        secondHalfHead=secondHalfHead->next;
    }
    return 1;
}

int main()
{
    return 0;
}