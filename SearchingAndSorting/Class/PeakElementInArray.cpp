#include<iostream>
#include<vector>
using namespace std;

int findPeakElement(vector<int>& nums){
    int start=0;
    int end=nums.size()-1;

    while(start < end){
        int mid=start+(end-start)/2;
        
    }
}

int main()
{
    vector<int> nums={10,20,70,50,30,20,15,10};
    findPeakElement(nums);
    cout << nums[2];
    return 0;
}