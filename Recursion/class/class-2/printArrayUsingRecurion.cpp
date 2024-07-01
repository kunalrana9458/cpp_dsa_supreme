#include<iostream>
using namespace std;
void printArray(int arr[],int index,int size){
    // base case
    if(index >= size) return ;
    // processing to solve one case 
    cout << arr[index] <<  "  ";
    // recurrence relation
    printArray(arr,index+1,size);
}
int main()
{
    int arr[6] = {10,12,30,8,50,60};
    int index=0;
    int size=6;
    printArray(arr,index,size);
    return 0;
}