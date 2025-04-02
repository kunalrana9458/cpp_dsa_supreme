#include<iostream>
#include<unordered_map>
#include<vector>
#include<queue>
#include<list>
using namespace std;

class Solution {
    private:
        void createAdjList(vector<vector<int>>& edges,unordered_map<int,list<int>>& adjList){
            for(int i=0;i<edges.size();i++){
                int u=edges[i][0];
                int v=edges[i][1];
                adjList[u].push_back(v);
                adjList[v].push_back(u);
            }
        }
        bool bfsTraversal(unordered_map<int,list<int>> &adjList,unordered_map<int,bool>& visited,int src,int des){
            // maintain initial state by pushing src into the queue
            queue<int> q;
            q.push(src);
            visited[src]=true;
            while(!q.empty()){
                int node=q.front();
                q.pop();
                if(node==des) return true;
                for(auto nbr:adjList[node]){
                    if(!visited[nbr]){
                        q.push(nbr);
                        visited[nbr]=true;
                    }
                }
            }
            return false;
        }
    public:
        bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
            unordered_map<int,list<int>> adjList;
            unordered_map<int,bool> visited;
            createAdjList(edges,adjList);
            bool ans = bfsTraversal(adjList,visited,source,destination);
            return ans;
        }
    };