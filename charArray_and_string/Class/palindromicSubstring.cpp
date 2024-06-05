#include<iostream>
using namespace std;
int checkPalindrome(string s,int start,int end){
    int count=0;
    while(start>=0 && end<s.size() && start<=end){
        if(s[start] == s[end]){
            count++;
            start--;
            end++;
        }
    }
    return count;
}
int palindromicSubstring(string s){
    int count=0;
    for(int i=0;i<s.size();i++){
        int oddCount=checkPalindrome(s,i,i);
        count+=oddCount;
        int evenCount=checkPalindrome(s,i,i+1);
        count+=evenCount;
    }
    return count;
}
int main(){
    string s="aaa";
    // brute force Approach -: find all possible substring and check weather it is palindromic or not
    // we will solve with the optimized approach
    int count=palindromicSubstring(s);
    cout << "Answer is:" << count << endl;
    return 0;
}