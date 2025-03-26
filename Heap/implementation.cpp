#include<iostream>
using namespace std;

class Heap{
    public:
    int* arr;
    int capacity;
    int index;

    Heap(int capacity){
        this->capacity=capacity;
        arr=new int[capacity];
        index=0;
        for(int i=0;i<capacity;i++) arr[i]=0;
    }

    void print(){
        for(int i=0;i<capacity;i++){
            cout << arr[i] << " "; 
        }
        cout << endl;
    }

    void insert(int val){
        if(index == capacity-1){
            cout << "Overflow" << endl;
            return ;
        }
                                                                                                                                                                                                                                                                    
        // if heap not overflow
        index++;
        arr[index] = val;
        int currIndex=index;
        while(currIndex > 1){
            int parentIndex=currIndex/2;

            if(arr[parentIndex] < arr[currIndex]){
                swap(arr[parentIndex],arr[currIndex]);
                currIndex=parentIndex;
            }
            else break;
        }
    }

        void deleteFromHeap(){
            // replacement root and last node
            swap(arr[1],arr[index]);
            // decrease size
            index--;
            // heapify
            heapify(arr,index,1);
        }

        void heapify(int arr[],int n,int currIndex){
            // n-> number of elements in heap
            int i=currIndex;
            int leftIndex=2*i;
            int rightIndex=2*i+1;

            int largestIndex=i;
            // asuume i prr value is the largest value
             
            // check for left
            if(leftIndex < n && arr[leftIndex]>arr[largestIndex]){
                largestIndex=leftIndex;
            }

            // check for right
            if(rightIndex < n && arr[rightIndex]>arr[largestIndex]){
                largestIndex=rightIndex; 
            }
        // if largest value still curr Index
        if(largestIndex != i){
            swap(arr[i],arr[largestIndex]);
            heapify(arr,n,i);
        }
    }

    void buildHeap(int* arr,int n){
        for(int i=n/2;i>0;i--){
            heapify(arr,n,i);
        }
    }

    void heapSort(int* arr,int n){
        int endIndex=n-1;
        while(n>1){
            swap(arr[1],arr[endIndex]);
            // delete last index
            endIndex--;
            // heapify algo
            heapify(arr,endIndex,1);
        }
    }

};

int main(){
    Heap pq(10);
    pq.insert(10);
    pq.print();
    pq.insert(20);
    pq.print();
    pq.insert(30);
    pq.print();
    pq.insert(40);
    pq.print();
    pq.insert(50);
    pq.print();
    pq.deleteFromHeap();
    pq.print();
    pq.deleteFromHeap();
    pq.print();
    pq.deleteFromHeap();
    pq.print();
    return 0;
}