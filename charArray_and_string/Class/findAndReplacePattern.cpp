#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

void normalize(string& str){
    char start='a';
    unordered_map<char,char> mpp;

    for(int i=0;i<str.length();i++){
        char stringCharacter=str[i];
        if(mpp.find(stringCharacter) == mpp.end()){
            mpp[stringCharacter] = start;
            start++;
        }
    }

    for(int i=0;i<str.length();i++){
        char mappedChracter=mpp[str[i]];
        str[i]=mappedChracter;
    }
}

vector<string> findAndReplacePattern(vector<string> &words,string pattern){

    vector<string> ans;
    // normalize the pattern first 
    normalize(pattern);
    // lets check on words -> normalise it -> check pattern k equal h ta nhi
    for(auto i:words){
        string currWord=i;
        // create copy and normailse it
        string currWordCopy=currWord;
        normalize(currWordCopy);
        if(currWordCopy.compare(pattern) == 0l){
            ans.push_back(currWord);
        }
    }
    return ans;   
}
int main()
{
    vector<string> words = {"abc","deq","mee","aqq","dkd","ccc"};
    string pattern = "abb";
    vector<string> ans=findAndReplacePattern(words,pattern);
    for(auto i:ans){
        cout << i << " ";
    }
    return 0;
}