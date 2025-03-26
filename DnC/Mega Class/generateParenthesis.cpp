#include<iostream>
#include<string>
#include<vector>
using namespace std;
void solve(vector<string>& ans,string& output,int open,int close,int n){
    if((open+close)>=2*n){
        ans.push_back(output);
        return ;
    }
    if(open<n){
        output.push_back('(');
        solve(ans,output,open+1,close,n);
        output.pop_back();
    }
    if(close<open){
        output.push_back(')');
        solve(ans,output,open,close+1,n);
        output.pop_back();
    }
}
vector<string> generateParenthesis(int n){
    vector<string> ans;
    string output="";
    solve(ans,output,0,0,n);
    return ans;
}
int main(){
    int n;
    cin >> n;
    vector<string> ans=generateParenthesis(n);
    for(auto i:ans){
        cout << i << endl;
    }
    return 0;
}