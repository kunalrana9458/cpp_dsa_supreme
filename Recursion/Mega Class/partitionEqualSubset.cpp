#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>
using namespace std;
bool solve(vector<int>& nums,int target,int i){
    if(target<0 || i>=nums.size()) return false;
    if(target==0) return true;
    // include wali call
    bool include=solve(nums,target-nums[i],i+1);
    // exclude wali call
    bool exclude=solve(nums,target,i+1);

    // use or operator between two calls
    return include||exclude;
}
bool canPartition(vector<int>& nums){
    int sum=accumulate(nums.begin(),nums.end(),0);
    if(sum%2|=0) return false;

    int target=sum>>1;
    solve(nums,target,0);
}
int main()
{
    vector<int> nums={1,5,11,5};
    bool ans=canPartition(nums);
    cout << "Answer is:" << ans << endl;
    return 0;
}