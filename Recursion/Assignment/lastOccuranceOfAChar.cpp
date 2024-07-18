#include<iostream>
using namespace std;
void find_Last_Occ(string& str,char& ch,int index,int& ans){
    if(index <= 0){
        return ;
    }
    if(str[index] == ch){
        ans=index;
        return ;
    }
    find_Last_Occ(str,ch,index-1,ans);
}
int main(){
    string str;
    cin >> str;
    char ch;
    cin >> ch;
    int index=0;
    int ans=-1;
    find_Last_Occ(str,ch,str.size()-1,ans);
    cout << "Answer is:" << ans << endl;
    return 0;
}