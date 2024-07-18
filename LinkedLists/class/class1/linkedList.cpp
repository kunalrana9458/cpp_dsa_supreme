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

// traversing a Linked List
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

void insertAtHeadTT(Node*& head,Node*& tail,int data){
    Node* newNode=new Node(data);
    if(head==nullptr){
        head=newNode;
        tail=newNode;
    }
    else{
        newNode->next=head;
        head=newNode;
    }
}
int main()
{
    cout << "Enter the size of the Linked List" << endl;
    int n;
    cin >> n;;
    cout << "Enter the nodes of the Linked Lists" << endl;
    Node* head=nullptr;
    Node* tail=nullptr;
    for(int i=0;i<n;i++){
        int data;
        cin >> data;
        insertAtTailLL(head,tail,data);
    }
    cout << head->data << endl;
    printLL(head);
    return 0;
}