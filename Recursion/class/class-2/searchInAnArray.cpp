#include<iostream>
using namespace std;
bool searchElement(int arr[],int size,int index,int target){
    // 2 base case -> one for found element and one for not found element
    if(index >= size) return false;
    if(arr[index] == target) return true;
    return searchElement(arr,size,index+1,target);
}
int main()
{
    int arr[5] = {151,545,4547,458,988};
    int size=5;
    int index=0;
    int target=988;
    bool ans = searchElement(arr,size,index,target);
    cout << "Answer is:" << ans << endl;
}