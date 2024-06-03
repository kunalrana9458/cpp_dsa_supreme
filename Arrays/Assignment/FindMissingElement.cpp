#include<iostream>
#include<vector>
using namespace std;
int findMissingElement(vector<int>& nums){
    int n=nums.size();
    int sum=((n)*(n+1))/2;
    for(int i=0;i<n;i++){
        sum -= nums[i];
    }
    return sum;
}
int main(){
    vector<int> nums={1,2,4,3};
    int ans=findMissingElement(nums);
    cout << "Answer is:" << ans;
    return 0;
}