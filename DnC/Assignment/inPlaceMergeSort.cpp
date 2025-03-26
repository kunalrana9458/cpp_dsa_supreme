#include<iostream>
#include<vector>
using namespace std;
void mergeArrInaPlace(vector<int>& nums,int start,int mid,int end){
    int total_len=end-start+1;
    int gap=(total_len/2)+(total_len%2);
    while(gap>0){
        int i=start;
        int j=start+gap;
        while (j<=end)
        {
            if(nums[i]>nums[j]){
                swap(nums[i],nums[j]);
                i++;
                j++;
            }
                i++;
                j++;
        }
        gap=gap<=1 ? 0 : (gap/2)+(gap%2); 
    }
}
void mergeSort(vector<int>& nums,int start,int end){
    if(start>=end) return;
    int mid=start+(end-start)/2;
    mergeSort(nums,start,mid);
    mergeSort(nums,mid+1,end);
    mergeArrInaPlace(nums,start,mid,end);
}
int main()
{
    vector<int> nums={1,5,4,5,1,24,6,8,6,10,24,12,87,54,69,21,45,78,9,5,4,7,8};
    int start=0;
    int end=nums.size()-1;
    mergeSort(nums,start,end);
    for(auto i:nums) cout << i << " ";
    return 0;
}