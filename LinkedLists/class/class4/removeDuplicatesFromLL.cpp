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
void printLL(Node* head){
    Node* temp=head;
    while(temp!=nullptr){
        cout << temp->data << " ";
        temp=temp->next;
    }
}
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

Node *removeDuplicates(Node *head)
{
 // your code goes here
 if(head==nullptr || head->next==nullptr) return head;
 Node* prev=head;
 Node* temp=head->next;
 while(temp!=nullptr){
     if(prev->data==temp->data){
         prev->next=temp->next;
         temp->next=nullptr;
         delete temp;
         temp=prev->next;
     }
     else{
         prev=temp;
         temp=temp->next;
     }
 }
 return head;
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
    Node* ans=removeDuplicates(head);
    cout << endl;
    printLL(ans);
    return 0;
}