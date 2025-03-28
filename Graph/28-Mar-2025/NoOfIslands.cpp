#include<iostream>
#include<vector>
using namespace std;

void dfsTraversal(vector<vector<int>>& grid,int n,int m,int i,int j){
    // check if we are out of bound from the grid and also stops when water comes
    if(i<0 || i>=n || j<0 || j>=m || grid[i][j]==0)
        return ;

    if(grid[i][j] == -1)
       return ;

    // apply in all four directions first mark current cell as -1 to keep track
    grid[i][j] = -1;
    dfsTraversal(grid,n,m,i+1,j);
    dfsTraversal(grid,n,m,i-1,j);
    dfsTraversal(grid,n,m,i,j-1);
    dfsTraversal(grid,n,m,i,j+1);
}

int findNumOfIslands(vector<vector<int>>& grid,int n,int m){
    // iterate over the loop and find 1 for the island
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            // piece of lands is founded
            if(grid[i][j] == 1){
                // try to cover all adjacent lands of pieces correspond to that piece
                // for that find we use dfs traversal
                dfsTraversal(grid,n,m,i,j);
                count++;
            }
        }
    }
    return count;
}

int main()
{
    cout << "Enter the size of the grid" << endl;
    int n,m;
    cin >> n >> m;
    vector<vector<int>> grid(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> grid[i][j];
        }
    }
    int noOfIslands = findNumOfIslands(grid,n,m);
    cout << "Number of Islands:" << noOfIslands;
    return 0;
}