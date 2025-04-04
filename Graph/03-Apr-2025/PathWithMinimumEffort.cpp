#include<iostream>
#include<list>
#include<queue>
using namespace std;

class Solution {
    public:
        int minimumEffortPath(vector<vector<int>>& heights) {
            // apply dijkstra algorithmm to solve that question
            // take min heap to find the minimum effort
            // {effort,{x,y}}
            int n=heights.size();
            int m=heights[0].size();
            if(n==1 && m==1) return 0;
            priority_queue<pair<int,pair<int,int>>,
            vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
            // maintain the intial state into the pq
            pq.push({0,{0,0}}); // for starting effort will be zero and coordinated are also zero
            // create a more one for storing the efforts 
            vector<vector<int>> weights(n,vector<int>(m,1e8));
            // vectors for movement in all four directions
            vector<int> dx={1,-1,0,0};
            vector<int> dy={0,0,1,-1};
            // process the priority queue
            while(!pq.empty()){
                // fetch the top minimum node
                auto topNode = pq.top();
                pq.pop();
                int effort = topNode.first;
                int x = topNode.second.first;
                int y = topNode.second.second;
                for(int i=0;i<4;i++){
                    int newX = x+dx[i];
                    int newY = y+dy[i];
                    // check that index is a valid grid index or not
                    if(newX<0 || newY<0 || newX>=n || newY>=m) continue;
                    int newEffort = abs(heights[x][y]-heights[newX][newY]); // new Effort for that particular grid cell
                    int maxEffort = max(newEffort,effort); // find maximum effort bw  new Effort and old effort because that
                    // will be the overall effort if person has max Old effort then that will be the original effort
                    if(maxEffort < weights[newX][newY]){
                        // update to the weights and push it into the pq
                        weights[newX][newY] = maxEffort;
                        pq.push({maxEffort,{newX,newY}});
                    }
                }
            }
            return weights[n-1][m-1];
        }
    };