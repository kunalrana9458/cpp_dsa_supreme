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
void printLL(Node*& head){
    Node* temp=head;
    while(temp!=nullptr){
        cout << temp->data << " ";
        temp=temp->next;
    }
}

Node* recursiveFunc(Node*& prev,Node*& curr){
    // base case
    if(curr==nullptr){
        return prev;
    }
    // recursive function
    Node* forward=curr->next;
    curr->next=prev;
    prev=curr;
    curr=forward;
    return recursiveFunc(prev,curr);
}

Node* reverseLL(Node* head){
    Node* prev=nullptr;
    Node* curr=head;

    Node* newHead=recursiveFunc(prev,curr);
    return newHead;
}
int main(){
    int n;
    cin >> n;
    Node* head=nullptr;
    Node* tail=nullptr;
    for(int i=0;i<n;i++){
        int data;
        cin >> data;
        insertAtTailLL(head,tail,data);
    }
    Node* ans=reverseLL(head);
    printLL(ans);
    return 0;
}