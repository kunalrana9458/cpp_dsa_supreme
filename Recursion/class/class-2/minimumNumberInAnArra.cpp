#include<iostream>
#include<climits>
using namespace std;
void findMin(int arr[],int size,int index,int& mini){
    // base case
    if(index >= size) return ;
    // solving one case
    mini=min(mini,arr[index]);
    // recursive relation
    findMin(arr,size,index+1,mini);
}
int main()
{
    int size=10;
    int arr[size] = {12,14,55,69,44,45,12,4,78,56};
    int index=0;
    int mini=INT_MAX;
    findMin(arr,size,index,mini);
    cout << "Minimum Number is:" << mini << endl;
    return 0;
}