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
void insertAtTailLL(Node*& head,Node*& tail,int data){
    Node* newNode=new Node(data);
    if(head==nullptr){
        head=newNode;
        tail=newNode;
    }
    else{
        tail->next=newNode;
        tail=newNode;
    }
}
int findMiddleOfLL(Node*& head){
    Node* slow=head;
    Node* fast=head;
    while(fast->next!=nullptr && fast->next->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow->data;
}
int main()
{
    int n;
    cin >> n;
    Node* head=nullptr;
    Node* tail=nullptr;
    for(int i=0;i<n;i++){
        int data;
        cin >> data;
        insertAtTailLL(head,tail,data);
    }
    int ans=findMiddleOfLL(head);
    cout << ans << endl;
    return 0;
}