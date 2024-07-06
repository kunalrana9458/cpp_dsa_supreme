#include<iostream>
#include<vector>
#include<climits>
using namespace std;
void find_max(vector<int>& nums,int index,int sum,int& ans){
    // base case
    if(index >= nums.size()){
        ans=max(sum,ans);
        return ;
    }

    // include answer
    find_max(nums,index+2,sum+nums[index],ans);
    // exclude answer 
    find_max(nums,index+1,sum,ans);
}
int main()
{
    vector<int> nums={6,5,1,11};
    int index=0;
    int sum=0;
    int ans=INT_MIN;
    find_max(nums,index,sum,ans);
    cout << "Answer is:" << ans << endl;
    return 0;
}