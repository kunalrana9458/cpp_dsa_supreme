#include<iostream>
#include<vector>
using namespace std;
int rob(vector<int>& nums,int index,int size){
    if(index>=size){
        return 0;
    }
    int ans1=nums[index]+rob(nums,index+2,size);
    int ans2=rob(nums,index+1,size);
    return max(ans1,ans2);
}
int main()
{
    vector<int> nums={1,2,3,1};
    int index=0;
    int n=nums.size();
    int opt1=rob(nums,index,n-1);
    int opt2=rob(nums,index+1,n);
    cout << max(opt1,opt2) << endl;
    return 0;
}