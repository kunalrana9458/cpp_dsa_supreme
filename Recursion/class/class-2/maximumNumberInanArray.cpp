#include<iostream>
#include<climits>
using namespace std;
void findMax(int arr[],int index,int size,int& maxi){
    if(index >= size) return ;
    if(arr[index] > maxi) maxi=arr[index];
    findMax(arr,index+1,size,maxi);
}
int main()
{
    int maxi=INT_MIN;
    int size=15;
    int index=0;
    int arr[size] = {45,9,6,5,54,78,14,25,3,878,245,2115,15,5451,1};
    findMax(arr,index,size,maxi);
    cout << "Answer is:" << maxi << endl;
    return 0;
}