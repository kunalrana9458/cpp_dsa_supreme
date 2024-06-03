#include<iostream>
#include<climits>
#include<vector>
using namespace std;

bool isPossible(vector<int>& bloomDay,int m,int k,int bloom){
    int flowerCnt=0;
    int boquetCnt=0;
    for(int i=0;i<bloomDay.size();i++){
        if(bloomDay[i] <= bloom){
            flowerCnt++;
            if(flowerCnt == k){
                boquetCnt++;
                flowerCnt=0;
            }
        }
        else flowerCnt=0;
    }
    return boquetCnt>=m;
}


int minimumDaysToBloom(vector<int>& bloomDay,int m,int k){
    int ans=-1;

    int mini=INT_MAX;
    int maxi=INT_MIN;

    for(int i=0;i<bloomDay.size();i++){
        mini=min(mini,bloomDay[i]);
        maxi=max(maxi,bloomDay[i]);
    }

    int start=mini;
    int end=maxi;

    while(start<=end){
        int mid=start+(end-start)/2;
        if(isPossible(bloomDay,m,k,mid)){
            ans=mid;
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }

    return ans;
}
int main()
{
    vector<int> bloomDay={5, 8, 5, 5, 6, 5, 5};
    int k=3;
    int m=2;
    int ans=minimumDaysToBloom(bloomDay,m,k);
    cout << "Answer is:" << ans;
    return 0;
}