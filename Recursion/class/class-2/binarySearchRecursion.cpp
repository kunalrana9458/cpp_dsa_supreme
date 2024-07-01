#include<iostream>
using namespace std;
int binarySearchRE(int arr[],int start,int end,int target){
    if(start > end) return -1;
    int mid=start+(end-start)/2;
    if(arr[mid] == target) return mid;
    else if(target > arr[mid]){
        return binarySearchRE(arr,mid+1,end,target);
    }
    else{
        return binarySearchRE(arr,start,mid-1,target);
    }
}
int main()
{
    int size=7;
    int arr[size]={10,20,28,69,98,102,118};
    int start=0;
    int end=size-1;
    int target=60;
    int ans=binarySearchRE(arr,start,end,target);
    cout << "Answer is:" << ans << endl;
    return 0;
}