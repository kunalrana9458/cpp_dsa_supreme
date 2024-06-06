#include<iostream>
#include<unordered_map>
using namespace std;
string decodeMessage(string key,string message){
    // step:1 create mapping
    unordered_map<char,char> mpp;
    char space=' ';
    mpp[space] = ' ';
    char start='a';
    int index=0;
    while(start <= 'z' && index < key.length()){
        char keyCurrentCharacter=key[index];
        // start-> mapping abcd..
        if(mpp.find(keyCurrentCharacter) != mpp.end()){
            // agrr currentcharacter ki mapping already present hai
            // no need to store any mapping here just move to the next character in key
            index++;
        }
        else{
            // already present
            // create mapping and move ahead
            mpp[keyCurrentCharacter] = start;
            start++;
            index++;
        }
    }
    // step:2 use mapping and decode message
    string ans="";
    for(int i=0;i<message.size();i++){
        char messageCharacter = message[i];
        char mappedCharacter = mpp[messageCharacter];
        ans.push_back(mappedCharacter);
    }
    return ans;
}
int main()
{
    string key="the quick brown fox jumps over the lazy dog";
    string message="vkbs bs t suepuv";
    string ans=decodeMessage(key,message);
    cout << "Answer is:" << ans << endl;
    return 0;
}