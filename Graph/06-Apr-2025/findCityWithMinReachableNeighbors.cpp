#include<iostream>
#include<unordered_map>
#include<queue>
#include<vector>
#include<list>
#include<limits.h>
using namespace std;

class Solution {
    private:
    int dijkstraAlgo(int src,unordered_map<int,list<pair<int,int>>>& adjList,int distanceThresold,int n){
        int reachableCities=0;

        vector<int> dist(n,1e9);
        dist[src]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,src});

        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            int distance=top.first;
            int node=top.second;
            for(auto nbr:adjList[node]){
                if(distance+nbr.second < dist[nbr.first]){
                    dist[nbr.first]=nbr.second+distance;
                    pq.push({dist[nbr.first],nbr.first});
                }
            }
        }

        for(int i=0;i<n;i++){
            if(src != i && dist[i] <= distanceThresold){
                reachableCities++;
            }
        }

        cout << "Distance for node:" << src << endl;
        for(auto itr:dist) cout << itr << " ";
        cout << endl;
        cout << reachableCities << endl;
        return reachableCities;
    }
    private:
    void createAdjList(int n,vector<vector<int>>& edges,unordered_map<int,list<pair<int,int>>>& adjList){
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int wt=edges[i][2];
            adjList[u].push_back({v,wt});
            adjList[v].push_back({u,wt});
        }
    }
    public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        unordered_map<int,list<pair<int,int>>> adjList;
        createAdjList(n,edges,adjList);
        int minCities=INT_MAX;
        int city=0;
        for(int i=0;i<n;i++){
            int totalCities=dijkstraAlgo(i,adjList,distanceThreshold,n);
            if(totalCities <= minCities){
                minCities=totalCities;
                city=i;
            }
        }
        return city;
    }
};