#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    Node(int data){
        this->data=data;
        this->prev=nullptr;
        this->next=nullptr;
    }
};
// insertion of a linked lists
void insertAtHead(Node*& head,Node*& tail,int data){
    // if linked list is empty
    if(head==nullptr && tail==nullptr){
        Node* newNode=new Node(data);
        head=newNode;
        tail=newNode;
    }
    else{
        Node* newNode=new Node(data);
        newNode->next=head;
        head->prev=newNode;
        head=newNode;
    }
}
void insertAtTail(Node*& head,Node*& tail,int data){
    // if linekd lists is empty
    if(head==nullptr && tail==nullptr){
        Node* newNode=new Node(data);
        head=newNode;
        tail=newNode;
    }
    else{
        Node* newNode=new Node(data);
        tail->next=newNode;
        newNode->prev=tail;
        tail=newNode;
    }
}
void print(Node* head){
    Node* temp=head;
    while(temp!=nullptr){
        cout << temp->data << " ";
        temp=temp->next;
    }
    cout << endl;
}

bool searchElementInDLL(Node* head,int target){
    Node* temp=head;
    while(temp!=nullptr){
        if(temp->data==target) return true;
        temp=temp->next;
    }
    return false;
}

void insertAtPos(Node*& head,Node*& tail,int pos,int data){
    Node* prevPtr=head;
    while (pos>2)
    {
        prevPtr=prevPtr->next;
        pos--;
    }
    // creation of new Node
    Node* newNode=new Node(data);
    newNode->next=prevPtr->next;
    newNode->prev=prevPtr->next->prev;
    prevPtr->next->prev=newNode;
    prevPtr->next=newNode;
}

void deleteFromPos(int pos,Node*& head,Node*& tail){
    // if linked lists is empty
    if(head==nullptr && tail==nullptr){
        cout << "No Linked List to be deleted" << endl;
        return ;
    }
    else if(head==tail){
        Node* temp=head;
        head=nullptr;
        tail=nullptr;
        delete temp;
    }
    // we delete head node from the linked lists
    else if(pos==1){
        Node* temp=head;
        head=head->next;
        head->prev=nullptr;
        temp->next=nullptr;
    }
    // we want to delete any other than head
    else{

    }
}

void printReverse(Node* tail){
    Node* temp=tail;
    while (temp!=nullptr)
    {
        cout << temp->data << " ";
        temp=temp->prev;
    }
    
}

int main()
{
    Node* head=nullptr;
    Node* tail=nullptr;
    // insertAtHead(head,tail,19);
    // insertAtTail(head,tail,20);
    // insertAtHead(head,tail,18);
    insertAtHead(head,tail,17);
    insertAtTail(head,tail,21);
    insertAtPos(head,tail,2,85);
    insertAtPos(head,tail,3,55);
    print(head);
    printReverse(tail);
    bool ans=searchElementInDLL(head,45);
    cout << endl;
    cout << ans << " ";
    return 0;
}