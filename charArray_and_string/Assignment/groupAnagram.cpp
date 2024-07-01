#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
using namespace std;

std::array<int,256> hashed(string str){
    std::array<int,256> ans={0};
    for(int i=0;i<str.size();i++){
        ans[str[i]]++;
    }
    return ans;
}

vector<vector<string>> groupAnagram(vector<string>& strs){
    map<std::array<int,256>,vector<string>> mpp;
    vector<vector<string>> ans;
    for(auto str:strs){
        mpp[hashed(str)].push_back(str);
    }

    for(auto i:mpp){
        ans.push_back(i.second);
    }
    return ans;
}
int main()
{
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
    vector<vector<string>> ans = groupAnagram(strs);
    for(auto i:ans){
        for(auto j:i){
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}