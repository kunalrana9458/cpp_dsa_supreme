#include<iostream>
using namespace std;
void printEvenNumbers(int arr[],int index,int size){
    if(index >= size) return ;
    if(!(arr[index]&1)) cout << arr[index] << " ";
    printEvenNumbers(arr,index+1,size);
}
int main()
{
    int size=6;
    int arr[size] = {10,11,12,15,54,45};
    int index=0;
    printEvenNumbers(arr,index,size);
    return 0;
}