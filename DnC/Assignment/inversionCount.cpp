#include<iostream>
#include<vector>
using namespace std;
void mergeArr(vector<int>& arr,int start,int mid,int end,int& ans){
        int len1=mid-start+1;
          int len2=end-mid;
          int* first=new int[len1];
          int* second=new  int[len2];
          int mainArrIndex=start;
        // copying the two arr
        for(int i=0;i<len1;i++){
            first[i]=arr[mainArrIndex++];
        }
        for(int i=0;i<len2;i++){
            second[i]=arr[mainArrIndex++];
        }
        mainArrIndex=start;
        int i=0;
        int j=0;
        while(i<len1 && j<len2){
            if(first[i]<=second[j]){
                arr[mainArrIndex++]=first[i++];
            }
            else{
                arr[mainArrIndex++]=second[j++];
                ans+=(len1-i);
            }
        }
        while(i<len1){
            arr[mainArrIndex++]=first[i++];
        }
        while(j<len2){
            arr[mainArrIndex++]=second[j++];
        }
        delete[] first;
        delete[] second;
        
    }
    void mergeSort(vector<int>& arr,int start,int end,int& ans){
       if(start>=end) return;
       int mid=start+(end-start)/2;
       mergeSort(arr,start,mid,ans);
       mergeSort(arr,mid+1,end,ans);
       mergeArr(arr,start,mid,end,ans);
    }

int countInversions(vector<int> &A) {
    int ans=0;
    mergeSort(A,0,A.size()-1,ans);
    return ans;
}

int main()
{
    vector<int> nums={2,4,1,3,5};
    int ans=countInversions(nums);
    cout << "Answer is:" << ans << endl;
    return 0;
}