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

void inputLL(int n,Node*& head,Node*& tail){
    // Node* head=nullptr;
    // Node* tail=nullptr;
    for(int i=0;i<n;i++){
        int data;
        cin >> data;
        insertAtTail(head,tail,data);
    }
}

void reverseLL(Node* head){
    Node* prev=nullptr;
    Node* curr=head;
    Node* forward=nullptr;
    while(curr!=nullptr){
        forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
    }
}

void printLL(Node* head){
    Node* temp=head;
    while(temp!=nullptr){
        cout << temp->data << " ";
        temp=temp->next;
    }
}

Node* addTwoLL(Node* head1,Node* head2){
    Node* temp1=head1;
    Node* temp2=head2;
    Node* ansHead=nullptr;
    Node* ansTail=nullptr;
    int carry=0;
    while(temp1!=nullptr && temp2!=nullptr){
        int sum=temp1->data+temp2->data+carry;
        int digit=sum%10;
        insertAtTail(ansHead,ansTail,digit);
        carry=sum/10;
        temp1=temp1->next;
        temp2=temp2->next;
    }
    while (temp1!=nullptr)
    {
        int sum=temp1->data+carry;
        int digit=sum%10;
        insertAtTail(ansHead,ansTail,digit);
        carry=sum/10;
        temp1=temp1->next;
    }
    while(temp2!=nullptr){
        int sum=temp2->data+carry;
        int digit=sum%10;
        insertAtTail(ansHead,ansTail,digit);
        carry=sum/10;
        temp2=temp2->next;
    }
    if(carry!=0){
        insertAtTail(ansHead,ansTail,carry);
    }
    return ansHead;
}

int main()
{
    cout << "Enter the size of firstList" << endl;
    int n1;
    cin >> n1;
    Node* list1Head=nullptr;
    Node* list1Tail=nullptr;
    inputLL(n1,list1Head,list1Tail);
    Node* list2Head=nullptr;
    Node* list2Tail=nullptr;
    cout << "Enter the size of the Second Linked List" << endl;
    int n2;
    cin >> n2;
    inputLL(n2,list2Head,list2Tail);
    reverseLL(list1Head);
    reverseLL(list2Head);
    Node* ans=addTwoLL(list1Head,list2Tail);
    reverseLL(ans);
    printLL(ans);
    return 0;
}