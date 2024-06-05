#include<iostream>
using namespace std;
int main()
{
    cout << "Enter the string" << endl;
    string str;
    cin >> str;
    string s="";
    for(int i=0;i<str.size();i++){
        if(s.back() == str[i]){
            s.pop_back();
        }
        else s.push_back(str[i]);
    }
    cout << "Answer is:" << s << endl;
    return 0;
}