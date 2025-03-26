#include<iostream>
#include<stack>
using namespace std;
class Stack{
    public:
    int size;
    int* arr;
    int top;

    Stack(int size){
        this->size=size;
        arr=new int[size];
        top=-1;
    }

    void push(int data){
        if(top==size-1){
            cout << "Stack Overflow" << endl;
            return ;
        }
        top++;
        arr[top]=data;
    }

    void pop(){
        if(top<0){
            cout << "Stack Underflow" << endl;
            return ;
        }
        arr[top]=-1;
        top--;
    }

    int getSize(){
        return top+1;
    }

    bool isEmpty(){
        if(top==-1) return true;
        return false;
    }

    int getTop(){
        if(top==-1){
            cout << "No element in the stack";
            return -1;
        }
        else{
            return arr[top];
        }
    }

    void print(){
        for(int i=0;i<size;i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }

};
int main()
{
    Stack stt(5);
    stt.push(10);
    stt.push(20);
    stt.push(30);
    stt.push(40);
    stt.push(50);
    stt.print();
    return 0;
}