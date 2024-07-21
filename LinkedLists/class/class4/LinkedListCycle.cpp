#include<iostream>
#include<unordered_map>
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
bool hasCycle(Node* head){
    Node* slow=head;
    Node* fast=head;
    while(fast!=nullptr){
        fast=fast->next;
        slow=slow->next;
        if(fast!=nullptr){
            fast=fast->next;
        }
        if(fast==slow){
            return true;
        }
    }
    return false;
}
int main()
{

    return 0;
}