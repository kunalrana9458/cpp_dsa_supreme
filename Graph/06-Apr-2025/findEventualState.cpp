#include<iostream>
#include<unordered_map>
#include<queue>
#include<vector>
#include<list>
#include<algorithm>
#include<limits.h>
using namespace std;


class Solution {
    private:
        void graphReversal(vector<vector<int>>& graph,unordered_map<int,list<int>>& adjList,
                           unordered_map<int,int>& indegree){
            for(int i=0;i<graph.size();i++){
                for(auto itr:graph[i]){
                    adjList[itr].push_back(i);
                    indegree[i]++;
                }
            }
        }
    public:
        vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
            // reverse the graph
            int n=graph.size();
            unordered_map<int,list<int>> adjList;
            unordered_map<int,int> indegree;
            graphReversal(graph,adjList,indegree);
            // find indegree for the list
            // initaite queue and maintain intial state into the queue by pusing all having 0 indegree
            queue<int> q;
            for(int i=0;i<graph.size();i++){
                if(indegree[i]==0) q.push(i);
            }
            vector<int> ans;
            while(!q.empty()){
                int node=q.front();
                ans.push_back(node);
                q.pop();
                for(auto nbr:adjList[node]){
                    indegree[nbr]--;
                    if(indegree[nbr]==0){
                        q.push(nbr);
                    }
                }
            }
            sort(ans.begin(),ans.end());
            return ans;
        }
    };