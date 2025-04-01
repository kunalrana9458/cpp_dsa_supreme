#include<vector>
using namespace std;

class Solution {
    private:
        void dfsTraversal(vector<vector<int>>& board,vector<vector<bool>>& visited,int m,int n,int i,int j){
            // check for out of bound condition and X block
            if(i<0 || j<0 || i>=n || j>=m || board[i][j]==0){
                return ;
            }
            if(visited[i][j]==true) return ;
            // traverse across all four direction
            visited[i][j]=true;
            dfsTraversal(board,visited,m,n,i+1,j);
            dfsTraversal(board,visited,m,n,i-1,j);
            dfsTraversal(board,visited,m,n,i,j+1);
            dfsTraversal(board,visited,m,n,i,j-1);
        }
    public:
        int numEnclaves(vector<vector<int>>& board) {
            int n=board.size();
            int m=board[0].size();
            vector<vector<bool>> visited(n,vector<bool>(m,false));
            // traverse across the boundary 
            for(int i=0;i<n;i++){
                if(board[i][0]==1 || board[i][m-1]==1){
                    if(visited[i][0]==false){
                        dfsTraversal(board,visited,m,n,i,0);
                    }
                    if(visited[i][m-1]==false){
                        dfsTraversal(board,visited,m,n,i,m-1);
                    }
                }
            }
            for(int j=0;j<m;j++){
                if(board[0][j]==1 || board[n-1][j]==1){
                    if(visited[0][j]==false){
                        dfsTraversal(board,visited,m,n,0,j);
                    }
                    if(visited[n-1][j]==false){
                        dfsTraversal(board,visited,m,n,n-1,j);
                    }
                }
            }
            int ans=0;
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(board[i][j]==1 && visited[i][j]==false){
                        ans++;
                    }
                }
            }
            return ans;
        }
    };

int main(){
    return 0;
}