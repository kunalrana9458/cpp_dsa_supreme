#include<iostream>
using namespace std;
bool isPalindrome(int start,int end,string& str){
    while(start<=end){
        if(str[start] != str[end]) return false;
        else{
            start++;
            end--;
        }
    }
    return true;
}
string longestSubstr(string& str){
    string ans="";
    // iterate on a str and find all possible substring
    for(int i=0;i<str.size();i++){
        for(int j=i;j<str.size();j++){
            if(isPalindrome(i,j,str)){
                string t=str.substr(i,j-i+1);
                ans = t.size() > ans.size() ? t:ans;
            }
        }
    }
    return ans;
}
int main()
{
    string str="aacabdkacaa";
    string ans=longestSubstr(str);
    cout << "Answer is:" << ans << endl;
    return 0;
}