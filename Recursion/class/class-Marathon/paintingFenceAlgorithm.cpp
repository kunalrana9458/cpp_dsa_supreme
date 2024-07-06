#include<iostream>
using namespace std;
int findPaintingFence(int n,int k){
    // base case
    if(n==1){
        return k;
    }
    if(n==2){
        return k+(k*(k-1));
    }
    int ans=(k-1)*(findPaintingFence(n-1,k)+findPaintingFence(n-2,k));
    return ans;
}
int main()
{
    int n=3;
    int k=3;
    int ans=findPaintingFence(n,k);
    cout << "Answer is:" << ans << endl;
    return 0;
}