#include<iostream>
using namespace std;
void printCount(int n){
    if(n==0) return ;
    printCount(n-1);
    cout << n << " ";
    // if(n>=1){
    //     cout << n << " ";
    //     printCount(n-1);
    // }
}
int main()
{
    int n=10;
    printCount(n);
    return 0;
}