#include<iostream>
using namespace std;
bool checkPalindrome(string s,int start,int end){
    while(start <= end){
        if(s[start] != s[end]) return false;
        else{
            start++;
            end--;
        }
    }
    return true;
}
bool validPalindromeAfterRemoveOneChar(string s,int start,int end){
    int i=0;
    int j=s.length()-1;

    while(start<=end){
        if(s[start] != s[end]){
            return (checkPalindrome(s,start+1,end) || checkPalindrome(s,start,end-1));
        }
        else{
            start++;
            end--;
        }
    }
    return true;
}
int main(){
    string s="abcdfcba";
    int start=0;
    int end=s.size()-1;
    bool ans = validPalindromeAfterRemoveOneChar(s,start,end);
    cout << "Answer is:" << ans;
}