#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data=data;
        this->next=nullptr;
    }
};
Node* reverseLL(Node* head){
    Node* prev=nullptr;
    Node* curr=head;
    Node* forward=nullptr;
    while(curr!=nullptr){
        forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
    }
    return prev;
}
int main()
{
    return 0;
}
