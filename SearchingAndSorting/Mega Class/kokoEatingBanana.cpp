#include<iostream>
#include<vector>
#include<climits>
using namespace std;

bool isPossible(vector<int>& piles,int h,int speed){
    int s=0;
    for(int i=0;i<piles.size();i++){
        s += piles[i]/speed + ((piles[i]%speed) != 0);
        if(s > h) return false;
    }
    return true;
}

int minEatingSpeed(vector<int>& piles,int h){

    int maxi=0;

    for(int i=0;i<piles.size();i++){
        maxi=max(maxi,piles[i]);
    }

    for(int i=1;i<=maxi;i++){
        if(isPossible(piles,h,i)) return i;
    }
    
    int start=1;
    int end=maxi;
    int ans=-1;
    
    while(start<=end){
        int mid=start+(end-start)/2;
        if(isPossible(piles,h,mid)){
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
    vector<int> piles={312884470};
    int n=piles.size();
    cout << "hii" << endl;
    int h=312884469;
    int ans=minEatingSpeed(piles,h);
    cout << "Answer is:" << ans << endl;

    cout << 312884470%312884469;
    return 0;
}