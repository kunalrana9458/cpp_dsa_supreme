#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
bool keyPair(vector<int>& nums,int target){
    map<int,int> mpp;
    for(int i=0;i<nums.size();i++){
        int rem=target-nums[i];
        if(mpp.find(rem) != mpp.end()) return true;
        mpp[nums[i]] = i;
    } 
    return false;
}

bool keyPairTwoPointer(vector<int>& nums,int target){
    int low=0;
    int high=nums.size()-1;
    while(low < high){
        if(nums[low]+nums[high] == target) return true;
        else if(nums[low]+nums[high] < target) low++;
        else high--;
    }
    return false;
}
int main()
{
    vector<int> arr={1,4,45,6,10,8};
    int target=16;
    sort(arr.begin(),arr.end());
    bool ans=keyPairTwoPointer(arr,target);
    cout << "Answer is:" << ans;
    return 0;
}