#include<iostream>
using namespace std;
class Queue{
    private:
    int* arr;
    int n; // represents size
    int front;
    int rear;
    public:
    Queue(int size){
        arr = new int[size];
        n = size;
        front=-1;
        rear=-1;
    }

    void push(int val){
        if(front==-1 && rear==-1){
            front=0;
            rear=0;
        }
        if(rear==n-1){
            cout << "Queue is full" << endl;
            return ;
        }
        arr[rear++]=val;
    }

    void pop(){
        if(front==-1 && rear==-1){
            cout << "Queue is Empty" << endl;
            return ;
        }
        if(front == rear){
            front=-1;
            rear=-1;
            return ;
        }
        front++;
    }

    int front(){
        return arr[front];
    }
};
int main()
{
    return 0;
}