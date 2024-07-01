#include<iostream>
using namespace std;
int firstOcc(string& haystack,string& needle){
    if(haystack.size() < needle.size()) return -1;
    int ans=-1;
    for(int i=0;i<haystack.size()-needle.size();i++){
        for(int j=0;j<needle.size();j++){
            if(haystack[i+j] != needle[j]){
                break;
            }
            if(j==needle.size()-1) return i;
        }
    }
    return ans;
}
int main()
{
    string haystack,needle;
    cin >> haystack >> needle;
    int index=firstOcc(haystack,needle);
    cout << "Answer is:" << index << endl;
    return 0;
}