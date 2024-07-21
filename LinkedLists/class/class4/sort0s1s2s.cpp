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

Node* sort0s1s2s(Node* head){
    if(head==nullptr || head->next==nullptr) return head;
    // seggregate 0,1, and 2 linked list and created three different linked list
    Node* zeroHead=nullptr;
    Node* zeroTail=nullptr;
    Node* oneHead=nullptr;
    Node* oneTail=nullptr;
    Node* twoHead=nullptr;
    Node* twoTail=nullptr;

    Node* temp=head;
    while(temp!=nullptr){
        // if element is 0 then add it to the zeroTail
        if(temp->data==0){
            insertAtTailLL(zeroHead,zeroTail,0);
        }
        // if element is 1 then add it to the oneTail
        else if(temp->data==1){
            insertAtTailLL(oneHead,oneTail,1);
        }
        // if element is 2 then add it to the twoTail
        else{
            insertAtTailLL(twoHead,twoTail,2);
        }
        // increment temp couonter
        temp=temp->next;
    }
    // if one of the three linked one of them are empty then handle it by using that conditions
    if(zeroHead!=nullptr){
        if(oneHead!=nullptr){
            zeroTail->next=oneHead;
            oneTail->next=twoHead;
            return zeroHead;
        }
        else{
            zeroTail->next=twoHead;
            return zeroHead;
        }
    }
    else{
        if(oneHead!=nullptr){
            oneTail->next=twoHead; 
            return oneHead;
        }
        else{
            return twoHead;
        }
    }
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
    Node* ans=sort0s1s2s(head);
    printLL(ans);
    return 0;
}