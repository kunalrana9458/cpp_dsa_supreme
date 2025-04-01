#include<vector>
#include<queue>
using namespace std;
class Solution {
    public:
        vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
            // firstly find all the mat-cell with 0 because its distance is 0 from itself
            // store all these into the queue for processing other one's
            int n=mat.size();
            int m=mat[0].size();
            queue<pair<int,pair<int,int>>> points;
            vector<vector<bool>> visited(n,vector<bool>(m,false));
            vector<vector<int>> ans(n,vector<int>(m,0));
            // find all 0's to push it into the queue marked ans as 0 and visited as true
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(mat[i][j] == 0){
                        points.push({0,{i,j}});
                        visited[i][j]=true;
                        ans[i][j]=0;
                    }
                }
            }
            // for moving all four directions
            vector<int> dx={1,-1,0,0};
            vector<int> dy={0,0,1,-1};
            // process all adjacent nodes to that zeroes
            while(!points.empty()){
                // fetch front node
                auto fNode = points.front();
                points.pop();
                int distance=fNode.first;
                int x=fNode.second.first;
                int y=fNode.second.second;
                for(int i=0;i<4;i++){
                    int newX=x+dx[i];
                    int newY=y+dy[i];
                    if(newX<0 || newX>=n || newY<0 || newY>=m || mat[newX][newY] == 0) continue;
                    if(!visited[newX][newY]){
                        ans[newX][newY]=distance+1;
                        visited[newX][newY]=true;
                        points.push({distance+1,{newX,newY}});
                    }
                }
            }
            return ans;
        }
    };