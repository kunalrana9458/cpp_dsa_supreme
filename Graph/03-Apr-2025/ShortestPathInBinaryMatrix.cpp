#include<iostream>
#include<list>
#include<queue>
using namespace std;

class Solution {
    public:
        int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
            int n=grid.size();
            if(grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
            priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<>> pq;
            vector<vector<int>> visited(n,vector<int>(n,false));
            // make vector to traverse to all the four directions
            vector<int> dx={1,-1,0,0,-1,1,1,-1};
            vector<int> dy={0,0,1,-1,-1,1,-1,1};
            // maintain the intial state of the priority queue
            pq.push({1,{0,0}}); // <int,pair<int,int>> int=distance <int,int> ={x,y} coordinates
            while(!pq.empty()){
                auto frontNode = pq.top(); // access top smallest node of the minHeap
                pq.pop();
                int dist = frontNode.first; // access the distance for the current coordinates
                int x = frontNode.second.first; // access the x-axis
                int y = frontNode.second.second;  // access the y-axis
                // check if can reach to the destination coordinates
                if(x==n-1 && y==n-1){
                    return dist;
                }
                // iterate to all eight directions in the matrix
                for(int i=0;i<8;i++){
                    int newX=x+dx[i];
                    int newY=y+dy[i];
                    if(newX<0 || newY<0 || newX>=n || newY>=n || grid[newX][newY]==1 || visited[newX][newY]==true) continue;
                    pq.push({dist+1,{newX,newY}});
                    visited[newX][newY]=true;
                }
            }
            return -1;
        }
    };