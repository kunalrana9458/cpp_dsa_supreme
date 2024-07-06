#include<iostream>
using namespace std;
int solve(int n){
    // base case if n==1 then no dearrangement possible so return 0
    if(n==1) return 0;
    // if n==2 then only one dearrangement is possible so return 1
    if(n==2) return 1;
    int ans=(n-1)*(solve(n-1)+solve(n-2));
    return ans;
}
int main()
{
    int n=8;
    int ans=solve(n);
    cout << "Answer is:" << ans << endl;
    return 0;
}