#include<iostream>
#include<vector>
#include<climits>
using namespace std;
// NOT SOLVED YET
int findMinCoins(vector<int>& nums,int amount,int& minCoins){
    // base case
    if(amount == 0){
        return 0;
    }
    if(amount < 0){
        return INT_MAX;
    }
    for(int i=0;i<nums.size();i++){
        if(minCoins != INT_MAX){
            minCoins = 1 + min(minCoins,findMinCoins(nums,amount-nums[i],minCoins));
        }
    }
    return minCoins;
}
int main()
{
    vector<int> nums={1,2,3};
    int amount=10;
    int minCoins=INT_MAX;
    int coins=findMinCoins(nums,amount,minCoins);
    cout << "Answer is:" << coins << endl;
    return 0;
}