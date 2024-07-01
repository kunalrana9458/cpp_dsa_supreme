#include<iostream>
using namespace std;
int summation(int n){
    if(n==0) return 0;
    return n+summation(n-1);
}
int main()
{
    int n=6;
    int ans=summation(n);
    cout << "Answer is:" << ans << endl;
    return 0;
}