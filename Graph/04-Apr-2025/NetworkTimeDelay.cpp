#include<iostream>
#include<unordered_map>
#include<queue>
#include<vector>
#include<list>
#include<limits.h>
using namespace std;


class Solution {
    public:
        int networkDelayTime(vector<vector<int>>& times, int n, int k) {
            // create a adjList
            unordered_map<int,list<pair<int,int>>> adjList;
            for(int i=0;i<times.size();i++){
                int u=times[i][0];
                int v=times[i][1];
                int w=times[i][2];
                adjList[u].push_back({v,w});
            }
            // maintain queue
            queue<pair<int,int>> q; // {distance,node}
            vector<int> dist(n+1,1e8);
            dist[0]=-1;
            dist[k]=0;
            q.push({0,k});
            while(!q.empty()){
                auto front = q.front();
                q.pop();
                int time = front.first;
                int node = front.second;
                for(auto nbr:adjList[node]){
                    if(nbr.second+time < dist[nbr.first]){
                        dist[nbr.first] = nbr.second+time;
                        q.push({dist[nbr.first],nbr.first});
                    }
                }
            }
            int minTime = 0;
            for(int i=1;i<dist.size();i++){
                if(dist[i] == 1e8) return -1;
                minTime = max(minTime,dist[i]);
            }
            return minTime;
        }
    };