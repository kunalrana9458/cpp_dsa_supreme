#include<iostream>
#include<vector>
using namespace std;
int singleNumber(vector<int>& arr){
    int ans=0;
    for(int i=0;i<arr.size();i++){
        ans ^= arr[i];
    }
    return ans;
}
int main(){
    // find number which present only one time in the array
    vector<int> arr={1,5,1,8,9,6,5,9,8};
    int ans=singleNumber(arr);
    cout << "Answer is:" << ans << endl;
    return 0;
}