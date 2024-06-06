#include<iostream>
#include<vector>
using namespace std;
bool isAnagram(string s,string t){
    vector<int> arr(256,0);
    if(s.length() != t.length()) return false;
    for(int i=0;i<s.length();i++){
        arr[s[i]]++;
        arr[t[i]]--;
    }
    for(int i=0;i<256;i++){
        if(arr[i] != 0){
            return false;
        }
    }
    return true;
}
int main()
{
    string str1,str2;
    cin >> str1 >> str2;
    bool ans=isAnagram(str1,str2);
    cout << "Answer is:" << ans;
    return 0;
}