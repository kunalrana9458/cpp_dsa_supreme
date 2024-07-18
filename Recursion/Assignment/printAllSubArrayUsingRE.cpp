#include<iostream>
#include<vector>
using namespace std;
void printSinglePattern(vector<int>& nums,int start,int end){
    if(end>=nums.size()){
        return ;
    }
    for(int i=start;i<=end;i++){
        cout << nums[i] << " ";
    }
    cout << endl;
    printSinglePattern(nums,start,end+1);
}
void printAllSubarray(vector<int>& nums,int start,int end){
    if(start>=nums.size()){
        return ;
    }
    printSinglePattern(nums,start,start);
    printAllSubarray(nums,start+1,end);
}
int main()
{
    vector<int> nums={1,2,3,4,5};
    int start=0;
    int end=0;
    printAllSubarray(nums,start,end);
    return 0;
}