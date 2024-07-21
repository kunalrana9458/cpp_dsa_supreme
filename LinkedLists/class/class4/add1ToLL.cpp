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
void insertAtTail(Node*& head,Node*& tail,int data){
    Node* newNode=new Node(data);
    if(head==nullptr && tail==nullptr){
        head=newNode;
        tail=newNode;
    }
    else{
        tail->next=newNode;
        tail=newNode;
    }
}
void print(Node* head){
    Node* temp=head;
    while (temp!=nullptr)
    {
        cout << temp->data << " ";
        temp=temp->next;
    }
}

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

Node* add1ToLL(Node* head){
    // firstly we reverse a Linked list
    head=reverseLL(head);
    Node* temp=head;
    // add 1 to the Linked List
    int carry=1;
    while(temp!=nullptr && carry!=0){
        int sum=temp->data+carry;
        int digit=sum%10;
        carry=sum/10;
        temp->data=digit;
        if(temp->next==nullptr) break;
        temp=temp->next;
    }
    // if carry remains and not a 0 then create new Node of carry and add it to the ans
     if(carry!=0){
            Node* newNode=new Node(carry);
            temp->next=newNode;
        }
    // again reverse a linked list
    head=reverseLL(head);
    return head;
}

int main()
{
    cout << "Enter the size of the Linked list" << endl;
    int n;
    cin >> n;
    Node* head=nullptr;
    Node* tail=nullptr;
    for(int i=0;i<n;i++){
        int data;
        cin >> data;
        insertAtTail(head,tail,data);
    }
    Node* ans=add1ToLL(head);
    print(ans);
    return 0;
}