#include<iostream>
#include<vector>
using namespace std;
void mergeArray(vector<int>& nums,int start,int mid,int end){
    int leftArrayLen=mid-start+1;
    int rightArrayLen=end-mid;
    // declaration of array for copying original array content
    int* leftArray=new int[leftArrayLen];
    int* rightArray=new int[rightArrayLen];

    int index=start;
    for(int i=0;i<leftArrayLen;i++){
        leftArray[i] = nums[index++];
    }
    for(int i=0;i<rightArrayLen;i++){
        rightArray[i] = nums[index++];
    }
    int i=0;
    int j=0;
    index=start;
    while(i<leftArrayLen && j<rightArrayLen){
        if(leftArray[i] < rightArray[j]){
            nums[index++] = leftArray[i++];
        }
        else{
            nums[index++] = rightArray[j++];
        }
    }
    while(i<leftArrayLen){
        nums[index++] = leftArray[i++];
    }
    while(j<rightArrayLen){
        nums[index++] = rightArray[j++];
    }
}
void mergeSort(vector<int>& nums,int start,int end){
    // base case if end exceed from start and their is only element in the array
    if(start>=end){
        return ;
    }
    // find mid to divide the array into parts
    int mid=start+(end-start)/2;
    // call merge sort for start to mid
    mergeSort(nums,start,mid);
    // call merge sort for mid+1 to end
    mergeSort(nums,mid+1,end);
    // merge two sorted array 
    mergeArray(nums,start,mid,end);
}
int main()
{
    vector<int> nums={34, 1, 8, 50, 7, 15, 2, 60, 29, 13, 22, -5, -10, 48, 18, 5};
    int start=0;
    int end=nums.size()-1;
    mergeSort(nums,start,end);
    for(auto i:nums) cout << i << " ";
    return 0;
}