#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;
void findMaxMoney(vector<int>& nums,int index,int sum,int& ans){
    if(index >= nums.size()){
        ans=max(ans,sum);
        return;
    }
    // include non-adjacent element and add it into the array
    findMaxMoney(nums,index+2,sum+nums[index],ans);
    // exclude non-adjacent element and add it into the array
    findMaxMoney(nums,index+1,sum,ans);
}
int rob(vector<int>& nums){
    int index=0;
    int sum=0;
    int ans=INT_MIN;
    findMaxMoney(nums,index,sum,ans);
    return ans;
}
int main()
{
    vector<int> nums={9,4,11,12,6,12};
    int ans=rob(nums);
    cout << "Answer is:" << ans << endl;
    return 0;
}