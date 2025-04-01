#include<vector>
#include<list>
#include<queue>
#include<unordered_map>
using namespace std;

class Solution {
    private:
        void createAdjList(vector<vector<int>>& isConnected,unordered_map<int,list<int>>& adjList){
            int n=isConnected.size();
            int m=isConnected[0].size();
    
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(i!=j && isConnected[i][j]!=0){
                        adjList[i+1].push_back(j+1);
                    }
                }
            }
        }
        void dfsTraversal(int src,unordered_map<int,list<int>>& adjList,unordered_map<int,bool>& visited){
            // mark current code as visited 
            visited[src] = true;
            // process for the neighbour node
            for(auto nbr:adjList[src]){
                if(!visited[nbr]){
                    dfsTraversal(nbr,adjList,visited);
                }
            }
        }
    public:
        int findCircleNum(vector<vector<int>>& isConnected) {
            unordered_map<int,list<int>> adjList;
            createAdjList(isConnected,adjList);
            unordered_map<int,bool> visited;
            int n=isConnected.size();
            int count=0;
            for(int i=1;i<=n;i++){
                if(!visited[i]){
                    count++;
                    dfsTraversal(i,adjList,visited);
                }
            }
            return count;
        }
    };