#include<iostream>
#include<vector>
using namespace std;
string longestCommonPrefix(vector<string>& strs) {
        string ans;
        int index=0;
        while(true){
            char curr_ch='@';
            for(int i=0;i<strs.size();i++){
                if(index >= strs[i].length()){
                    curr_ch='@';
                    break;
                }
                if(curr_ch == '@'){
                    curr_ch = strs[i][index];
                }
                else if(curr_ch != strs[i][index]){
                    curr_ch='@';
                    break;
                }
            }
            if(curr_ch == '@') break;
            ans.push_back(curr_ch);
            index++;
        }
        return ans;
    }
int main()
{
    vector<string> strs={"flower","flow","flo"};
    string ans=longestCommonPrefix(strs);
    cout << "Answer is:" << ans << endl;
    return 0;
}