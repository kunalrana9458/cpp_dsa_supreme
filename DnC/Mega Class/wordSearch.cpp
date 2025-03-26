#include<iostream>
#include<vector>
using namespace std;
bool exist_helper(vector<vector<char>>& board,string word,int wordIndex,int i,int j,int m,int n){
        if(wordIndex >= word.size())  return true;
        if(i<0 || i>=m || j<0 || j>=n || board[i][j]!=word[wordIndex] || board[i][j]=='!')  return false;

        char ch=board[i][j];
        board[i][j]='!';
        bool left=exist_helper(board,word,wordIndex+1,i+1,j,m,n);
        bool right=exist_helper(board,word,wordIndex+1,i-1,j,m,n);
        bool up=exist_helper(board,word,wordIndex+1,i,j-1,m,n);
        bool down=exist_helper(board,word,wordIndex+1,i,j+1,m,n);
        board[i][j]=ch;

        return left||right||up||down;
    }

bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j] == word[0]){
                    if(exist_helper(board,word,0,i,j,m,n)) return true;
                }
            }
        }
        return false;
    }
int main()
{
    return 0;
}