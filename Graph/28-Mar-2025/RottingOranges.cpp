#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int rottingOranges(vector<vector<int>>& grid,int n,int m){
    queue<pair<int,int>> rottenPos;  // rotten oranges position
    int totalOranges = 0;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j] == 2){
                rottenPos.push({i,j});
            }
            if(grid[i][j] == 1 || grid[i][j] == 2) totalOranges++;
        }
    }

    cout << "TOTALORANGES:" << totalOranges << endl;
    // intialize vector which is used to move in all four directions
    vector<int> dx = {0,0,1,-1};
    vector<int> dy = {1,-1,0,0};

    int minutes = 0; // used to store minutes required to rotten the oranges
    int countCheck = 0; // used to keep if all oranges are rotten or not if not all are rotten return -1
    // iterate over the queue to find total time to rotten all the oranges

    while(!rottenPos.empty()){
        int k = rottenPos.size();
        countCheck += k;
        cout << "ITER" << endl;

        while(k--){
            // move in all four directions and mark the orannges as rotten
            pair<int,int> qFront = rottenPos.front();
            rottenPos.pop();
            int x = qFront.first;
            int y = qFront.second;

            // iterate in all four direction and mark orange as rotten
            for(int i=0;i<4;i++){
                int newX = x+dx[i];
                int newY = y+dy[i];
                if(newX<0 || newY<0 || newX>=n || newY>=m || grid[newX][newY]!=1) continue;
                // mark fresh oranges as rotten and push new rotten oranges postion into the queue
                rottenPos.push({newX,newY});
                grid[newX][newY] = 2;
            }
        }
        if(!rottenPos.empty()){
            minutes++;
        }
    }
    cout << "Minutes is:" << minutes << endl;
    cout << "countcheck:" << countCheck << endl;
    return totalOranges == countCheck ? minutes:-1 ;
}

int main()
{
    // take input for the grid 
    // 0->Empty cell 1->Fresh oranges 2->Rotten oranges 
    cout << "Enter the size of Grid" << endl;
    int n,m;
    cin >> n >> m;
    vector<vector<int>> grid(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> grid[i][j];
        }
    }
    int timesToRotten = rottingOranges(grid,n,m);
    cout << "Time to rotten all the oranges:" << timesToRotten;
    return 0;
}