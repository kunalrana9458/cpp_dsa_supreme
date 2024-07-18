#include<iostream>
#include<string>
using namespace std;
bool checkPalindrome(string& str,int i,int j){
    if(i>=j){
        return true;
    }
    if(str[i] != str[j]){
        return false;
    }
    return checkPalindrome(str,i+1,j-1);
}
int main()
{
    string str;
    cin >> str;
    int i=0;
    int j=str.size()-1;
    bool ans=checkPalindrome(str,i,j);
    cout << "Answer is:" << ans << endl;
    return 0;
}