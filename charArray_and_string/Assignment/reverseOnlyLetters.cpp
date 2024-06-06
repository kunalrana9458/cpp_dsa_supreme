#include<iostream>
using namespace std;
string reverseOnlyLetters(string s){
    int i=0;
    int j=s.size()-1;
    while(i<=j){
        if(!isalpha(s[i])) i++;
        else if(!isalpha(s[j])) j--;
        else{
            swap(s[i],s[j]);
            i++;
            j--;
        }
    }
    return s;
}
int main()
{
    string s;
    cin >> s;
    string ans=reverseOnlyLetters(s);
    cout << "Answer is:" << ans << endl;
    return 0;
}