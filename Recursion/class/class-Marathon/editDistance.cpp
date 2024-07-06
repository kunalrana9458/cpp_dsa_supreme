#include<iostream>
#include<string>
using namespace std;
// Leetcode-72
int solve(string& word1,string& word2,int i,int j){
    // if our one of the string characters end then there is only delete operation available
    if(i>=word1.length()){
        return word2.length()-j;
    }
    if(j>=word2.length()){
        return word1.length()-i;
    }
    // there is possiblility that character of two string may be matched
    int ans=0;
    if(word1[i] == word2[j]){
        // 0 operation is performed and i,j both increased by 1
        ans=0+solve(word1,word2,i+1,j+1);
    }
    else{
        // if no string character matched then there are three operations :- DELETE,REPLACE,INSERT
        // INSERT Operation
        int insert=1+solve(word1,word2,i,j+1);
        // DELETE OPERATION
        int deleting=1+solve(word1,word2,i+1,j);
        // REPLACE Operation
        int replace=1+solve(word1,word2,i+1,j+1);
        // we always return minimum out of three
        ans=min(insert,min(deleting,replace));
    }
    return ans;
}
int minDistance(string word1, string word2) {
    int i=0;
    int j=0;
    int ans=solve(word1,word2,i,j);
    return ans;
}
int main()
{
    string word1,word2;
    cin >> word1 >> word2;
    int ans=minDistance(word1,word2);
    cout << "Answer is:" << ans << endl;   
    return 0;
}