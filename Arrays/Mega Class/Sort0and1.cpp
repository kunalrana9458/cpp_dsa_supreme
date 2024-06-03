#include<iostream>
#include<vector>
using namespace std;
void sort0and1(vector<int>& nums){
    int start=0;
    int end=nums.size()-1;
    while(start<end){
        if(nums[start] == 0) start++;
        else if(nums[end] == 1) end--;
        else {
            swap(nums[start++],nums[end--]);
        }
    }
}
int main()
{
    vector<int> nums={0,1,0,1,1,0,0,1,1,0,0,1,1};
    sort0and1(nums);
    for(int i=0;i<nums.size();i++){
        cout << nums[i] << " ";
    }
    return 0;
}