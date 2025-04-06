#include<iostream>
#include<unordered_map>
#include<queue>
#include<vector>
#include<list>
#include<limits.h>
using namespace std;

class Solution {
    public:
        int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
            // firslty convert the flights into adjList for easy processing
            vector<vector<pair<int,int>>> adjList(n);
            for(int i=0;i<flights.size();i++){
                int u=flights[i][0];
                int v=flights[i][1];
                int weight=flights[i][2];
                adjList[u].push_back({v,weight});
            }
            // priority queue for processing
            // priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,
            // greater<pair<int,pair<int,int>>>> pq;
    
            queue<pair<int,pair<int,int>>> pq;
    
            // maintain the intial state into the pq
            pq.push({0,{src,0}}); // pq.first-> weight,pq.second.first->node and pq.second.second->stops
            // vector for storing the distance
            vector<int> dist(n,1e9);
            dist[src]=0;
            // process the pq
            while(!pq.empty()){
                //  fetch top of the pq
                auto topEle = pq.front();
                pq.pop();
                int price = topEle.first;
                int node = topEle.second.first;
                int stops = topEle.second.second;
                if(stops > k){
                    continue;
                }
                for(auto nbr:adjList[node]){
                    // price for current node
                    int currNodePrice = dist[nbr.first];
                    int nbrNodePrice = nbr.second;
                    if(price+nbrNodePrice<currNodePrice && stops<=k){
                        dist[nbr.first] = price+nbrNodePrice;
                        pq.push({price+nbrNodePrice,{nbr.first,stops+1}});
                    }
                }
            }
            for(auto itr:dist) cout << "Dist is:" << itr << endl;
           return dist[dst] == 1e9 ? -1 : dist[dst] ; 
        }
    };